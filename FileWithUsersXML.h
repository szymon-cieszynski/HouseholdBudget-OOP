//W jezyku XML tagi definiuja strukture i znaczenie danych: mowia, czym sa okreslone dane.
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
    //FileWithUsersXML();
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();


};


#endif
