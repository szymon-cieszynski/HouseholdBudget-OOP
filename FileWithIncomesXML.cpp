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
    xml.AddElem("Amount", income.getAmountString()); //konwersja obcinala kwote np. 10.50 zamienial na 10.5

    xml.Save("incomes.xml");
}

vector <Income> FileWithIncomesXML::loadIncomesFromFile(int idLoggedUser)
{
    vector <Income> incomes;
    Income income;

    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while( xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem( "UserId" );
            int userId = atoi(xml.GetData().c_str() );
            if(idLoggedUser == userId)
            {
                income.setUserId(userId);

                xml.FindElem( "IncomeId" );
                int incomeId = atoi(xml.GetData().c_str() );
                income.setIncomeId(incomeId);

                xml.FindElem( "Date" );
                string date = xml.GetData();
                income.setDate(date);

                xml.FindElem( "Item" );
                string item = xml.GetData();
                income.setTypeOfIncome(item);

                xml.FindElem( "Amount" );
                float amount = stof(xml.GetData().c_str() );
                //string amountString = xml.GetData();
                //income.setAmountString(amountString);
                income.setAmount(amount);
            }

            incomes.push_back(income);
            xml.OutOfElem();
        }

        cout<< incomes.size() << endl;
        system("pause");
    }
    else
    {
        cout<< "Add first income" << endl;
        Sleep(1000);
    }

    return incomes;

}
