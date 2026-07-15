#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "../repositories/AccountManager.h"
#include "../repositories/ArtistManager.h"
#include "../repositories/ListenerManager.h"
#include "../entities/account.h"
#include <string>
#include <memory>

class AuthManager
{
private:
    AccountManager accountManager;
    ArtistManager artistManager;
    ListenerManager listenerManager;

public:
    AuthManager();

    bool registerUser(const std::string& username, const std::string& password,
                      const std::string& fullName, const std::string& bio,
                      const std::string& role);

    std::shared_ptr<Account> loginUser(const std::string& username, const std::string& password);

    bool checkUsernameExists(const std::string& username) const;
};

#endif