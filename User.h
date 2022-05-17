#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string lastName;
    string login;
    string password;

public: //gettery i settery???? w pliku .cpp sa ustawione zeby inne metody mogly ustawiac te wartosci ktore sa wyzej prywatne!!
    void setId(int newId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getLastName();
    string getLogin();
    string getPassword();
};

#endif
