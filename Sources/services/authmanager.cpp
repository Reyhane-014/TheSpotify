#include "authmanager.h"
#include <iostream>

AuthManager::AuthManager()
{
    accountManager = AccountManager::getInstance();
}

bool AuthManager::registerUser(const std::string& username, const std::string& password,
                               const std::string& fullName, const std::string& bio,
                               const std::string& role)
{
    std::cout << "=== REGISTER ===" << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "FullName: " << fullName << std::endl;
    std::cout << "Role: " << role << std::endl;

    if (checkUsernameExists(username)) {
        std::cout << "Username already exists!" << std::endl;
        return false;
    }

    if (username.empty() || password.empty() || fullName.empty()) {
        std::cout << "Empty fields!" << std::endl;
        return false;
    }

    if (role != "Artist" && role != "Listener" &&
        role != "artist" && role != "listener") {
        std::cout << "Invalid role!" << std::endl;
        return false;
    }

    Role userRole = (role == "Artist" || role == "artist") ? Role::Artist : Role::Listener;

    Account newAccount(0, username, password, fullName, bio, userRole);
    int accountId = accountManager->storeAccount(newAccount);
    std::cout << "Account stored with ID: " << accountId << std::endl;

    if (userRole == Role::Artist) {
        Artist newArtist(accountId, username, password, fullName, bio);
        artistManager.saveArtist(newArtist);
        std::cout << "Artist saved!" << std::endl;
    } else {
        Listener newListener(accountId, username, password, fullName, bio);
        listenerManager.storeListener(newListener);
        std::cout << "Listener saved!" << std::endl;
    }

    std::cout << "=== REGISTER COMPLETE ===" << std::endl;
    return true;
}

std::shared_ptr<Account> AuthManager::loginUser(const std::string& username, const std::string& password)
{
    std::cout << "=== LOGIN ===" << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;

    auto account = accountManager->findAccountByUsername(username);

    if (!account.has_value()) {
        std::cout << "Account NOT found!" << std::endl;
        std::cout << "Total accounts in manager: " << accountManager->getTotalAccounts() << std::endl;
        return nullptr;
    }

    std::cout << "Account found!" << std::endl;
    std::cout << "Stored password: " << account.value().getPassword() << std::endl;

    if (account.value().getPassword() != password) {
        std::cout << "Password mismatch!" << std::endl;
        return nullptr;
    }

    std::cout << "=== LOGIN SUCCESS ===" << std::endl;
    return std::make_shared<Account>(account.value());
}

bool AuthManager::checkUsernameExists(const std::string& username) const
{
    return accountManager->isUsernameUsed(username);
}