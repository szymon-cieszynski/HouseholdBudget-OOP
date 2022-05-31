#include "FileWithExpensesXML.h"
#include <windows.h>


using namespace std;

void FileWithExpensesXML::addExpenseToFile(Expense expense)
{

    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", (expense.getTypeOfExpense()));
    //xml.AddElem("Amount", AuxillaryMethods::floatToString(expense.getAmount()));
    xml.AddElem("Amount", expense.getAmountString()); //konwersja obcinala kwote np. 10.50 zamienial na 10.5

    xml.Save("expenses.xml");
}

vector <Expense> FileWithExpensesXML::loadExpensesFromFile(int idLoggedUser)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );

    if (fileExists)
    {
        xml.FindElem(); //enter to Expenses
        xml.IntoElem();

        while( xml.FindElem("Expense"))
        {
            xml.IntoElem(); //enter to Expense
            xml.FindElem("UserId");

            int userId = atoi(xml.GetData().c_str());

            if(idLoggedUser == userId)
            {
                xml.ResetMainPos(); //without this wrong writing of expenseId
                expense.setUserId(userId);

                xml.FindElem( "ExpenseId" );
                int expenseId = 0;
                expenseId = atoi(xml.GetData().c_str() );
                expense.setExpenseId(expenseId);

                xml.FindElem( "Date" );
                string date = xml.GetData();
                expense.setDate(date);

                xml.FindElem( "Item" );
                string item = xml.GetData();
                expense.setTypeOfExpense(item);

                xml.FindElem( "Amount" );
                /*float amount = atof(xml.GetData().c_str() );
                expense.setAmount(amount);*/

                string amountString = xml.GetData(); //for two characters amount after pointer - for example 10.50
                expense.setAmountString(amountString);

                expenses.push_back(expense);
            }
            xml.OutOfElem(); //out of Expense - jesli bylo to w ifie to sprawdzal tylko jedno id, nie zwazal na inne
        }
        /*cout<< expenses.size() << endl;
        system("pause");*/
    }
    else
    {
        cout<< "Add first expense" << endl;
        Sleep(1000);
    }
    return expenses;
}
