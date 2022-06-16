#include "FileWithIncomesXML.h"

using namespace std;

void FileWithIncomesXML::addIncomeToFile(IncomeExpense incomeExpense)
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
    xml.AddElem("IncomeId", incomeExpense.getOperationId());
    xml.AddElem("UserId", incomeExpense.getUserId());
    xml.AddElem("Date", incomeExpense.getDate());
    xml.AddElem("Item", (incomeExpense.getTypeOfItem()));
    xml.AddElem("Amount", AuxillaryMethods::floatToString(incomeExpense.getAmount()));
    xml.Save("incomes.xml");
}

vector <IncomeExpense> FileWithIncomesXML::loadIncomesFromFile(int idLoggedUser)
{
    vector <IncomeExpense> incomes;
    IncomeExpense incomeExpense;

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
                incomeExpense.setUserId(userId);

                xml.FindElem( "IncomeId" );
                int incomeId = 0;
                incomeId = atoi(xml.GetData().c_str() );
                incomeExpense.setOperationId(incomeId);

                xml.FindElem( "Date" );
                string date = xml.GetData();
                incomeExpense.setDate(date);

                xml.FindElem( "Item" );
                string item = xml.GetData();
                incomeExpense.setTypeOfItem(item);

                xml.FindElem( "Amount" );
                float amount = stof(xml.GetData().c_str() );
                incomeExpense.setAmount(amount);

                incomes.push_back(incomeExpense);
            }
            xml.OutOfElem(); //out of Income - for checking other id's
        }
    }
    return incomes;
}

int FileWithIncomesXML::establishNewIncomeIdFromFile()
{
    int lastIncomeId = 0;
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while( xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem( "IncomeId" );
            lastIncomeId = atoi(xml.GetData().c_str() );
            xml.OutOfElem();
        }
    }
    else
    {
        return 1;
    }
    return lastIncomeId + 1;
}
