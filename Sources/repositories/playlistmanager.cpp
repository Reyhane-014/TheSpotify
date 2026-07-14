#include "PlaylistManager.h"

PlaylistManager::PlaylistManager() : nextId(1) {}

int PlaylistManager::savePlaylist(const Playlist& playlist)
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getId() == playlist.getId()) {
            playlists[i] = playlist;
            return playlists[i].getId();
        }
    }

    Playlist newPlaylist(nextId, playlist.getName(), playlist.getListenerId(),
                         playlist.getIsFavorite());
    const std::vector<int>& songIds = playlist.getSongIds();
    for (int i = 0; i < (int)songIds.size(); i++) {
        newPlaylist.addSong(songIds[i]);
    }
    playlists.push_back(newPlaylist);
    return nextId++;
}

bool PlaylistManager::deletePlaylist(int id)
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getId() == id) {
            playlists.erase(playlists.begin() + i);
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

std::optional<Playlist> PlaylistManager::getFavoritePlaylist(int listenerId) const
{
    for (int i = 0; i < (int)playlists.size(); i++) {
        if (playlists[i].getListenerId() == listenerId && playlists[i].getIsFavorite()) {
            return playlists[i];
        }
    }
    return std::nullopt;
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