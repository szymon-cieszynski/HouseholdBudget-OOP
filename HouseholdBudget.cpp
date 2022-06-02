#include "HouseholdBudget.h"

using namespace std;

void HouseholdBudget::registrationOfUser()
{
     userManager.registrationOfUser();
}

void HouseholdBudget::logIn()
{
    idLoggedUser = userManager.logIn();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(idLoggedUser); //creating object of class BudgetManager when logged in (also loading incomes and expenses!!)
    }
}

bool HouseholdBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

char HouseholdBudget::chooseFromMainMenu()
{
    userManager.chooseFromMainMenu();
}

char HouseholdBudget::chooseFromUserMenu()
{
    userManager.chooseFromUserMenu();
}

void HouseholdBudget::addIncome()
{
    budgetManager -> addIncome(idLoggedUser);
}

void HouseholdBudget::addExpense()
{
    budgetManager -> addExpense(idLoggedUser);
}

void HouseholdBudget::showBalanceFromCurrentMonth()
{
    budgetManager -> showBalanceFromCurrentMonth();
}

void HouseholdBudget::showBalanceFromPreviousMonth()
{
    budgetManager -> showBalanceFromPreviousMonth();
}

void HouseholdBudget::showBalanceFromSelectedPeriod()
{
    budgetManager -> showBalanceFromSelectedPeriod();
}

void HouseholdBudget::changePassword()
{
    userManager.changePassword();
}

void HouseholdBudget::logOut()
{
    userManager.logOut();
    delete budgetManager;
    budgetManager = NULL;
}
