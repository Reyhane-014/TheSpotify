#include "songmanager.h"
#include "datamanager.h"

SongManager::SongManager() : nextId(1)
{
    loadFromFile();
}

void SongManager::reload()
{
    loadFromFile();
}

void SongManager::loadFromFile()
{
    DataManager* dm = DataManager::getInstance();
    songs = dm->loadSongs();
    int accountId, albumId, playlistId;
    dm->loadNextIds(accountId, albumId, playlistId, nextId);

    for (const auto& song : songs) {
        if (song.getId() >= nextId) {
            nextId = song.getId() + 1;
        }
    }
}

void SongManager::saveToFile()
{
    DataManager* dm = DataManager::getInstance();
    dm->saveSongs(songs);
}

int SongManager::addSong(const Song& song)
{
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getId() == song.getId() && song.getId() != 0) {
            songs[i] = song;
            saveToFile();
            return songs[i].getId();
        }
    }

    int newId = nextId++;
    Song newSong(newId, song.getTitle(), song.getGenre(),
                 song.getReleaseYear(), song.getDuration(),
                 song.getArtistId(), song.getAlbumId(), song.getFilePath());
    songs.push_back(newSong);
    saveToFile();
    return newSong.getId();
}

bool SongManager::deleteSong(int id)
{
    for (int i = 0; i < (int)songs.size(); i++) {
        if (songs[i].getId() == id) {
            songs.erase(songs.begin() + i);
            saveToFile();
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