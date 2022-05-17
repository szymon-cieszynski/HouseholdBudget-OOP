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
       /* else
        {
            char wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //edytujAdresata(adresaci);
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
                adresaci.clear();
                ksiazkaAdresowa.wylogujUzytkownika();
                break;
            }
        }*/
    }

    return 0;
}

