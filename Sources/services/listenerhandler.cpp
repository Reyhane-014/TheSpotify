#include "listenerhandler.h"

ListenerHandler::ListenerHandler() {}

int ListenerHandler::createNewPlaylist(int listenerId, const std::string& name)
{
    if (name.empty()) {
        return -1;
    }

    auto listener = listenerManager.fetchListener(listenerId);
    if (!listener.has_value()) {
        return -1;
    }

    Playlist newPlaylist(0, name, listenerId, false);
    int playlistId = playlistManager.savePlaylist(newPlaylist);

    Listener updatedListener = listener.value();
    updatedListener.addPlaylist(playlistId);
    listenerManager.storeListener(updatedListener);

    return playlistId;
}

bool ListenerHandler::updatePlaylist(int playlistId, const std::string& newName)
{
    if (newName.empty()) {
        return false;
    }

    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    if (playlist->getIsFavorite()) {
        return false;
    }

    Playlist updatedPlaylist = playlist.value();
    updatedPlaylist.setName(newName);
    playlistManager.savePlaylist(updatedPlaylist);
    return true;
}

bool ListenerHandler::deletePlaylist(int playlistId)
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    if (playlist->getIsFavorite()) {
        return false;
    }

    auto listener = listenerManager.fetchListener(playlist->getListenerId());
    if (listener.has_value()) {
        Listener updatedListener = listener.value();
        updatedListener.removePlaylist(playlistId);
        listenerManager.storeListener(updatedListener);
    }

    return playlistManager.deletePlaylist(playlistId);
}

std::vector<Playlist> ListenerHandler::fetchListenerPlaylists(int listenerId) const
{
    return playlistManager.getPlaylistsByListener(listenerId);
}

bool ListenerHandler::addSongToPlaylist(int playlistId, int songId)
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    auto song = songManager.getSong(songId);
    if (!song.has_value()) {
        return false;
    }

    Playlist updatedPlaylist = playlist.value();
    updatedPlaylist.addSong(songId);
    playlistManager.savePlaylist(updatedPlaylist);
    return true;
}

bool ListenerHandler::removeSongFromPlaylist(int playlistId, int songId)
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (!playlist.has_value()) {
        return false;
    }

    if (playlist->getIsFavorite()) {
        return false;
    }

    Playlist updatedPlaylist = playlist.value();
    updatedPlaylist.removeSong(songId);
    playlistManager.savePlaylist(updatedPlaylist);
    return true;
}

bool ListenerHandler::likeSong(int listenerId, int songId)
{
    auto listener = listenerManager.fetchListener(listenerId);
    if (!listener.has_value()) {
        return false;
    }

    auto song = songManager.getSong(songId);
    if (!song.has_value()) {
        return false;
    }

    Listener updatedListener = listener.value();
    updatedListener.likeSong(songId);
    listenerManager.storeListener(updatedListener);

    auto favoritePlaylist = playlistManager.getFavoritePlaylist(listenerId);
    if (favoritePlaylist.has_value()) {
        Playlist updatedFavorite = favoritePlaylist.value();
        updatedFavorite.addSong(songId);
        playlistManager.savePlaylist(updatedFavorite);
    }

    listenerManager.updateLikedSongs(listenerId, songId, true);
    return true;
}

bool ListenerHandler::unlikeSong(int listenerId, int songId)
{
    auto listener = listenerManager.fetchListener(listenerId);
    if (!listener.has_value()) {
        return false;
    }

    Listener updatedListener = listener.value();
    updatedListener.unlikeSong(songId);
    listenerManager.storeListener(updatedListener);

    auto favoritePlaylist = playlistManager.getFavoritePlaylist(listenerId);
    if (favoritePlaylist.has_value()) {
        Playlist updatedFavorite = favoritePlaylist.value();
        updatedFavorite.removeSong(songId);
        playlistManager.savePlaylist(updatedFavorite);
    }

    listenerManager.updateLikedSongs(listenerId, songId, false);
    return true;
}

bool ListenerHandler::isSongLiked(int listenerId, int songId) const
{
    return listenerManager.isSongLikedByListener(listenerId, songId);
}

std::vector<Song> ListenerHandler::fetchLikedSongs(int listenerId) const
{
    auto listener = listenerManager.fetchListener(listenerId);
    if (!listener.has_value()) {
        return std::vector<Song>();
    }

    std::vector<Song> likedSongs;
    std::vector<int> likedIds = listener.value().getLikedSongIds();
    for (int i = 0; i < (int)likedIds.size(); i++) {
        auto song = songManager.getSong(likedIds[i]);
        if (song.has_value()) {
            likedSongs.push_back(song.value());
        }
    }
    return likedSongs;
}

std::vector<Artist> ListenerHandler::fetchAllArtists() const
{
    return artistManager.getAllArtists();
}

std::vector<Album> ListenerHandler::fetchArtistAlbums(int artistId) const
{
    return albumManager.getAlbumsByArtist(artistId);
}

std::shared_ptr<Artist> ListenerHandler::fetchArtist(int artistId) const
{
    auto artist = artistManager.getArtist(artistId);
    if (artist.has_value()) {
        Artist artistCopy = artist.value();
        return std::make_shared<Artist>(artistCopy);
    }
    return nullptr;
}

std::vector<Song> ListenerHandler::fetchAllSongs() const
{
    return songManager.getAllSongs();
}

std::shared_ptr<Song> ListenerHandler::fetchSong(int songId) const
{
    auto song = songManager.getSong(songId);
    if (song.has_value()) {
        Song songCopy = song.value();
        return std::make_shared<Song>(songCopy);
    }
    return nullptr;
}

std::shared_ptr<Listener> ListenerHandler::fetchListener(int listenerId) const
{
    auto listener = listenerManager.fetchListener(listenerId);
    if (listener.has_value()) {
        Listener listenerCopy = listener.value();
        return std::make_shared<Listener>(listenerCopy);
    }
    return nullptr;
}

std::shared_ptr<Playlist> ListenerHandler::getPlaylist(int playlistId) const
{
    auto playlist = playlistManager.findPlaylist(playlistId);
    if (playlist.has_value()) {
        return std::make_shared<Playlist>(playlist.value());
    }
    return nullptr;
}

std::vector<Song> ListenerHandler::searchSongsByKeyword(const std::string& keyword) const
{
    return songManager.searchSongsByTitle(keyword);
}

std::vector<Song> ListenerHandler::filterSongsByGenre(const std::string& genre) const
{
    return songManager.filterSongsByGenre(genre);
}

std::vector<Song> ListenerHandler::filterSongsByYear(int year) const
{
    return songManager.filterSongsByYear(year);
}