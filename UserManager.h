#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsersXML.h"

class UserManager
{
public:
    UserManager() :
    idLoggedUser(0),
    users(fileWithUsersXML.loadUsersFromFile()),
    fileWithUsersXML()
    {};

    void registrationOfUser();
    char chooseFromMainMenu();
    char chooseFromUserMenu();
    int logIn();
    bool isUserLoggedIn();
    void changePassword();
    void logOut();

private:
    unsigned int idLoggedUser;
    static const unsigned int INVALID_USER = 0;
    std::vector <User> users;

    User typeDataOfNewUser();
    int establishNewUserID();
    bool isLoginExist(const string &login);
    void changeOfLoggedUserPassword();
    FileWithUsersXML fileWithUsersXML;

};


#endif
