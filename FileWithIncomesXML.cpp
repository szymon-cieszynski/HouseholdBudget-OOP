#include "FileWithIncomesXML.h"
#include <windows.h>


using namespace std;

void FileWithIncomesXML::addIncomeToFile(Income income)
{

    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", (income.getTypeOfIncome()));
    xml.AddElem("Amount", AuxillaryMethods::floatToString(income.getAmount()));

    xml.Save("incomes.xml");
}

vector <Income> FileWithIncomesXML::loadIncomesFromFile()
{
   /* vector <User> users;
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

    return users;*/
}
