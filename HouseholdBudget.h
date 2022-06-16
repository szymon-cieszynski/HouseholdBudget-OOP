#ifndef HOUSEHOLDBUDGET_H
#define HOUSEHOLDBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

class HouseholdBudget
{
public:
    HouseholdBudget() :
    idLoggedUser(0),
    userManager(),
    budgetManager(NULL)
    {};
    ~HouseholdBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };

    void registrationOfUser();
    void logIn();
    bool isUserLoggedIn();
    char chooseFromMainMenu();
    char chooseFromUserMenu();
    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
    void changePassword();
    void logOut();

private:
    unsigned int idLoggedUser;
    UserManager userManager;
    BudgetManager *budgetManager;

};


#endif
