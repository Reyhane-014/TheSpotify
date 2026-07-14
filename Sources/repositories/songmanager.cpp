#include "SongManager.h"

SongManager::SongManager() : nextId(1) {}

int SongManager::addSong(const Song& song)
{
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getId() == song.getId()) {
            songs[i] = song;
            return songs[i].getId();
        }
    }

    Song newSong(nextId, song.getTitle(), song.getGenre(),
                 song.getReleaseYear(), song.getDuration(),
                 song.getArtistId(), song.getAlbumId(), song.getFilePath());
    songs.push_back(newSong);
    return nextId++;
}

bool SongManager::deleteSong(int id)
{
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getId() == id) {
            songs.erase(songs.begin() + i);
            return true;
        }
    }
    return false;
}

std::optional<Song> SongManager::getSong(int id) const
{
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getId() == id) {
            return songs[i];
        }
    }
    return std::nullopt;
}

std::vector<Song> SongManager::getAllSongs() const
{
    return songs;
}

std::vector<Song> SongManager::getSongsByArtist(int artistId) const
{
    std::vector<Song> result;
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getArtistId() == artistId) {
            result.push_back(songs[i]);
        }
    }
    return result;
}

std::vector<Song> SongManager::getSongsByAlbum(int albumId) const
{
    std::vector<Song> result;
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getAlbumId() == albumId) {
            result.push_back(songs[i]);
        }
    }
    return result;
}

std::vector<Song> SongManager::searchSongsByTitle(const std::string& title) const
{
    std::vector<Song> result;
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getTitle().find(title) != std::string::npos) {
            result.push_back(songs[i]);
        }
    }
    return result;
}

std::vector<Song> SongManager::filterSongsByGenre(const std::string& genre) const
{
    std::vector<Song> result;
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getGenre() == genre) {
            result.push_back(songs[i]);
        }
    }
    return result;
}

std::vector<Song> SongManager::filterSongsByYear(int year) const
{
    std::vector<Song> result;
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getReleaseYear() == year) {
            result.push_back(songs[i]);
        }
    }
    return result;
}

bool SongManager::songExists(int id) const
{
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getId() == id) {
            return true;
        }
    }
    return false;
}