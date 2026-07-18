#ifndef ALBUMMANAGER_H
#define ALBUMMANAGER_H

#include "../entities/album.h"
#include <vector>
#include <optional>

class AlbumManager
{
private:
    std::vector<Album> albums;
    int nextId;

public:
    AlbumManager();

    int addAlbum(const Album& album);
    bool removeAlbum(int id);
    std::optional<Album> getAlbum(int id) const;
    std::vector<Album> getAllAlbums() const;
    std::vector<Album> getAlbumsByArtist(int artistId) const;
    bool albumBelongsToArtist(int albumId, int artistId) const;
    void loadFromFile();
    void saveToFile();
    void reload();
    int getNextId() const { return nextId; }
    void setNextId(int id) { nextId = id; }
};

#endif