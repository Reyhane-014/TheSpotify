#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../entities/account.h"
#include <vector>
#include <optional>

class AccountManager
{
private:
    std::vector<Account> accounts;
    int nextId;

public:
    AccountManager();

    int storeAccount(const Account& account);
    bool deleteAccount(int id);
    std::optional<Account> findAccount(int id) const;
    std::optional<Account> findAccountByUsername(const std::string& username) const;
    std::vector<Account> getAllAccounts() const;
    bool isUsernameUsed(const std::string& username) const;
    int getTotalAccounts() const;
    void clearAllAccounts();
};

#endif