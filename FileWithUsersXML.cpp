#include "FileWithUsersXML.h"
#include <windows.h>

using namespace std;

void FileWithUsersXML::addUserToFile(User user)
{

    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Name", user.getName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Password", user.getPassword());

    xml.Save("users.xml");
}

vector <User> FileWithUsersXML::loadUsersFromFile()
{
    vector <User> users;
    User user;

    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while( xml.FindElem("User"))
        {
            //xml.FindElem();
            xml.IntoElem();
            xml.FindElem( "UserId" );
            int id = atoi(xml.GetData().c_str() );
            user.setId(id);
            //xml.ResetMainPos();

            xml.FindElem( "Login" );
            string login = xml.GetData();
            user.setLogin(login);
            //xml.ResetMainPos();

            xml.FindElem( "Name" );
            string name = xml.GetData();
            user.setName(name);
            //xml.ResetMainPos();

            xml.FindElem( "LastName" );
            string lastName = xml.GetData();
            user.setLastName(lastName);
            //xml.ResetMainPos();

            xml.FindElem( "Password" );
            string password = xml.GetData();
            user.setPassword(password);

            users.push_back(user);
            xml.OutOfElem();

        }
        //xml.Close();
    }
    else
    {
        cout<< "Add first user to the app" << endl;
        Sleep(1000);
    }

    return users;
}

void FileWithUsersXML::updatePasswordInFile(User user, int idLoggedUser)
//void FileWithUsersXML::updatePasswordInFile(vector <User> &users)
{

    /*CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );



    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        for (int i = 0; i < users.size(); i++)
        {
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem("UserId", users[i].getId());
            xml.AddElem("Login", users[i].getLogin());
            xml.AddElem("Name", users[i].getName());
            xml.AddElem("LastName", users[i].getLastName());
            xml.AddElem("Password", users[i].getPassword());

            xml.Save("users.xml");
        }


    }
    else
    {
        cout<< "Error!" << endl;
        Sleep(1000);
    }*/


    CMarkup xml;
    bool fileExists = xml.Load( "users.xml" );

    if (fileExists)
    {
        xml.FindElem(); //enter to Users
        xml.IntoElem();

        while( xml.FindElem("User"))
        {

            xml.IntoElem(); //enter to User
            xml.FindElem("UserId");

            int userId = atoi(xml.GetData().c_str());

            if(idLoggedUser == userId)
            {
               // xml.ResetMainPos();

                xml.FindElem("Password");
                //xml.IntoElem();
                xml.RemoveElem();
                xml.AddElem("Password", user.getPassword());
                xml.Save("users.xml");

            }
            xml.OutOfElem(); //out of Income - jesli bylo to w ifie to sprawdzal tylko jedno id, nie zwazal na inne
        }
    }
    else
    {
        cout<< "Error!" << endl;
        Sleep(1000);
    }
}
