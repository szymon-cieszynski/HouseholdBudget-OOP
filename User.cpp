#include "User.h"

using namespace std;

void User::setId(unsigned int newId)
{
    if (newId >= 0)
        id = newId;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setLastName(string newLastName)
{
    lastName = newLastName;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}
void User::setPassword(string newPassword)
{
    password = newPassword;
}

unsigned int User::getId()
{
    return id;
}

string User::getName()
{
    return name;
}

string User::getLastName()
{
    return lastName;
}

string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
