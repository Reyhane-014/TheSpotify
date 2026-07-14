#include "playlist.h"
#include <algorithm>

Playlist::Playlist(int id, const std::string& name, int listenerId, bool isFavorite)
    : id(id), name(name), listenerId(listenerId), isFavorite(isFavorite) {}

int Playlist::getId() const {
    return id;
}

std::string Playlist::getName() const {
    return name;
}

int Playlist::getListenerId() const {
    return listenerId;
}

const std::vector<int>& Playlist::getSongIds() const {
    return songIds;
}

bool Playlist::getIsFavorite() const {
    return isFavorite;
}

void Playlist::setName(const std::string& newName) {
    name = newName;
}

void Playlist::setIsFavorite(bool favorite) {
    isFavorite = favorite;
}

void Playlist::addSong(int songId) {
    if (!hasSong(songId)) {
        songIds.push_back(songId);
    }
}

void Playlist::removeSong(int songId) {
    auto it = std::find(songIds.begin(), songIds.end(), songId);
    if (it != songIds.end()) {
        songIds.erase(it);
    }
}

bool Playlist::hasSong(int songId) const {
    return std::find(songIds.begin(), songIds.end(), songId) != songIds.end();
}

int Playlist::getSongCount() const {
    return static_cast<int>(songIds.size());
}