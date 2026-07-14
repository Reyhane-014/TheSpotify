#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
private:
    int id;
    std::string title;
    std::string genre;
    int releaseYear;
    int duration;
    int artistId;
    int albumId;
    std::string filePath;

public:
    Song(int id, const std::string& title, const std::string& genre,
         int releaseYear, int duration, int artistId,
         int albumId = 0, const std::string& filePath = "");

    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getReleaseYear() const;
    int getDuration() const;
    int getArtistId() const;
    int getAlbumId() const;
    std::string getFilePath() const;

    void setTitle(const std::string& newTitle);
    void setGenre(const std::string& newGenre);
    void setReleaseYear(int year);
    void setDuration(int newDuration);
    void setAlbumId(int newAlbumId);
    void setFilePath(const std::string& path);


    bool isSingle() const;
    std::string getFormattedDuration() const;
};

#endif