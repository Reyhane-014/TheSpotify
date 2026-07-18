#include "artist.h"
#include <algorithm>

Artist::Artist() : Account() {}

Artist::Artist(int id, const std::string& username, const std::string& password,
               const std::string& fullName, const std::string& bio)
    : Account(id, username, password, fullName, bio, Role::Artist) {}

void Artist::addAlbum(int albumId)
{
    if (!hasAlbum(albumId)) {
        albumIds.push_back(albumId);
    }
}

void Artist::removeAlbum(int albumId)
{
    auto it = std::find(albumIds.begin(), albumIds.end(), albumId);
    if (it != albumIds.end()) {
        albumIds.erase(it);
    }
}

const std::vector<int>& Artist::getAlbumIds() const
{
    return albumIds;
}

bool Artist::hasAlbum(int albumId) const
{
    return std::find(albumIds.begin(), albumIds.end(), albumId) != albumIds.end();
}

int Artist::getAlbumCount() const
{
    return static_cast<int>(albumIds.size());
}