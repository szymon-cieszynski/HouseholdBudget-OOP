#include <iostream>
#include "HouseholdBudget.h"

using namespace std;

void HouseholdBudget::registrationOfUser()
{
     userManager.registrationOfUser();
}

void HouseholdBudget::logIn()
{
    userManager.logIn();
}

char HouseholdBudget::chooseFromMainMenu()
{
    userManager.chooseFromMainMenu();
}

bool HouseholdBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void HouseholdBudget::loadUsersFromFile()
{
    userManager.loadUsersFromFile();
}

void HouseholdBudget::showAllUsers()
{
    userManager.showAllUsers();
}
