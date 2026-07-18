#include "datamanager.h"
#include "../utils/filehelper.h"
#include <iostream>

#ifdef _WIN32
#include <direct.h>
#define MKDIR(dir) _mkdir(dir)
#else
#include <sys/stat.h>
#define MKDIR(dir) mkdir(dir, 0777)
#endif

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
    dataFolder = "spotify_data";
    ensureDataFolderExists();
}

DataManager* DataManager::getInstance()
{
    if (instance == nullptr) {
        instance = new DataManager();
    }
    return instance;
}

void DataManager::ensureDataFolderExists()
{
    MKDIR(dataFolder.c_str());
}

std::string DataManager::getAccountFilePath() const
{
    return dataFolder + "/accounts.txt";
}

std::string DataManager::getArtistFilePath() const
{
    return dataFolder + "/artists.txt";
}

std::string DataManager::getListenerFilePath() const
{
    return dataFolder + "/listeners.txt";
}

std::string DataManager::getAlbumFilePath() const
{
    return dataFolder + "/albums.txt";
}

std::string DataManager::getPlaylistFilePath() const
{
    return dataFolder + "/playlists.txt";
}

std::string DataManager::getSongFilePath() const
{
    return dataFolder + "/songs.txt";
}

std::string DataManager::getNextIdFilePath() const
{
    return dataFolder + "/nextids.txt";
}

std::string DataManager::accountToString(const Account& account)
{
    std::vector<std::string> parts;
    parts.push_back(std::to_string(account.getId()));
    parts.push_back(FileHelper::encodeSpecialChars(account.getUsername()));
    parts.push_back(FileHelper::encodeSpecialChars(account.getPassword()));
    parts.push_back(FileHelper::encodeSpecialChars(account.getFullName()));
    parts.push_back(FileHelper::encodeSpecialChars(account.getBio()));
    parts.push_back(std::to_string(static_cast<int>(account.getRole())));
    return FileHelper::joinString(parts, '|');
}

Account DataManager::stringToAccount(const std::string& str)
{
    std::vector<std::string> parts = FileHelper::splitString(str, '|');
    if (parts.size() < 6) {
        return Account(0, "", "", "", "", Role::Listener);
    }
    int id = std::stoi(parts[0]);
    std::string username = FileHelper::decodeSpecialChars(parts[1]);
    std::string password = FileHelper::decodeSpecialChars(parts[2]);
    std::string fullName = FileHelper::decodeSpecialChars(parts[3]);
    std::string bio = FileHelper::decodeSpecialChars(parts[4]);
    Role role = static_cast<Role>(std::stoi(parts[5]));
    return Account(id, username, password, fullName, bio, role);
}

std::string DataManager::artistToString(const Artist& artist)
{
    std::vector<std::string> parts;
    parts.push_back(std::to_string(artist.getId()));
    parts.push_back(FileHelper::encodeSpecialChars(artist.getUsername()));
    parts.push_back(FileHelper::encodeSpecialChars(artist.getPassword()));
    parts.push_back(FileHelper::encodeSpecialChars(artist.getFullName()));
    parts.push_back(FileHelper::encodeSpecialChars(artist.getBio()));
    parts.push_back(std::to_string(static_cast<int>(artist.getRole())));

    std::string albumIdsStr;
    const std::vector<int>& albumIds = artist.getAlbumIds();
    for (size_t i = 0; i < albumIds.size(); ++i) {
        if (i > 0) albumIdsStr += ",";
        albumIdsStr += std::to_string(albumIds[i]);
    }
    parts.push_back(albumIdsStr);

    return FileHelper::joinString(parts, '|');
}

