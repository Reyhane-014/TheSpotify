#ifndef LISTENERHANDLER_H
#define LISTENERHANDLER_H

#include "../repositories/listenermanager.h"
#include "../repositories/playlistmanager.h"
#include "../repositories/songmanager.h"
#include "../repositories/artistmanager.h"
#include "../repositories/albummanager.h"
#include "../entities/listener.h"
#include "../entities/playlist.h"
#include "../entities/song.h"
#include "../entities/artist.h"
#include "../entities/album.h"
#include <vector>
#include <memory>

class ListenerHandler
{
private:
    ListenerManager listenerManager;
    PlaylistManager playlistManager;
    SongManager songManager;
    ArtistManager artistManager;
    AlbumManager albumManager;

public:
    ListenerHandler();

    int createNewPlaylist(int listenerId, const std::string& name);
    bool updatePlaylist(int playlistId, const std::string& newName);
    bool deletePlaylist(int playlistId);
    std::vector<Playlist> fetchListenerPlaylists(int listenerId) const;

    bool addSongToPlaylist(int playlistId, int songId);
    bool removeSongFromPlaylist(int playlistId, int songId);

    std::vector<Artist> fetchAllArtists() const;
    std::vector<Album> fetchArtistAlbums(int artistId) const;
    std::shared_ptr<Artist> fetchArtist(int artistId) const;

    std::vector<Song> fetchAllSongs() const;
    std::shared_ptr<Song> fetchSong(int songId) const;

    std::shared_ptr<Listener> fetchListener(int listenerId) const;
    std::shared_ptr<Playlist> getPlaylist(int playlistId) const;

    std::vector<Song> searchSongsByKeyword(const std::string& keyword) const;
    std::vector<Song> filterSongsByGenre(const std::string& genre) const;
    std::vector<Song> filterSongsByYear(int year) const;

    void saveAllData();
    void reloadAllData();
};

#endif