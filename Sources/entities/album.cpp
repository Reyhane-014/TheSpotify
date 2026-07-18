#include "album.h"
#include <algorithm>

Album::Album() : id(0), artistId(0) {}

Album::Album(int id, const std::string& name, int artistId)
    : id(id), name(name), artistId(artistId) {}

int Album::getId() const { return id; }
std::string Album::getName() const { return name; }
int Album::getArtistId() const { return artistId; }
const std::vector<int>& Album::getSongIds() const { return songIds; }

void Album::setName(const std::string& newName) { name = newName; }

void Album::addSong(int songId)
{
    if (!hasSong(songId)) {
        songIds.push_back(songId);
    }
}

void Album::removeSong(int songId)
{
    auto it = std::find(songIds.begin(), songIds.end(), songId);
    if (it != songIds.end()) {
        songIds.erase(it);
    }
}

bool Album::hasSong(int songId) const
{
    return std::find(songIds.begin(), songIds.end(), songId) != songIds.end();
}

int Album::getSongCount() const
{
    return static_cast<int>(songIds.size());
}