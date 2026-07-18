#include "account.h"

Account::Account() : id(0), role(Role::Listener) {}

Account::Account(int id, const std::string& username, const std::string& password,
                 const std::string& fullName, const std::string& bio, Role role)
    : id(id), username(username), password(password), fullName(fullName), bio(bio), role(role) {}

int Account::getId() const { return id; }
std::string Account::getUsername() const { return username; }
std::string Account::getPassword() const { return password; }
std::string Account::getFullName() const { return fullName; }
std::string Account::getBio() const { return bio; }
Role Account::getRole() const { return role; }

void Account::setUsername(const std::string& username) { this->username = username; }
void Account::setPassword(const std::string& password) { this->password = password; }
void Account::setFullName(const std::string& fullName) { this->fullName = fullName; }
void Account::setBio(const std::string& bio) { this->bio = bio; }
void Account::setRole(Role role) { this->role = role; }