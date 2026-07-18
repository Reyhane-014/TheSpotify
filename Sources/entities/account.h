#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

enum class Role {
    Artist,
    Listener
};

class Account
{
private:
    int id;
    std::string username;
    std::string password;
    std::string fullName;
    std::string bio;
    Role role;

public:
    Account();
    Account(int id, const std::string& username, const std::string& password,
            const std::string& fullName, const std::string& bio, Role role);

    int getId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getFullName() const;
    std::string getBio() const;
    Role getRole() const;

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setFullName(const std::string& fullName);
    void setBio(const std::string& bio);
    void setRole(Role role);
};

#endif