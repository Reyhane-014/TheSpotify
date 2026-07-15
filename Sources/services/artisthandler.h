#ifndef ARTISTHANDLER_H
#define ARTISTHANDLER_H

#include "../repositories/ArtistManager.h"
#include "../repositories/AlbumManager.h"
#include "../repositories/SongManager.h"
#include "../entities/artist.h"
#include "../entities/album.h"
#include "../entities/song.h"
#include <vector>
#include <memory>

class ArtistHandler
{
private:
    ArtistManager artistManager;
    AlbumManager albumManager;
    SongManager songManager;

public:
    ArtistHandler();

    int addNewAlbum(int artistId, const std::string& name);
    bool deleteAlbum(int albumId);
    std::vector<Album> fetchArtistAlbums(int artistId) const;
    std::vector<Album> fetchAllAlbums() const;

    int addNewSong(int artistId, const std::string& title, const std::string& genre,
                   int releaseYear, int duration, int albumId = 0, const std::string& filePath = "");
    bool updateSong(int songId, const std::string& title, const std::string& genre,
                    int releaseYear, int duration, int albumId);
    bool deleteSong(int songId);
    std::vector<Song> fetchArtistSongs(int artistId) const;
    std::vector<Song> fetchSongsByAlbum(int albumId) const;

    std::vector<Song> fetchSingles(int artistId) const;
    std::shared_ptr<Artist> fetchArtist(int artistId) const;
};

#endif