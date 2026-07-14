#include "AlbumManager.h"

AlbumManager::AlbumManager() : nextId(1) {}

int AlbumManager::addAlbum(const Album& album)
{
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getId() == album.getId()) {
            albums[i] = album;
            return albums[i].getId();
        }
    }

    Album newAlbum(nextId, album.getName(), album.getArtistId());
    const std::vector<int>& songIds = album.getSongIds();
    for (int i = 0; i < (int)songIds.size(); i++) {
        newAlbum.addSong(songIds[i]);
    }
    albums.push_back(newAlbum);
    return nextId++;
}

bool AlbumManager::removeAlbum(int id)
{
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getId() == id) {
            albums.erase(albums.begin() + i);
            return true;
        }
    }
    return false;
}

std::optional<Album> AlbumManager::getAlbum(int id) const
{
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getId() == id) {
            return albums[i];
        }
    }
    return std::nullopt;
}

std::vector<Album> AlbumManager::getAllAlbums() const
{
    return albums;
}

std::vector<Album> AlbumManager::getAlbumsByArtist(int artistId) const
{
    std::vector<Album> result;
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getArtistId() == artistId) {
            result.push_back(albums[i]);
        }
    }
    return result;
}

bool AlbumManager::albumBelongsToArtist(int albumId, int artistId) const
{
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getId() == albumId && albums[i].getArtistId() == artistId) {
            return true;
        }
    }
    return false;
}