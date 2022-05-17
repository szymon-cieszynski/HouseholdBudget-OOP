#ifndef FILEWITHUSERSXML_H
#define FILEWITHUSERSXML_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

//#include "UserManager.h"
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
