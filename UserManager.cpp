#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

void UserManager::registrationOfUser()
{
    User user = typeDataOfNewUser();

    users.push_back(user);

    fileWithUsersXML.addUserToFile(user);

    cout << endl << "Your account is created successfully!" << endl << endl;
    system("pause");
}


User UserManager::typeDataOfNewUser()
{
    User user;

    user.setId(getNewUserID());

    string login;
    do
    {
        cout << endl << "Enter login: ";
        login = AuxillaryMethods::loadLine();
        user.setLogin(login);
    }
    while (isLoginExist(user.getLogin()) == true);

    string name;
    cout << "Enter your name: ";
    name = AuxillaryMethods::loadLine();
    name = AuxillaryMethods::changeFirstLetterToCapitalAndOthersToLower(name);


    string lastName;
    cout << "Enter your last name: ";
    lastName = AuxillaryMethods::loadLine();
    lastName = AuxillaryMethods::changeFirstLetterToCapitalAndOthersToLower(lastName);

    string password;
    cout << "Enter password: ";
    cin >> password;

    user.setName(name);
    user.setLastName(lastName);
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with this login already exist." << endl;
            return true;
        }
    }
    return false;
}

char UserManager::chooseFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "3. Show all users" << endl;
    cout << "9. End of work" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxillaryMethods::loadCharacter();

    return choice;
}

int UserManager::logIn()
{

}

bool UserManager::isUserLoggedIn()
{

}

vector <User> UserManager::loadUsersFromFile()
{
    users = fileWithUsersXML.loadUsersFromFile();
    return users;
}

void UserManager::showAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getLastName() << endl;
        cout << users[i].getPassword() << endl;
    }
}








