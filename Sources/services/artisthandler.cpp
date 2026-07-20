#include "artisthandler.h"
#include "../repositories/datamanager.h"
#include "../repositories/accountmanager.h"

ArtistHandler::ArtistHandler() {}

int ArtistHandler::addNewAlbum(int artistId, const std::string& name)
{
    if (name.empty()) {
        return -1;
    }

    auto artist = artistManager.getArtist(artistId);
    if (!artist.has_value()) {
        return -1;
    }

    Album newAlbum(0, name, artistId);
    int albumId = albumManager.addAlbum(newAlbum);

    Artist updatedArtist = artist.value();
    updatedArtist.addAlbum(albumId);
    artistManager.saveArtist(updatedArtist);

    saveAllData();
    reloadAllData();

    return albumId;
}

bool ArtistHandler::deleteAlbum(int albumId)
{
    auto album = albumManager.getAlbum(albumId);
    if (!album.has_value()) {
        return false;
    }

    std::vector<Song> songs = fetchSongsByAlbum(albumId);
    for (int i = 0; i < (int)songs.size(); i++) {
        songManager.deleteSong(songs[i].getId());
    }

    auto artist = artistManager.getArtist(album->getArtistId());
    if (artist.has_value()) {
        Artist updatedArtist = artist.value();
        updatedArtist.removeAlbum(albumId);
        artistManager.saveArtist(updatedArtist);
    }

    bool result = albumManager.removeAlbum(albumId);
    saveAllData();
    reloadAllData();
    return result;
}

std::vector<Album> ArtistHandler::fetchArtistAlbums(int artistId) const
{
    return albumManager.getAlbumsByArtist(artistId);
}

std::vector<Album> ArtistHandler::fetchAllAlbums() const
{
    return albumManager.getAllAlbums();
}

int ArtistHandler::addNewSong(int artistId, const std::string& title, const std::string& genre,
                              int releaseYear, int duration, int albumId, const std::string& filePath)
{
    if (title.empty()) {
        return -1;
    }

    auto artist = artistManager.getArtist(artistId);
    if (!artist.has_value()) {
        return -1;
    }

    if (albumId != 0) {
        auto album = albumManager.getAlbum(albumId);
        if (!album.has_value()) {
            return -1;
        }
        if (album->getArtistId() != artistId) {
            return -1;
        }
    }

    Song newSong(0, title, genre, releaseYear, duration, artistId, albumId, filePath);
    int songId = songManager.addSong(newSong);

    if (albumId != 0) {
        auto album = albumManager.getAlbum(albumId);
        if (album.has_value()) {
            Album updatedAlbum = album.value();
            updatedAlbum.addSong(songId);
            albumManager.addAlbum(updatedAlbum);
        }
    }

    saveAllData();
    reloadAllData();
    return songId;
}

bool ArtistHandler::updateSong(int songId, const std::string& title, const std::string& genre,
                               int releaseYear, int duration, int albumId, const std::string& filePath)
{
    if (title.empty()) {
        return false;
    }

    auto song = songManager.getSong(songId);
    if (!song.has_value()) {
        return false;
    }

    Song updatedSong = song.value();
    updatedSong.setTitle(title);
    updatedSong.setGenre(genre);
    updatedSong.setReleaseYear(releaseYear);
    updatedSong.setDuration(duration);

    if (!filePath.empty()) {
        updatedSong.setFilePath(filePath);
    }

    if (updatedSong.getAlbumId() != albumId) {
        if (updatedSong.getAlbumId() != 0) {
            auto oldAlbum = albumManager.getAlbum(updatedSong.getAlbumId());
            if (oldAlbum.has_value()) {
                Album updatedOldAlbum = oldAlbum.value();
                updatedOldAlbum.removeSong(songId);
                albumManager.addAlbum(updatedOldAlbum);
            }
        }

        if (albumId != 0) {
            auto newAlbum = albumManager.getAlbum(albumId);
            if (newAlbum.has_value()) {
                Album updatedNewAlbum = newAlbum.value();
                updatedNewAlbum.addSong(songId);
                albumManager.addAlbum(updatedNewAlbum);
            }
        }

        updatedSong.setAlbumId(albumId);
    }

    songManager.addSong(updatedSong);
    saveAllData();
    reloadAllData();
    return true;
}

bool ArtistHandler::deleteSong(int songId)
{
    auto song = songManager.getSong(songId);
    if (!song.has_value()) {
        return false;
    }

    if (song->getAlbumId() != 0) {
        auto album = albumManager.getAlbum(song->getAlbumId());
        if (album.has_value()) {
            Album updatedAlbum = album.value();
            updatedAlbum.removeSong(songId);
            albumManager.addAlbum(updatedAlbum);
        }
    }

    bool result = songManager.deleteSong(songId);
    saveAllData();
    reloadAllData();
    return result;
}

std::vector<Song> ArtistHandler::fetchArtistSongs(int artistId) const
{
    return songManager.getSongsByArtist(artistId);
}

std::vector<Song> ArtistHandler::fetchSongsByAlbum(int albumId) const
{
    return songManager.getSongsByAlbum(albumId);
}

std::shared_ptr<Song> ArtistHandler::fetchSong(int songId) const
{
    auto song = songManager.getSong(songId);
    if (song.has_value()) {
        Song songCopy = song.value();
        return std::make_shared<Song>(songCopy);
    }
    return nullptr;
}

std::vector<Song> ArtistHandler::fetchSingles(int artistId) const
{
    std::vector<Song> allSongs = songManager.getSongsByArtist(artistId);
    std::vector<Song> singles;
    for (int i = 0; i < (int)allSongs.size(); i++) {
        if (allSongs[i].getAlbumId() == 0) {
            singles.push_back(allSongs[i]);
        }
    }
    return singles;
}

std::shared_ptr<Artist> ArtistHandler::fetchArtist(int artistId) const
{
    auto artist = artistManager.getArtist(artistId);
    if (artist.has_value()) {
        Artist artistCopy = artist.value();
        return std::make_shared<Artist>(artistCopy);
    }
    return nullptr;
}

void ArtistHandler::saveAllData()
{
    DataManager* dm = DataManager::getInstance();
    AccountManager* am = AccountManager::getInstance();

    dm->saveAccounts(am->getAllAccounts());
    dm->saveArtists(artistManager.getAllArtists());
    dm->saveListeners(listenerManager.getAllListeners());
    dm->saveAlbums(albumManager.getAllAlbums());
    dm->savePlaylists(playlistManager.getAllPlaylists());
    dm->saveSongs(songManager.getAllSongs());
}

void ArtistHandler::reloadAllData()
{
    artistManager.reload();
    albumManager.reload();
    songManager.reload();
    listenerManager.reload();
    playlistManager.reload();
}