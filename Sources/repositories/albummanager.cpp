#include "albummanager.h"
#include "datamanager.h"

AlbumManager::AlbumManager() : nextId(1)
{
    loadFromFile();
}

void AlbumManager::reload()
{
    loadFromFile();
}

void AlbumManager::loadFromFile()
{
    DataManager* dm = DataManager::getInstance();
    albums = dm->loadAlbums();
    int accountId, playlistId, songId;
    dm->loadNextIds(accountId, nextId, playlistId, songId);

    for (const auto& album : albums) {
        if (album.getId() >= nextId) {
            nextId = album.getId() + 1;
        }
    }
}

void AlbumManager::saveToFile()
{
    DataManager* dm = DataManager::getInstance();
    dm->saveAlbums(albums);
}

int AlbumManager::addAlbum(const Album& album)
{
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getId() == album.getId() && album.getId() != 0) {
            albums[i] = album;
            saveToFile();
            return albums[i].getId();
        }
    }

    int newId = nextId++;
    Album newAlbum(newId, album.getName(), album.getArtistId());
    const std::vector<int>& songIds = album.getSongIds();
    for (int i = 0; i < (int)songIds.size(); i++) {
        newAlbum.addSong(songIds[i]);
    }
    albums.push_back(newAlbum);
    saveToFile();
    return newAlbum.getId();
}

bool AlbumManager::removeAlbum(int id)
{
    for (int i = 0; i < (int)albums.size(); i++) {
        if (albums[i].getId() == id) {
            albums.erase(albums.begin() + i);
            saveToFile();
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