//W jezyku XML tagi definiuja strukture i znaczenie danych: mowia, czym sa okreslone dane.
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
            householdBudget.loadUsersFromFile();
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
    }

    return 0;
}

