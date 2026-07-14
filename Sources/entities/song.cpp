#include "song.h"
#include <sstream>
#include <iomanip>

Song::Song(int id, const std::string& title, const std::string& genre,
           int releaseYear, int duration, int artistId,
           int albumId, const std::string& filePath)
    : id(id), title(title), genre(genre), releaseYear(releaseYear),
    duration(duration), artistId(artistId), albumId(albumId), filePath(filePath) {}

int Song::getId() const {
    return id;
}

std::string Song::getTitle() const {
    return title;
}

std::string Song::getGenre() const {
    return genre;
}

int Song::getReleaseYear() const {
    return releaseYear;
}

int Song::getDuration() const {
    return duration;
}

int Song::getArtistId() const {
    return artistId;
}

int Song::getAlbumId() const {
    return albumId;
}

std::string Song::getFilePath() const {
    return filePath;
}

void Song::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Song::setGenre(const std::string& newGenre) {
    genre = newGenre;
}

void Song::setReleaseYear(int year) {
    releaseYear = year;
}

void Song::setDuration(int newDuration) {
    duration = newDuration;
}

void Song::setAlbumId(int newAlbumId) {
    albumId = newAlbumId;
}

void Song::setFilePath(const std::string& path) {
    filePath = path;
}

bool Song::isSingle() const {
    return albumId == 0;
}

std::string Song::getFormattedDuration() const {
    int minutes = duration / 60;
    int seconds = duration % 60;
    std::ostringstream oss;
    oss << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return oss.str();
}