#ifndef FILEWITHUSERSXML_H
#define FILEWITHUSERSXML_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

class FileWithUsersXML
{
public:
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void updatePasswordInFile(User user);

private:
    void getDataOfUser();
};


#endif
