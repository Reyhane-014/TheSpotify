#include "account.h"

Account::Account(int id, const std::string& username, const std::string& password,
                 const std::string& fullName, const std::string& bio, Role role)
{
    this->id = id;
    this->username = username;
    this->password = password;
    this->fullName = fullName;
    this->bio = bio;
    this->role = role;
}