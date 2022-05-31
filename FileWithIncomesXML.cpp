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
    //xml.AddElem("Amount", AuxillaryMethods::floatToString(income.getAmount()));
    xml.AddElem("Amount", (income.getAmountString())); //konwersja obcinala kwote np. 10.50 zamienial na 10.5
    xml.Save("incomes.xml");
}

vector <Income> FileWithIncomesXML::loadIncomesFromFile(int idLoggedUser)
{
    vector <Income> incomes;
    Income income;


        /*cout<< "Logged User: " << idLoggedUser << endl;
        system("pause");*/

    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );

    if (fileExists)
    {
        xml.FindElem(); //enter to Incomes
        xml.IntoElem();

        while( xml.FindElem("Income"))
        {
            xml.IntoElem(); //enter to Income
            xml.FindElem("UserId");

            int userId = atoi(xml.GetData().c_str());

            if(idLoggedUser == userId)
            {
                xml.ResetMainPos(); //without this wrong writing of incomeId
                income.setUserId(userId);

                xml.FindElem( "IncomeId" );
                int incomeId = 0;
                incomeId = atoi(xml.GetData().c_str() );
                income.setIncomeId(incomeId);

                xml.FindElem( "Date" );
                string date = xml.GetData();
                income.setDate(date);

                xml.FindElem( "Item" );
                string item = xml.GetData();
                income.setTypeOfIncome(item);

                xml.FindElem( "Amount" );
                /*float amount = atof(xml.GetData().c_str() );
                income.setAmount(amount);*/

                string amountString = xml.GetData(); //for two characters amount after pointer - for example 10.50
                income.setAmountString(amountString);

                incomes.push_back(income);
            }
            xml.OutOfElem(); //out of Income - jesli bylo to w ifie to sprawdzal tylko jedno id, nie zwazal na inne
        }
        /*cout<< incomes.size() << endl;
        system("pause");*/
    }
    else
    {
        cout<< "Add first income" << endl;
        Sleep(1000);
    }
    return incomes;
}
