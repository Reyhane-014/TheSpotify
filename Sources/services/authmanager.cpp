#include "authmanager.h"
#include "../repositories/datamanager.h"
#include <iostream>

AuthManager::AuthManager()
{
    accountManager = AccountManager::getInstance();
}

bool AuthManager::registerUser(const std::string& username, const std::string& password,
                               const std::string& fullName, const std::string& bio,
                               const std::string& role)
{
    if (checkUsernameExists(username)) {
        return false;
    }

    if (username.empty() || password.empty() || fullName.empty()) {
        return false;
    }

    if (role != "Artist" && role != "Listener" &&
        role != "artist" && role != "listener") {
        return false;
    }

    Role userRole = (role == "Artist" || role == "artist") ? Role::Artist : Role::Listener;

    Account newAccount(0, username, password, fullName, bio, userRole);
    int accountId = accountManager->storeAccount(newAccount);

    if (userRole == Role::Artist) {
        Artist newArtist(accountId, username, password, fullName, bio);
        artistManager.saveArtist(newArtist);
    } else {
        Listener newListener(accountId, username, password, fullName, bio);
        listenerManager.storeListener(newListener);
    }

    saveAllData();
    return true;
}

std::shared_ptr<Account> AuthManager::loginUser(const std::string& username, const std::string& password)
{
    auto account = accountManager->findAccountByUsername(username);

    if (!account.has_value()) {
        return nullptr;
    }

    if (account.value().getPassword() != password) {
        return nullptr;
    }

    return std::make_shared<Account>(account.value());
}

bool AuthManager::checkUsernameExists(const std::string& username) const
{
    return accountManager->isUsernameUsed(username);
}

bool AuthManager::updateAccount(int accountId, const std::string& username, const std::string& password,
                                const std::string& fullName, const std::string& bio)
{
    auto accountOpt = accountManager->findAccount(accountId);
    if (!accountOpt.has_value()) {
        return false;
    }

    if (username.empty() || password.empty() || fullName.empty()) {
        return false;
    }

    Account currentAccount = accountOpt.value();

    if (currentAccount.getUsername() != username) {
        if (accountManager->isUsernameUsed(username)) {
            return false;
        }
    }

    Account updatedAccount(accountId, username, password, fullName, bio, currentAccount.getRole());
    accountManager->storeAccount(updatedAccount);

    Role role = currentAccount.getRole();
    if (role == Role::Artist) {
        auto artistOpt = artistManager.getArtist(accountId);
        if (artistOpt.has_value()) {
            Artist updatedArtist(accountId, username, password, fullName, bio);
            const std::vector<int>& albumIds = artistOpt.value().getAlbumIds();
            for (int id : albumIds) {
                updatedArtist.addAlbum(id);
            }
            artistManager.saveArtist(updatedArtist);
        }
    } else {
        auto listenerOpt = listenerManager.fetchListener(accountId);
        if (listenerOpt.has_value()) {
            Listener updatedListener(accountId, username, password, fullName, bio);
            const std::vector<int>& playlistIds = listenerOpt.value().getPlaylistIds();
            for (int id : playlistIds) {
                updatedListener.addPlaylist(id);
            }
            listenerManager.storeListener(updatedListener);
        }
    }

    saveAllData();
    return true;
}

bool AuthManager::deleteAccount(int accountId)
{
    auto accountOpt = accountManager->findAccount(accountId);
    if (!accountOpt.has_value()) {
        return false;
    }

    Role role = accountOpt.value().getRole();

    if (role == Role::Artist) {
        artistManager.removeArtist(accountId);
        auto albums = albumManager.getAlbumsByArtist(accountId);
        for (const Album& album : albums) {
            auto songs = songManager.getSongsByAlbum(album.getId());
            for (const Song& song : songs) {
                songManager.deleteSong(song.getId());
            }
            albumManager.removeAlbum(album.getId());
        }
    } else {
        auto listenerOpt = listenerManager.fetchListener(accountId);
        if (listenerOpt.has_value()) {
            std::vector<int> playlistIds = listenerOpt.value().getPlaylistIds();
            for (int id : playlistIds) {
                playlistManager.deletePlaylist(id);
            }
        }
        listenerManager.deleteListener(accountId);
    }

    accountManager->deleteAccount(accountId);
    saveAllData();
    return true;
}

void AuthManager::saveAllData()
{
    DataManager* dm = DataManager::getInstance();

    dm->saveAccounts(accountManager->getAllAccounts());
    dm->saveArtists(artistManager.getAllArtists());
    dm->saveListeners(listenerManager.getAllListeners());
    dm->saveAlbums(albumManager.getAllAlbums());
    dm->savePlaylists(playlistManager.getAllPlaylists());
    dm->saveSongs(songManager.getAllSongs());

    dm->saveNextIds(accountManager->getNextId(),
                    albumManager.getNextId(),
                    playlistManager.getNextId(),
                    songManager.getNextId());
}