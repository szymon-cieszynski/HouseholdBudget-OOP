#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "FileWithUsersXML.h"
//#include "AuxillaryMethods.h"

using namespace std;

class UserManager
{
private:
    int idLoggedUser;
    vector <User> users;

    User typeDataOfNewUser();
    int getNewUserID();
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
    int logIn();
    bool isUserLoggedIn();
    vector <User> loadUsersFromFile();
    void showAllUsers();


};


#endif
