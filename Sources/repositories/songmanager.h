#ifndef SONGMANAGER_H
#define SONGMANAGER_H

#include "../entities/song.h"
#include <vector>
#include <optional>

class SongManager
{
private:
    std::vector<Song> songs;
    int nextId;

public:
    SongManager();

    int addSong(const Song& song);
    bool deleteSong(int id);
    std::optional<Song> getSong(int id) const;
    std::vector<Song> getAllSongs() const;
    std::vector<Song> getSongsByArtist(int artistId) const;
    std::vector<Song> getSongsByAlbum(int albumId) const;
    std::vector<Song> searchSongsByTitle(const std::string& title) const;
    std::vector<Song> filterSongsByGenre(const std::string& genre) const;
    std::vector<Song> filterSongsByYear(int year) const;
    bool songExists(int id) const;
};

#endif