#include "FileWithExpensesXML.h"

using namespace std;

void FileWithExpensesXML::addExpenseToFile(IncomeExpense incomeExpense)
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
    xml.AddElem("ExpenseId", incomeExpense.getOperationId());
    xml.AddElem("UserId", incomeExpense.getUserId());
    xml.AddElem("Date", incomeExpense.getDate());
    xml.AddElem("Item", (incomeExpense.getTypeOfItem()));
    xml.AddElem("Amount", AuxillaryMethods::floatToString(incomeExpense.getAmount()));

    xml.Save("expenses.xml");
}

vector <IncomeExpense> FileWithExpensesXML::loadExpensesFromFile(int idLoggedUser)
{
    vector <IncomeExpense> expenses;
    IncomeExpense incomeExpense;

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
                incomeExpense.setUserId(userId);

                xml.FindElem( "ExpenseId" );
                int expenseId = 0;
                expenseId = atoi(xml.GetData().c_str() );
                incomeExpense.setOperationId(expenseId);

                xml.FindElem( "Date" );
                string date = xml.GetData();
                incomeExpense.setDate(date);

                xml.FindElem( "Item" );
                string item = xml.GetData();
                incomeExpense.setTypeOfItem(item);

                xml.FindElem( "Amount" );
                float amount = atof(xml.GetData().c_str() );
                incomeExpense.setAmount(amount);

                expenses.push_back(incomeExpense);
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
