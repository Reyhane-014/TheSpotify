#include "ArtistManager.h"

ArtistManager::ArtistManager() {}

int ArtistManager::saveArtist(const Artist& artist)
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getId() == artist.getId()) {
            artists[i] = artist;
            return artists[i].getId();
        }
    }
    artists.push_back(artist);
    return artist.getId();
}

bool ArtistManager::removeArtist(int id)
{
    for (int i = 0; i < (int)artists.size(); i++) {
        if (artists[i].getId() == id) {
            artists.erase(artists.begin() + i);
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