#ifndef ARTIST_H
#define ARTIST_H

#include "account.h"
#include <vector>

class Artist : public Account
{
private:
    std::vector<int> albumIds;

public:
    Artist(int id, const std::string& username, const std::string& password,
           const std::string& fullName, const std::string& bio);

    void addAlbum(int albumId);
    void removeAlbum(int albumId);
    const std::vector<int>& getAlbumIds() const;

    bool hasAlbum(int albumId) const;
    int getAlbumCount() const;
};

#endif