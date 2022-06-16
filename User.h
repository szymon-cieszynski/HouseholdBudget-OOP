#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
public:
    User (int id = 0, string name = "", string lastName = "", string login = "", string password = "")
    {}

    void setId(unsigned int newId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    unsigned int getId();
    string getName();
    string getLastName();
    string getLogin();
    string getPassword();

private:
    unsigned int id;
    string name;
    string lastName;
    string login;
    string password;
};

#endif