Artist DataManager::stringToArtist(const std::string& str)
{
    if (str.empty()) {
        return Artist(0, "", "", "", "");
    }

    std::vector<std::string> parts = FileHelper::splitString(str, '|');
    if (parts.size() < 6) {
        return Artist(0, "", "", "", "");
    }

    int id = std::stoi(parts[0]);
    std::string username = (parts.size() > 1) ? FileHelper::decodeSpecialChars(parts[1]) : "";
    std::string password = (parts.size() > 2) ? FileHelper::decodeSpecialChars(parts[2]) : "";
    std::string fullName = (parts.size() > 3) ? FileHelper::decodeSpecialChars(parts[3]) : "";
    std::string bio = (parts.size() > 4) ? FileHelper::decodeSpecialChars(parts[4]) : "";

    Artist artist(id, username, password, fullName, bio);

    if (parts.size() > 6 && !parts[6].empty()) {
        std::vector<std::string> ids = FileHelper::splitString(parts[6], ',');
        for (const std::string& idStr : ids) {
            if (!idStr.empty()) {
                artist.addAlbum(std::stoi(idStr));
            }
        }
    }
    return artist;
}

std::string DataManager::listenerToString(const Listener& listener)
{
    std::vector<std::string> parts;
    parts.push_back(std::to_string(listener.getId()));
    parts.push_back(FileHelper::encodeSpecialChars(listener.getUsername()));
    parts.push_back(FileHelper::encodeSpecialChars(listener.getPassword()));
    parts.push_back(FileHelper::encodeSpecialChars(listener.getFullName()));
    parts.push_back(FileHelper::encodeSpecialChars(listener.getBio()));
    parts.push_back(std::to_string(static_cast<int>(listener.getRole())));
    std::string playlistIdsStr;
    const std::vector<int>& playlistIds = listener.getPlaylistIds();
    for (size_t i = 0; i < playlistIds.size(); ++i) {
        if (i > 0) playlistIdsStr += ",";
        playlistIdsStr += std::to_string(playlistIds[i]);
    }
    parts.push_back(playlistIdsStr);
    return FileHelper::joinString(parts, '|');
}

Listener DataManager::stringToListener(const std::string& str)
{
    std::vector<std::string> parts = FileHelper::splitString(str, '|');
    if (parts.size() < 7) {
        return Listener(0, "", "", "", "");
    }
    int id = std::stoi(parts[0]);
    std::string username = FileHelper::decodeSpecialChars(parts[1]);
    std::string password = FileHelper::decodeSpecialChars(parts[2]);
    std::string fullName = FileHelper::decodeSpecialChars(parts[3]);
    std::string bio = FileHelper::decodeSpecialChars(parts[4]);
    Listener listener(id, username, password, fullName, bio);
    if (!parts[6].empty()) {
        std::vector<std::string> ids = FileHelper::splitString(parts[6], ',');
        for (const std::string& idStr : ids) {
            if (!idStr.empty()) {
                listener.addPlaylist(std::stoi(idStr));
            }
        }
    }
    return listener;
}

std::string DataManager::albumToString(const Album& album)
{
    std::vector<std::string> parts;
    parts.push_back(std::to_string(album.getId()));
    parts.push_back(FileHelper::encodeSpecialChars(album.getName()));
    parts.push_back(std::to_string(album.getArtistId()));
    std::string songIdsStr;
    const std::vector<int>& songIds = album.getSongIds();
    for (size_t i = 0; i < songIds.size(); ++i) {
        if (i > 0) songIdsStr += ",";
        songIdsStr += std::to_string(songIds[i]);
    }
    parts.push_back(songIdsStr);
    return FileHelper::joinString(parts, '|');
}

Album DataManager::stringToAlbum(const std::string& str)
{
    std::vector<std::string> parts = FileHelper::splitString(str, '|');
    if (parts.size() < 4) {
        return Album(0, "", 0);
    }
    int id = std::stoi(parts[0]);
    std::string name = FileHelper::decodeSpecialChars(parts[1]);
    int artistId = std::stoi(parts[2]);
    Album album(id, name, artistId);
    if (!parts[3].empty()) {
        std::vector<std::string> ids = FileHelper::splitString(parts[3], ',');
        for (const std::string& idStr : ids) {
            if (!idStr.empty()) {
                album.addSong(std::stoi(idStr));
            }
        }
    }
    return album;
}

