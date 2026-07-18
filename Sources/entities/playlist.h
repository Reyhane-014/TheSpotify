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
    bool isFavorite;
    std::vector<int> songIds;

public:
    Playlist();
    Playlist(int id, const std::string& name, int listenerId, bool isFavorite);

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