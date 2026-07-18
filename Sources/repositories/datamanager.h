#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>
#include "../entities/account.h"
#include "../entities/artist.h"
#include "../entities/listener.h"
#include "../entities/album.h"
#include "../entities/playlist.h"
#include "../entities/song.h"

class DataManager
{
private:
    static DataManager* instance;
    std::string dataFolder;

    DataManager();
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;

    std::string getAccountFilePath() const;
    std::string getArtistFilePath() const;
    std::string getListenerFilePath() const;
    std::string getAlbumFilePath() const;
    std::string getPlaylistFilePath() const;
    std::string getSongFilePath() const;
    std::string getNextIdFilePath() const;

    std::string accountToString(const Account& account);
    Account stringToAccount(const std::string& str);
    std::string artistToString(const Artist& artist);
    Artist stringToArtist(const std::string& str);
    std::string listenerToString(const Listener& listener);
    Listener stringToListener(const std::string& str);
    std::string albumToString(const Album& album);
    Album stringToAlbum(const std::string& str);
    std::string playlistToString(const Playlist& playlist);
    Playlist stringToPlaylist(const std::string& str);
    std::string songToString(const Song& song);
    Song stringToSong(const std::string& str);

public:
    static DataManager* getInstance();

    bool saveAccounts(const std::vector<Account>& accounts);
    std::vector<Account> loadAccounts();
    bool saveArtists(const std::vector<Artist>& artists);
    std::vector<Artist> loadArtists();
    bool saveListeners(const std::vector<Listener>& listeners);
    std::vector<Listener> loadListeners();
    bool saveAlbums(const std::vector<Album>& albums);
    std::vector<Album> loadAlbums();
    bool savePlaylists(const std::vector<Playlist>& playlists);
    std::vector<Playlist> loadPlaylists();
    bool saveSongs(const std::vector<Song>& songs);
    std::vector<Song> loadSongs();
    void saveNextIds(int accountId, int albumId, int playlistId, int songId);
    void loadNextIds(int& accountId, int& albumId, int& playlistId, int& songId);
    void ensureDataFolderExists();
};

#endif