std::string DataManager::playlistToString(const Playlist& playlist)
{
    std::vector<std::string> parts;
    parts.push_back(std::to_string(playlist.getId()));
    parts.push_back(FileHelper::encodeSpecialChars(playlist.getName()));
    parts.push_back(std::to_string(playlist.getListenerId()));
    parts.push_back(playlist.getIsFavorite() ? "1" : "0");
    std::string songIdsStr;
    const std::vector<int>& songIds = playlist.getSongIds();
    for (size_t i = 0; i < songIds.size(); ++i) {
        if (i > 0) songIdsStr += ",";
        songIdsStr += std::to_string(songIds[i]);
    }
    parts.push_back(songIdsStr);
    return FileHelper::joinString(parts, '|');
}

Playlist DataManager::stringToPlaylist(const std::string& str)
{
    std::vector<std::string> parts = FileHelper::splitString(str, '|');
    if (parts.size() < 5) {
        return Playlist(0, "", 0, false);
    }
    int id = std::stoi(parts[0]);
    std::string name = FileHelper::decodeSpecialChars(parts[1]);
    int listenerId = std::stoi(parts[2]);
    bool isFavorite = (parts[3] == "1");
    Playlist playlist(id, name, listenerId, isFavorite);
    if (!parts[4].empty()) {
        std::vector<std::string> ids = FileHelper::splitString(parts[4], ',');
        for (const std::string& idStr : ids) {
            if (!idStr.empty()) {
                playlist.addSong(std::stoi(idStr));
            }
        }
    }
    return playlist;
}

std::string DataManager::songToString(const Song& song)
{
    std::vector<std::string> parts;
    parts.push_back(std::to_string(song.getId()));
    parts.push_back(FileHelper::encodeSpecialChars(song.getTitle()));
    parts.push_back(FileHelper::encodeSpecialChars(song.getGenre()));
    parts.push_back(std::to_string(song.getReleaseYear()));
    parts.push_back(std::to_string(song.getDuration()));
    parts.push_back(std::to_string(song.getArtistId()));
    parts.push_back(std::to_string(song.getAlbumId()));
    parts.push_back(FileHelper::encodeSpecialChars(song.getFilePath()));
    return FileHelper::joinString(parts, '|');
}

Song DataManager::stringToSong(const std::string& str)
{
    std::vector<std::string> parts = FileHelper::splitString(str, '|');
    if (parts.size() < 8) {
        return Song(0, "", "", 0, 0, 0, 0, "");
    }
    int id = std::stoi(parts[0]);
    std::string title = FileHelper::decodeSpecialChars(parts[1]);
    std::string genre = FileHelper::decodeSpecialChars(parts[2]);
    int releaseYear = std::stoi(parts[3]);
    int duration = std::stoi(parts[4]);
    int artistId = std::stoi(parts[5]);
    int albumId = std::stoi(parts[6]);
    std::string filePath = FileHelper::decodeSpecialChars(parts[7]);
    return Song(id, title, genre, releaseYear, duration, artistId, albumId, filePath);
}

bool DataManager::saveAccounts(const std::vector<Account>& accounts)
{
    std::string data;
    for (const Account& account : accounts) {
        data += accountToString(account) + "\n";
    }
    return FileHelper::writeStringToFile(getAccountFilePath(), data);
}

std::vector<Account> DataManager::loadAccounts()
{
    std::vector<Account> accounts;
    std::string data = FileHelper::readStringFromFile(getAccountFilePath());
    if (data.empty()) {
        return accounts;
    }
    std::vector<std::string> lines = FileHelper::splitString(data, '\n');
    for (const std::string& line : lines) {
        if (!line.empty()) {
            accounts.push_back(stringToAccount(line));
        }
    }
    return accounts;
}

bool DataManager::saveArtists(const std::vector<Artist>& artists)
{
    std::string data;
    for (const Artist& artist : artists) {
        data += artistToString(artist) + "\n";
    }
    return FileHelper::writeStringToFile(getArtistFilePath(), data);
}

std::vector<Artist> DataManager::loadArtists()
{
    std::vector<Artist> artists;
    std::string data = FileHelper::readStringFromFile(getArtistFilePath());
    if (data.empty()) {
        return artists;
    }
    std::vector<std::string> lines = FileHelper::splitString(data, '\n');
    for (const std::string& line : lines) {
        if (!line.empty()) {
            artists.push_back(stringToArtist(line));
        }
    }
    return artists;
}

