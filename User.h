#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
protected:
    string username;
    string password;
    string userRole;

public:
    User(const string& name, const string& pword, const string& userR);

    string getUsername() const;
    string getPassword() const;
    string getRole() const;

    void setUsername(const string& name);
    void setPassword(const string& pword);

    bool registerUser();
    bool login();
    virtual void displayUserMenu() const = 0;

    virtual ~User() = default;
};

#endif // USER_H