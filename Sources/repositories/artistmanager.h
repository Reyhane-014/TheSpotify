#ifndef ARTISTMANAGER_H
#define ARTISTMANAGER_H

#include "../entities/artist.h"
#include <vector>
#include <optional>

class ArtistManager
{
private:
    std::vector<Artist> artists;
    int nextId;

public:
    ArtistManager();

    int saveArtist(const Artist& artist);
    bool removeArtist(int id);
    std::optional<Artist> getArtist(int id) const;
    std::optional<Artist> getArtistByUsername(const std::string& username) const;
    std::vector<Artist> getAllArtists() const;
    bool artistExists(int id) const;
    int getArtistCount() const;
    void loadFromFile();
    void saveToFile();
    void reload();
    int getNextId() const;
    void setNextId(int id);
};

#endif