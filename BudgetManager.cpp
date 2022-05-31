#include "BudgetManager.h"
#include <windows.h> //function Sleep

using namespace std;

void BudgetManager::addIncome(int idLoggedUser)
{
    Income income;

    income.setIncomeId(establishNewIncomeIdFromFile());
    income.setUserId(idLoggedUser);

    cout << "Income from today? y/n" << endl;
    char choice = AuxillaryMethods::loadCharacter();

    string date = "";
    if (choice == 'y')
    {
        date = OperationOnDates::getTodaysDate();
        income.setDate(date);
    }
    else
    {
        date = OperationOnDates::loadAndCheckDate();
        income.setDate(date);
    }

    string typeOfIncome = "";
    cout<< "What kind of income is this?" << endl;

    typeOfIncome = AuxillaryMethods::loadLine();
    income.setTypeOfIncome(typeOfIncome);

    string amountString = "";
    cout<< "How many is that?" << endl;

    //amountString = AuxillaryMethods::loadLine();
    cin >> amountString;

    //float amount = AuxillaryMethods::checkComma(amountString);
    amountString = AuxillaryMethods::checkComma(amountString);
    income.setAmountString(amountString);

    incomes.push_back(income);

    fileWithIncomesXML.addIncomeToFile(income);

    cout << endl << "Your income is added successfully!" << endl << endl;
    system("pause");

}

int BudgetManager::establishNewIncomeIdFromFile()
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
        cout<< "Add first income to the app" << endl;
        Sleep(1000);
        return 1;
    }
    return lastIncomeId + 1;
}

void BudgetManager::addExpense(int idLoggedUser)
{
    Expense expense;

    expense.setExpenseId(establishNewExpenseIdFromFile());
    expense.setUserId(idLoggedUser);

    cout << "Income from today? y/n" << endl;
    char choice = AuxillaryMethods::loadCharacter();

    string date = "";
    if (choice == 'y')
    {
        date = OperationOnDates::getTodaysDate();
        expense.setDate(date);
    }
    else
    {
        date = OperationOnDates::loadAndCheckDate();
        expense.setDate(date);
    }

    string typeOfExpense = "";
    cout<< "What kind of expense is this?" << endl;

    typeOfExpense = AuxillaryMethods::loadLine();
    expense.setTypeOfExpense(typeOfExpense);

    string amountString = "";
    cout<< "How many is that?" << endl;

    amountString = AuxillaryMethods::loadLine();

    //float amount = AuxillaryMethods::checkComma(amountString);
    amountString = AuxillaryMethods::checkComma(amountString);

    /*cout<< amountString << endl;
    system("pause");*/

    expense.setAmountString(amountString);

    fileWithExpensesXML.addExpenseToFile(expense);
    expenses.push_back(expense);

    cout << endl << "Your expense is added successfully!" << endl << endl;
    system("pause");

}

int BudgetManager::establishNewExpenseIdFromFile()
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
        cout<< "Add first expense to the app" << endl;
        Sleep(1000);
        return 1;
    }
    return lastExpenseId + 1;
}

bool compare(Income & minDate, Income & maxDate)
{
    return (minDate.getDateInt() < maxDate.getDateInt());
}

void BudgetManager::showBalanceFromCurrentMonth()
{
    int dateInt = 0;

    //convert dates in vector from string to int:
    for (int i = 0; i < incomes.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
        incomes[i].setDateInt(dateInt);
        /*cout << incomes[i].getDateInt() << endl;
        system("pause");*/
    }

    //sorting by date from earliest to latest:
    sort(incomes.begin(), incomes.end(), compare);

    //printing on screen:
    system("cls");
    if (!incomes.empty())
    {
        cout << "        >>> Balance from current month <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < incomes.size(); i++)
        {
            cout << "Income Id:              " << incomes[i].getIncomeId() << endl;
            cout << "Your Id:                " << incomes[i].getUserId() << endl;
            cout << "Date:                   " << incomes[i].getDate() << endl;
            cout << "Item:                   " << incomes[i].getTypeOfIncome() << endl;
            cout << "Amount:                 " << incomes[i].getAmountString() << endl;
            system("pause");
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have incomes and expenses yet." << endl << endl;
        system("pause");
    }
}

void BudgetManager::showBalanceFromPreviousMonth()
{

}

void BudgetManager::showBalanceFromSelectedPeriod()
{

}

vector <Income> BudgetManager::loadIncomesFromFile(int idLoggedUser)
{
    incomes = fileWithIncomesXML.loadIncomesFromFile(idLoggedUser);
    return incomes;
}

vector <Expense> BudgetManager::loadExpensesFromFile(int idLoggedUser)
{
    expenses = fileWithExpensesXML.loadExpensesFromFile(idLoggedUser);
    return expenses;
}

void BudgetManager::showAllIncomes()
{
    for (int i = 0; i < incomes.size(); i++)
    {
        /*cout<< incomes.size() << endl;
        system("pause");*/
        cout << incomes[i].getIncomeId() << endl;
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getTypeOfIncome() << endl;
        cout << incomes[i].getAmountString() << endl;
        system("pause");
    }
}

void BudgetManager::showAllExpenses()
{
    for (int i = 0; i < expenses.size(); i++)
    {
        /*cout<< incomes.size() << endl;
        system("pause");*/
        cout << expenses[i].getExpenseId() << endl;
        cout << expenses[i].getUserId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getTypeOfExpense() << endl;
        cout << expenses[i].getAmountString() << endl;
        system("pause");
    }
}
