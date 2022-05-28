#include "HouseholdBudget.h"

using namespace std;

void HouseholdBudget::registrationOfUser()
{
     userManager.registrationOfUser();
}

void HouseholdBudget::logIn()
{
    idLoggedUser = userManager.logIn();
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
    budgetManager.addIncome(idLoggedUser);
}

void HouseholdBudget::addExpense()
{
    budgetManager.addExpense(idLoggedUser);
}

void HouseholdBudget::showBalanceFromCurrentMonth()
{
    budgetManager.showBalanceFromCurrentMonth();
}

void HouseholdBudget::showBalanceFromPreviousMonth()
{
    budgetManager.showBalanceFromPreviousMonth();
}

void HouseholdBudget::showBalanceFromSelectedPeriod()
{
    budgetManager.showBalanceFromSelectedPeriod();
}

void HouseholdBudget::changePassword()
{
    userManager.changePassword();
}

void HouseholdBudget::logOut()
{
    userManager.logOut();
}


void HouseholdBudget::loadUsersFromFile()
{
    userManager.loadUsersFromFile();
}

void HouseholdBudget::loadIncomesFromFile()
{
    budgetManager.loadIncomesFromFile(idLoggedUser);
}

void HouseholdBudget::loadExpensesFromFile()
{
    budgetManager.loadExpensesFromFile(idLoggedUser);
}

void HouseholdBudget::showAllUsers()
{
    userManager.showAllUsers();
}

void HouseholdBudget::showAllIncomes()
{
    budgetManager.showAllIncomes();
}

void HouseholdBudget::showAllExpenses()
{
    budgetManager.showAllExpenses();
}
