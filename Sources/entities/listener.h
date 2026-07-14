#ifndef LISTENER_H
#define LISTENER_H

#include "account.h"
#include <vector>

class Listener : public Account
{
private:
    std::vector<int> playlistIds;
    std::vector<int> likedSongIds;

public:
    Listener(int id, const std::string& username, const std::string& password,
             const std::string& fullName, const std::string& bio);

    void addPlaylist(int playlistId);
    void removePlaylist(int playlistId);
    const std::vector<int>& getPlaylistIds() const;

    void likeSong(int songId);
    void unlikeSong(int songId);
    bool isSongLiked(int songId) const;
    const std::vector<int>& getLikedSongIds() const;

    int getPlaylistCount() const;
    int getLikedCount() const;
    void clearAllLikes();
};

#endif