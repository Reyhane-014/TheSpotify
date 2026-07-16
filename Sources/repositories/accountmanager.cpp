#include "accountmanager.h"
#include <iostream>

AccountManager* AccountManager::instance = nullptr;

AccountManager::AccountManager() : nextId(1) {}

AccountManager* AccountManager::getInstance()
{
    if (instance == nullptr) {
        instance = new AccountManager();
    }
    return instance;
}

int AccountManager::storeAccount(const Account& account)
{
    std::cout << "=== ACCOUNT MANAGER: STORE ===" << std::endl;
    std::cout << "Username: " << account.getUsername() << std::endl;
    std::cout << "Current accounts count: " << accounts.size() << std::endl;

    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getId() == account.getId()) {
            accounts[i] = account;
            std::cout << "Account updated! ID: " << accounts[i].getId() << std::endl;
            return accounts[i].getId();
        }
    }

    Account newAccount(nextId, account.getUsername(), account.getPassword(),
                       account.getFullName(), account.getBio(), account.getRole());
    accounts.push_back(newAccount);
    std::cout << "New account created! ID: " << nextId << std::endl;
    std::cout << "Accounts count after store: " << accounts.size() << std::endl;
    return nextId++;
}

bool AccountManager::deleteAccount(int id)
{
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getId() == id) {
            accounts.erase(accounts.begin() + i);
            return true;
        }
    }
    return false;
}

std::optional<Account> AccountManager::findAccount(int id) const
{
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getId() == id) {
            return accounts[i];
        }
    }
    return std::nullopt;
}

std::optional<Account> AccountManager::findAccountByUsername(const std::string& username) const
{
    std::cout << "=== ACCOUNT MANAGER: FIND BY USERNAME ===" << std::endl;
    std::cout << "Looking for: " << username << std::endl;
    std::cout << "Total accounts in vector: " << accounts.size() << std::endl;

    for (int i = 0; i < (int)accounts.size(); i++) {
        std::cout << "  Checking: " << accounts[i].getUsername() << std::endl;
        if (accounts[i].getUsername() == username) {
            std::cout << "  FOUND!" << std::endl;
            return accounts[i];
        }
    }
    std::cout << "  NOT FOUND!" << std::endl;
    return std::nullopt;
}

std::vector<Account> AccountManager::getAllAccounts() const
{
    return accounts;
}

bool AccountManager::isUsernameUsed(const std::string& username) const
{
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getUsername() == username) {
            return true;
        }
    }
    return false;
}

int AccountManager::getTotalAccounts() const
{
    return (int)accounts.size();
}

void AccountManager::clearAllAccounts()
{
    accounts.clear();
}