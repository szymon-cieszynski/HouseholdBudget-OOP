#include "FileWithExpensesXML.h"

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
    xml.AddElem("Amount", AuxillaryMethods::floatToString(expense.getAmount()));

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
                float amount = atof(xml.GetData().c_str() );
                expense.setAmount(amount);

                expenses.push_back(expense);
            }
            xml.OutOfElem(); //out of Expense - for checking other id's
        }
    }
    return expenses;
}

int FileWithExpensesXML::establishNewExpenseIdFromFile()
{
    int lastExpenseId = 0;
    CMarkup xml;
    bool fileExists = xml.Load( "expenses.xml" );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while( xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem( "ExpenseId" );
            lastExpenseId = atoi(xml.GetData().c_str() );
            xml.OutOfElem();
        }
    }
    else
    {
        return 1;
    }
    return lastExpenseId + 1;
}
