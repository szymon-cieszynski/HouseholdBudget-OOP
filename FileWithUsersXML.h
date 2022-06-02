#ifndef FILEWITHUSERSXML_H
#define FILEWITHUSERSXML_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

using namespace std;

class FileWithUsersXML
{
private:
    void getDataOfUser();

public:
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void updatePasswordInFile(User user);
};


#endif
