#include "listener.h"
#include <algorithm>

Listener::Listener() : Account() {}

Listener::Listener(int id, const std::string& username, const std::string& password,
                   const std::string& fullName, const std::string& bio)
    : Account(id, username, password, fullName, bio, Role::Listener) {}

void Listener::addPlaylist(int playlistId)
{
    playlistIds.push_back(playlistId);
}

void Listener::removePlaylist(int playlistId)
{
    auto it = std::find(playlistIds.begin(), playlistIds.end(), playlistId);
    if (it != playlistIds.end()) {
        playlistIds.erase(it);
    }
}

const std::vector<int>& Listener::getPlaylistIds() const
{
    return playlistIds;
}

int Listener::getPlaylistCount() const
{
    return static_cast<int>(playlistIds.size());
}