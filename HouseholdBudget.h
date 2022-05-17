#ifndef HOUSEHOLDBUDGET_H
#define HOUSEHOLDBUDGET_H

#include <iostream>

#include "UserManager.h"

using namespace std;


class HouseholdBudget
{
private:
    //int idLoggedUser;
    const string NAME_OF_FILE_WITH_USERS;
    UserManager userManager;

public:
    //HoseholdBudget();

    void registrationOfUser();
    void logIn();
    bool isUserLoggedIn();
    char chooseFromMainMenu();
    void loadUsersFromFile();
    void showAllUsers();


};


#endif
