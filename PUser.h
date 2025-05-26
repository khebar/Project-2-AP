#pragma once
#include <iostream>

#include <string>
using namespace std;
class PUser
{
private:
    string username;
    string password;

public:
	PUser(string user, string pass) : username(user), password(pass) {}
    virtual void setUsername(const string& user) { this->username = user; }
    virtual void setPassword(const string& pass) { this->password = pass; }
    virtual string getUsername() const { return username; }
    virtual string getPassword() const { return password; }
    virtual ~PUser() {}
};

