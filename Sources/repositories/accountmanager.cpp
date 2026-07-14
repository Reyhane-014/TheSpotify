#include "AccountManager.h"
#include <algorithm>

AccountManager::AccountManager() : nextId(1) {}

int AccountManager::storeAccount(const Account& account)
{
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getId() == account.getId()) {
            accounts[i] = account;
            return accounts[i].getId();
        }
    }

    Account newAccount(nextId, account.getUsername(), account.getPassword(),
                       account.getFullName(), account.getBio(), account.getRole());
    accounts.push_back(newAccount);
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
    for (int i = 0; i < (int)accounts.size(); i++) {
        if (accounts[i].getUsername() == username) {
            return accounts[i];
        }
    }
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