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
    Account(int id, const std::string& username, const std::string& password,
            const std::string& fullName, const std::string& bio, Role role);

    // Getters
    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getFullName() const { return fullName; }
    std::string getBio() const { return bio; }
    Role getRole() const { return role; }

    // Setters
    void setUsername(const std::string& newUsername) { username = newUsername; }
    void setPassword(const std::string& newPassword) { password = newPassword; }
    void setFullName(const std::string& newFullName) { fullName = newFullName; }
    void setBio(const std::string& newBio) { bio = newBio; }

    virtual ~Account() = default;
};

#endif