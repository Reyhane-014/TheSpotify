#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>

class Album
{
private:
    int id;
    std::string name;
    int artistId;
    std::vector<int> songIds;

public:
    Album(int id, const std::string& name, int artistId);

    int getId() const;
    std::string getName() const;
    int getArtistId() const;
    const std::vector<int>& getSongIds() const;

    void setName(const std::string& newName);

    void addSong(int songId);
    void removeSong(int songId);

    bool hasSong(int songId) const;
    int getSongCount() const;
};

#endif