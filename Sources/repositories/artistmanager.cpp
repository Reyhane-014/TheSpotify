#include "artistmanager.h"
#include "datamanager.h"

ArtistManager::ArtistManager() : nextId(1)
{
    loadFromFile();
}

void ArtistManager::reload()
{
    loadFromFile();
}

void ArtistManager::loadFromFile()
{
    DataManager* dm = DataManager::getInstance();
    artists = dm->loadArtists();
    nextId = 1;
    for (const auto& a : artists) {
        if (a.getId() >= nextId) {
            nextId = a.getId() + 1;
        }
    }
}

void ArtistManager::saveToFile()
{
    DataManager* dm = DataManager::getInstance();
    dm->saveArtists(artists);
}

int ArtistManager::saveArtist(const Artist& artist)
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getId() == artist.getId() && artist.getId() != 0) {
            artists[i] = artist;
            saveToFile();
            return artists[i].getId();
        }
    }

    int newId = artist.getId();
    if (newId == 0 || artistExists(newId)) {
        newId = nextId++;
    }

    Artist artistToSave(newId, artist.getUsername(), artist.getPassword(),
                        artist.getFullName(), artist.getBio());
    const std::vector<int>& albumIds = artist.getAlbumIds();
    for (int id : albumIds) {
        artistToSave.addAlbum(id);
    }

    artists.push_back(artistToSave);
    saveToFile();
    return artistToSave.getId();
}

bool ArtistManager::removeArtist(int id)
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getId() == id) {
            artists.erase(artists.begin() + i);
            saveToFile();
            return true;
        }
    }
    return false;
}

std::optional<Artist> ArtistManager::getArtist(int id) const
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getId() == id) {
            return artists[i];
        }
    }
    return std::nullopt;
}

std::optional<Artist> ArtistManager::getArtistByUsername(const std::string& username) const
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getUsername() == username) {
            return artists[i];
        }
    }
    return std::nullopt;
}

std::vector<Artist> ArtistManager::getAllArtists() const
{
    return artists;
}

bool ArtistManager::artistExists(int id) const
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getId() == id) {
            return true;
        }
    }
    return false;
}

int ArtistManager::getArtistCount() const
{
    return (int)artists.size();
}

int ArtistManager::getNextId() const
{
    return nextId;
}

void ArtistManager::setNextId(int id)
{
    nextId = id;
}