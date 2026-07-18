#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include "../entities/playlist.h"
#include <vector>
#include <optional>

class PlaylistManager
{
private:
    std::vector<Playlist> playlists;
    int nextId;

public:
    PlaylistManager();

    int savePlaylist(const Playlist& playlist);
    bool deletePlaylist(int id);
    std::optional<Playlist> findPlaylist(int id) const;
    std::vector<Playlist> getAllPlaylists() const;
    std::vector<Playlist> getPlaylistsByListener(int listenerId) const;
    bool playlistExists(int id) const;
    void loadFromFile();
    void saveToFile();
    void reload();
    int getNextId() const { return nextId; }
    void setNextId(int id) { nextId = id; }
};

#endif