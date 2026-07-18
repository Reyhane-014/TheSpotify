#include "playlistmanager.h"
#include "datamanager.h"

PlaylistManager::PlaylistManager() : nextId(1)
{
    loadFromFile();
}

void PlaylistManager::reload()
{
    loadFromFile();
}

void PlaylistManager::loadFromFile()
{
    DataManager* dm = DataManager::getInstance();
    playlists = dm->loadPlaylists();
    int accountId, albumId, songId;
    dm->loadNextIds(accountId, albumId, nextId, songId);

    for (const auto& playlist : playlists) {
        if (playlist.getId() >= nextId) {
            nextId = playlist.getId() + 1;
        }
    }
}

void PlaylistManager::saveToFile()
{
    DataManager* dm = DataManager::getInstance();
    dm->savePlaylists(playlists);
}

int PlaylistManager::savePlaylist(const Playlist& playlist)
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getId() == playlist.getId() && playlist.getId() != 0) {
            playlists[i] = playlist;
            saveToFile();
            return playlists[i].getId();
        }
    }

    int newId = nextId++;
    Playlist newPlaylist(newId, playlist.getName(), playlist.getListenerId(),
                         playlist.getIsFavorite());
    const std::vector<int>& songIds = playlist.getSongIds();
    for (int i = 0; i < (int)songIds.size(); i++) {
        newPlaylist.addSong(songIds[i]);
    }
    playlists.push_back(newPlaylist);
    saveToFile();
    return newPlaylist.getId();
}

bool PlaylistManager::deletePlaylist(int id)
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getId() == id) {
            playlists.erase(playlists.begin() + i);
            saveToFile();
            return true;
        }
    }
    return false;
}

std::optional<Playlist> PlaylistManager::findPlaylist(int id) const
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getId() == id) {
            return playlists[i];
        }
    }
    return std::nullopt;
}

std::vector<Playlist> PlaylistManager::getAllPlaylists() const
{
    return playlists;
}

std::vector<Playlist> PlaylistManager::getPlaylistsByListener(int listenerId) const
{
    std::vector<Playlist> result;
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getListenerId() == listenerId) {
            result.push_back(playlists[i]);
        }
    }
    return result;
}

bool PlaylistManager::playlistExists(int id) const
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getId() == id) {
            return true;
        }
    }
    return false;
}