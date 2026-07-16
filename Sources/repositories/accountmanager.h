#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../entities/account.h"
#include <vector>
#include <optional>
#include <string>

class AccountManager
{
private:
    AccountManager();
    static AccountManager* instance;
    std::vector<Account> accounts;
    int nextId;

public:
    static AccountManager* getInstance();

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