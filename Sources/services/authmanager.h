#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "../repositories/accountmanager.h"
#include "../repositories/artistmanager.h"
#include "../repositories/listenermanager.h"
#include "../repositories/albummanager.h"
#include "../repositories/playlistmanager.h"
#include "../repositories/songmanager.h"
#include "../entities/account.h"
#include <string>
#include <memory>

class AuthManager
{
private:
    AccountManager* accountManager;
    ArtistManager artistManager;
    ListenerManager listenerManager;
    AlbumManager albumManager;
    PlaylistManager playlistManager;
    SongManager songManager;

public:
    AuthManager();

    bool registerUser(const std::string& username, const std::string& password,
                      const std::string& fullName, const std::string& bio,
                      const std::string& role);

    std::shared_ptr<Account> loginUser(const std::string& username, const std::string& password);
    bool checkUsernameExists(const std::string& username) const;
    bool updateAccount(int accountId, const std::string& username, const std::string& password,
                       const std::string& fullName, const std::string& bio);
    bool deleteAccount(int accountId);
    void saveAllData();
};

#endif