#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>

class Playlist
{
private:
    int id;
    std::string name;
    int listenerId;
    std::vector<int> songIds;
    bool isFavorite;

public:
    Playlist(int id, const std::string& name, int listenerId, bool isFavorite = false);

    int getId() const;
    std::string getName() const;
    int getListenerId() const;
    const std::vector<int>& getSongIds() const;
    bool getIsFavorite() const;

    void setName(const std::string& newName);
    void setIsFavorite(bool favorite);

    void addSong(int songId);
    void removeSong(int songId);
    bool hasSong(int songId) const;
    int getSongCount() const;
};

#endif