bool DataManager::saveListeners(const std::vector<Listener>& listeners)
{
    std::string data;
    for (const Listener& listener : listeners) {
        data += listenerToString(listener) + "\n";
    }
    return FileHelper::writeStringToFile(getListenerFilePath(), data);
}

std::vector<Listener> DataManager::loadListeners()
{
    std::vector<Listener> listeners;
    std::string data = FileHelper::readStringFromFile(getListenerFilePath());
    if (data.empty()) {
        return listeners;
    }
    std::vector<std::string> lines = FileHelper::splitString(data, '\n');
    for (const std::string& line : lines) {
        if (!line.empty()) {
            listeners.push_back(stringToListener(line));
        }
    }
    return listeners;
}

bool DataManager::saveAlbums(const std::vector<Album>& albums)
{
    std::string data;
    for (const Album& album : albums) {
        data += albumToString(album) + "\n";
    }
    return FileHelper::writeStringToFile(getAlbumFilePath(), data);
}

std::vector<Album> DataManager::loadAlbums()
{
    std::vector<Album> albums;
    std::string data = FileHelper::readStringFromFile(getAlbumFilePath());
    if (data.empty()) {
        return albums;
    }
    std::vector<std::string> lines = FileHelper::splitString(data, '\n');
    for (const std::string& line : lines) {
        if (!line.empty()) {
            albums.push_back(stringToAlbum(line));
        }
    }
    return albums;
}

bool DataManager::savePlaylists(const std::vector<Playlist>& playlists)
{
    std::string data;
    for (const Playlist& playlist : playlists) {
        data += playlistToString(playlist) + "\n";
    }
    return FileHelper::writeStringToFile(getPlaylistFilePath(), data);
}

std::vector<Playlist> DataManager::loadPlaylists()
{
    std::vector<Playlist> playlists;
    std::string data = FileHelper::readStringFromFile(getPlaylistFilePath());
    if (data.empty()) {
        return playlists;
    }
    std::vector<std::string> lines = FileHelper::splitString(data, '\n');
    for (const std::string& line : lines) {
        if (!line.empty()) {
            playlists.push_back(stringToPlaylist(line));
        }
    }
    return playlists;
}

bool DataManager::saveSongs(const std::vector<Song>& songs)
{
    std::string data;
    for (const Song& song : songs) {
        data += songToString(song) + "\n";
    }
    return FileHelper::writeStringToFile(getSongFilePath(), data);
}

std::vector<Song> DataManager::loadSongs()
{
    std::vector<Song> songs;
    std::string data = FileHelper::readStringFromFile(getSongFilePath());
    if (data.empty()) {
        return songs;
    }
    std::vector<std::string> lines = FileHelper::splitString(data, '\n');
    for (const std::string& line : lines) {
        if (!line.empty()) {
            songs.push_back(stringToSong(line));
        }
    }
    return songs;
}

void DataManager::saveNextIds(int accountId, int albumId, int playlistId, int songId)
{
    std::string data = std::to_string(accountId) + "|" +
                       std::to_string(albumId) + "|" +
                       std::to_string(playlistId) + "|" +
                       std::to_string(songId);
    FileHelper::writeStringToFile(getNextIdFilePath(), data);
}

void DataManager::loadNextIds(int& accountId, int& albumId, int& playlistId, int& songId)
{
    std::string data = FileHelper::readStringFromFile(getNextIdFilePath());
    if (data.empty()) {
        accountId = 1;
        albumId = 1;
        playlistId = 1;
        songId = 1;
        return;
    }
    std::vector<std::string> parts = FileHelper::splitString(data, '|');
    if (parts.size() >= 4) {
        accountId = std::stoi(parts[0]);
        albumId = std::stoi(parts[1]);
        playlistId = std::stoi(parts[2]);
        songId = std::stoi(parts[3]);
    } else {
        accountId = 1;
        albumId = 1;
        playlistId = 1;
        songId = 1;
    }
}