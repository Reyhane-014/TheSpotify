#ifndef LISTENER_H
#define LISTENER_H

#include "account.h"
#include <vector>

class Listener : public Account
{
private:
    std::vector<int> playlistIds;

public:
    Listener();
    Listener(int id, const std::string& username, const std::string& password,
             const std::string& fullName, const std::string& bio);

    void addPlaylist(int playlistId);
    void removePlaylist(int playlistId);
    const std::vector<int>& getPlaylistIds() const;

    int getPlaylistCount() const;
};

#endif