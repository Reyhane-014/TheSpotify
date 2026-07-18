#include "listenerhandler.h"
#include "../repositories/datamanager.h"
#include "../repositories/accountmanager.h"

ListenerHandler::ListenerHandler() {}

int ListenerHandler::createNewPlaylist(int listenerId, const std::string& name)
{
    if (name.empty()) {
        return -1;
    }

    auto listener = listenerManager.fetchListener(listenerId);
    if (!listener.has_value()) {
        return -1;
    }

    Playlist newPlaylist(0, name, listenerId, false);
    int playlistId = playlistManager.savePlaylist(newPlaylist);

    Listener updatedListener = listener.value();
    updatedListener.addPlaylist(playlistId);
    listenerManager.storeListener(updatedListener);

    saveAllData();

    return playlistId;
}

bool ListenerHandler::updatePlaylist(int playlistId, const std::string& newName)
{
    if (newName.empty()) {
        return false;
    }

    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    Playlist updatedPlaylist = playlist.value();
    updatedPlaylist.setName(newName);
    playlistManager.savePlaylist(updatedPlaylist);
    saveAllData();
    return true;
}

bool ListenerHandler::deletePlaylist(int playlistId)
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    auto listener = listenerManager.fetchListener(playlist->getListenerId());
    if (listener.has_value()) {
        Listener updatedListener = listener.value();
        updatedListener.removePlaylist(playlistId);
        listenerManager.storeListener(updatedListener);
    }

    bool result = playlistManager.deletePlaylist(playlistId);
    saveAllData();
    return result;
}

std::vector<Playlist> ListenerHandler::fetchListenerPlaylists(int listenerId) const
{
    return playlistManager.getPlaylistsByListener(listenerId);
}

bool ListenerHandler::addSongToPlaylist(int playlistId, int songId)
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    auto song = songManager.getSong(songId);
    if (!song.has_value()) {
        return false;
    }

    Playlist updatedPlaylist = playlist.value();
    updatedPlaylist.addSong(songId);
    playlistManager.savePlaylist(updatedPlaylist);
    saveAllData();
    return true;
}

bool ListenerHandler::removeSongFromPlaylist(int playlistId, int songId)
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    Playlist updatedPlaylist = playlist.value();
    updatedPlaylist.removeSong(songId);
    playlistManager.savePlaylist(updatedPlaylist);
    saveAllData();
    return true;
}

std::vector<Artist> ListenerHandler::fetchAllArtists() const
{
    return artistManager.getAllArtists();
}

std::vector<Album> ListenerHandler::fetchArtistAlbums(int artistId) const
{
    return albumManager.getAlbumsByArtist(artistId);
}

std::shared_ptr<Artist> ListenerHandler::fetchArtist(int artistId) const
{
    auto artist = artistManager.getArtist(artistId);
    if (artist.has_value()) {
        Artist artistCopy = artist.value();
        return std::make_shared<Artist>(artistCopy);
    }
    return nullptr;
}

std::vector<Song> ListenerHandler::fetchAllSongs() const
{
    return songManager.getAllSongs();
}

std::shared_ptr<Song> ListenerHandler::fetchSong(int songId) const
{
    auto song = songManager.getSong(songId);
    if (song.has_value()) {
        Song songCopy = song.value();
        return std::make_shared<Song>(songCopy);
    }
    return nullptr;
}

std::shared_ptr<Listener> ListenerHandler::fetchListener(int listenerId) const
{
    auto listener = listenerManager.fetchListener(listenerId);
    if (listener.has_value()) {
        Listener listenerCopy = listener.value();
        return std::make_shared<Listener>(listenerCopy);
    }
    return nullptr;
}

std::shared_ptr<Playlist> ListenerHandler::getPlaylist(int playlistId) const
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (playlist.has_value()) {
        return std::make_shared<Playlist>(playlist.value());
    }
    return nullptr;
}

std::vector<Song> ListenerHandler::searchSongsByKeyword(const std::string& keyword) const
{
    return songManager.searchSongsByTitle(keyword);
}

std::vector<Song> ListenerHandler::filterSongsByGenre(const std::string& genre) const
{
    return songManager.filterSongsByGenre(genre);
}

std::vector<Song> ListenerHandler::filterSongsByYear(int year) const
{
    return songManager.filterSongsByYear(year);
}

void ListenerHandler::saveAllData()
{
    DataManager* dm = DataManager::getInstance();
    AccountManager* am = AccountManager::getInstance();

    dm->saveAccounts(am->getAllAccounts());
    dm->saveArtists(artistManager.getAllArtists());
    dm->saveListeners(listenerManager.getAllListeners());
    dm->saveAlbums(albumManager.getAllAlbums());
    dm->savePlaylists(playlistManager.getAllPlaylists());
    dm->saveSongs(songManager.getAllSongs());

    dm->saveNextIds(am->getNextId(),
                    albumManager.getNextId(),
                    playlistManager.getNextId(),
                    songManager.getNextId());
}

void ListenerHandler::reloadAllData()
{
    listenerManager.reload();
    playlistManager.reload();
    songManager.reload();
    artistManager.reload();
    albumManager.reload();
}