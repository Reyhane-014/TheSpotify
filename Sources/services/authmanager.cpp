#include "authmanager.h"

AuthManager::AuthManager() {}

bool AuthManager::registerUser(const std::string& username, const std::string& password,
                               const std::string& fullName, const std::string& bio,
                               const std::string& role)
{
    if (checkUsernameExists(username)) {
        return false;
    }

    if (username.empty() || password.empty() || fullName.empty()) {
        return false;
    }

    if (role != "Artist" && role != "Listener" &&
        role != "artist" && role != "listener") {
        return false;
    }

    Role userRole = (role == "Artist" || role == "artist") ? Role::Artist : Role::Listener;

    Account newAccount(0, username, password, fullName, bio, userRole);
    int accountId = accountManager.storeAccount(newAccount);

    if (userRole == Role::Artist) {
        Artist newArtist(accountId, username, password, fullName, bio);
        artistManager.saveArtist(newArtist);
    } else {
        Listener newListener(accountId, username, password, fullName, bio);
        listenerManager.storeListener(newListener);
    }

    return true;
}

std::shared_ptr<Account> AuthManager::loginUser(const std::string& username, const std::string& password)
{
    auto account = accountManager.findAccountByUsername(username);

    if (!account.has_value()) {
        return nullptr;
    }

    if (account.value().getPassword() != password) {
        return nullptr;
    }

    return std::make_shared<Account>(account.value());
}

bool AuthManager::checkUsernameExists(const std::string& username) const
{
    return accountManager.isUsernameUsed(username);
}