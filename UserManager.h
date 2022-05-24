#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsersXML.h"

using namespace std;

class UserManager
{
private:
    int idLoggedUser;
    vector <User> users;

    User typeDataOfNewUser();
    int establishNewUserID();
    bool isLoginExist(string login);
    void changeOfLoggedUserPassword();
    FileWithUsersXML fileWithUsersXML;


public:
    UserManager()
    {
        idLoggedUser = 0;
        //users = fileWithUsersXML.loadUsersFromFile();
    };

    void registrationOfUser();
    char chooseFromMainMenu();
    char chooseFromUserMenu();
    int logIn();
    bool isUserLoggedIn();
    vector <User> loadUsersFromFile();
    void showAllUsers(); //supporting funcion!
    void changePassword();
    void logOut();


};


#endif
