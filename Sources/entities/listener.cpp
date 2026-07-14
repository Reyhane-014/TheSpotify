#include "listener.h"
#include <algorithm>

Listener::Listener(int id, const std::string& username, const std::string& password,
                   const std::string& fullName, const std::string& bio)
    : Account(id, username, password, fullName, bio, Role::Listener) {}

void Listener::addPlaylist(int playlistId) {
    playlistIds.push_back(playlistId);
}

void Listener::removePlaylist(int playlistId) {
    auto it = std::find(playlistIds.begin(), playlistIds.end(), playlistId);
    if (it != playlistIds.end()) {
        playlistIds.erase(it);
    }
}

const std::vector<int>& Listener::getPlaylistIds() const {
    return playlistIds;
}

void Listener::likeSong(int songId) {
    if (!isSongLiked(songId)) {
        likedSongIds.push_back(songId);
    }
}

void Listener::unlikeSong(int songId) {
    auto it = std::find(likedSongIds.begin(), likedSongIds.end(), songId);
    if (it != likedSongIds.end()) {
        likedSongIds.erase(it);
    }
}

bool Listener::isSongLiked(int songId) const {
    return std::find(likedSongIds.begin(), likedSongIds.end(), songId) != likedSongIds.end();
}

const std::vector<int>& Listener::getLikedSongIds() const {
    return likedSongIds;
}

int Listener::getPlaylistCount() const {
    return static_cast<int>(playlistIds.size());
}

int Listener::getLikedCount() const {
    return static_cast<int>(likedSongIds.size());
}

void Listener::clearAllLikes() {
    likedSongIds.clear();
}