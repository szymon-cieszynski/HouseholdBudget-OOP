#include <iostream>
#include "HouseholdBudget.h"

using namespace std;

int main()
{
    HouseholdBudget householdBudget;

    while (true)
    {
        if (!householdBudget.isUserLoggedIn())
        {
            //householdBudget.loadUsersFromFile(); transfer to the constructor
            char choice = householdBudget.chooseFromMainMenu();
            switch (choice)
            {
            case '1':
                householdBudget.registrationOfUser();
                break;
            case '2':
                householdBudget.logIn();
                break;
            case '3':
                householdBudget.showAllUsers();
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Selected option doesn't exist." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            //householdBudget.loadIncomesFromFile(); //loading inside class BudgetManager
            //householdBudget.loadExpensesFromFile();
            char choice = householdBudget.chooseFromUserMenu();

            switch (choice)
            {
            case '1':
                householdBudget.addIncome();
                break;
            case '2':
                householdBudget.addExpense();
                break;
            case '3':
                householdBudget.showBalanceFromCurrentMonth();
                break;
            case '4':
                householdBudget.showBalanceFromPreviousMonth();
                break;
            case '5':
                householdBudget.showBalanceFromSelectedPeriod();
                break;
            case '6':
                householdBudget.changePassword();
                break;
            case '7':
                householdBudget.logOut();
                break;
            case '8':
                householdBudget.showAllIncomes();
                break;
            case '9':
                householdBudget.showAllExpenses();
                break;
            }
        }
    }

    return 0;
}

