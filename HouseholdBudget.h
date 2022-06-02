#ifndef HOUSEHOLDBUDGET_H
#define HOUSEHOLDBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;


class HouseholdBudget
{
private:
    int idLoggedUser = 0;
    UserManager userManager;
    BudgetManager *budgetManager;

public:
    HouseholdBudget()
    {
        budgetManager = NULL;
    };
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

};


#endif
