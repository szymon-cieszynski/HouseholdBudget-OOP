#include "BudgetManager.h"
#include <windows.h> //function Sleep

using namespace std;

void BudgetManager::addIncome(int idLoggedUser)
{
    Income income;

    income.setIncomeId(fileWithIncomesXML.establishNewIncomeIdFromFile());
    income.setUserId(idLoggedUser);

    string date = "";

    bool flag = true;
    while (flag)
    {
        cout << "Income from today? y / n" << endl;
        char choice = AuxillaryMethods::loadCharacter();
        switch(choice)
        {
        case 'y':
            flag = false;
            date = OperationOnDates::getTodaysDate();
            income.setDate(date);
            break;
        case 'n':
            flag = false;
            date = OperationOnDates::loadAndCheckDate();
            income.setDate(date);
            break;
        default:
            cout << endl << "There is no option like this." << endl << endl;
            system("pause");
            break;
        }
    }

    string typeOfIncome = "";
    cout<< "What kind of income is this?" << endl;

    typeOfIncome = AuxillaryMethods::loadLine();
    income.setTypeOfIncome(typeOfIncome);

    string amountString = "";
    cout<< "How many is that?" << endl;

    cin >> amountString;
    amountString = AuxillaryMethods::checkComma(amountString);
    income.setAmountString(amountString);

    incomes.push_back(income);
    fileWithIncomesXML.addIncomeToFile(income);

    cout << endl << "Your income is added successfully!" << endl << endl;
    system("pause");

}

void BudgetManager::addExpense(int idLoggedUser)
{
    Expense expense;

    expense.setExpenseId(fileWithExpensesXML.establishNewExpenseIdFromFile());
    expense.setUserId(idLoggedUser);

    string date = "";
    bool flag = true;

    while (flag)
    {
        cout << "Expense from today? y / n" << endl;
        char choice = AuxillaryMethods::loadCharacter();
        switch(choice)
        {
        case 'y':
            flag = false;
            date = OperationOnDates::getTodaysDate();
            expense.setDate(date);
            break;
        case 'n':
            flag = false;
            date = OperationOnDates::loadAndCheckDate();
            expense.setDate(date);
            break;
        default:
            cout << endl << "There is no option like this." << endl << endl;
            system("pause");
            break;
        }
    }

    string typeOfExpense = "";
    cout<< "What kind of expense is this?" << endl;

    typeOfExpense = AuxillaryMethods::loadLine();
    expense.setTypeOfExpense(typeOfExpense);

    string amountString = "";
    cout<< "How many is that?" << endl;

    amountString = AuxillaryMethods::loadLine();

    amountString = AuxillaryMethods::checkComma(amountString);

    expense.setAmountString(amountString);
    fileWithExpensesXML.addExpenseToFile(expense);
    expenses.push_back(expense);

    cout << endl << "Your expense is added successfully!" << endl << endl;
    system("pause");

}


bool compareIncomes(Income date1, Income date2)
{
    return (date1.getDateInt() < date2.getDateInt());
}

bool compareExpenses(Expense date1, Expense date2)
{
    return (date1.getDateInt() < date2.getDateInt());
}

void BudgetManager::showBalanceFromCurrentMonth()
{
    int dateInt = 0;

    //convert dates in vector incomes from string to int:
    for (int i = 0; i < incomes.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
        incomes[i].setDateInt(dateInt);
    }

    //sorting by date from earliest to latest:
    sort(incomes.begin(), incomes.end(), compareIncomes);

    int firstDayOfCurrentMonth = 0;
    string currentDate = OperationOnDates::getTodaysDate();
    string firstDay = OperationOnDates::changeCurrentDateToFirstDayOfMonth(currentDate);

    firstDayOfCurrentMonth = OperationOnDates::dateStringToInt(firstDay);

    //printing on screen:
    system("cls");
    float sumIncomes = 0;
    if (!incomes.empty())
    {
        cout << "        >>> Balance from current month. <<<" << endl;
        cout << "         Incomes: " << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < incomes.size(); i++)
        {
            if(incomes[i].getDateInt() >= firstDayOfCurrentMonth)
            {
                cout << "Income Id:              " << incomes[i].getIncomeId() << endl;
                cout << "Date:                   " << incomes[i].getDate() << endl;
                cout << "Item:                   " << incomes[i].getTypeOfIncome() << endl;
                cout << "Amount:                 " << incomes[i].getAmountString() << endl;
                sumIncomes += stof(incomes[i].getAmountString());
                system("pause");
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have incomes yet." << endl << endl;
        system("pause");
    }

    //convert dates in vector expenses from string to int:
    for (int i = 0; i < expenses.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(expenses[i].getDate());
        expenses[i].setDateInt(dateInt);
    }

    //sorting by date from earliest to latest:
    sort(expenses.begin(), expenses.end(), compareExpenses);

    //printing on screen:
    float sumExpenses = 0;
    if (!expenses.empty())
    {
        cout << "         Expenses: " << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < expenses.size(); i++)
        {
            if(expenses[i].getDateInt() >= firstDayOfCurrentMonth)
            {
                cout << "Expense Id:             " << expenses[i].getExpenseId() << endl;
                cout << "Date:                   " << expenses[i].getDate() << endl;
                cout << "Item:                   " << expenses[i].getTypeOfExpense() << endl;
                cout << "Amount:                 " << expenses[i].getAmountString() << endl;
                sumExpenses += stof(expenses[i].getAmountString());
                system("pause");
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have expenses yet." << endl << endl;
        system("pause");
    }

    cout << endl << "Sum of incomes:                            " << sumIncomes << endl;
    cout << endl << "Sum of expenses:                           " << sumExpenses << endl;
    cout << endl << "Difference between incomes and expenses:   " << sumIncomes - sumExpenses << endl << endl;
    system("pause");
}

void BudgetManager::showBalanceFromPreviousMonth()
{
    int dateInt = 0;

    //convert dates in vector incomes from string to int:
    for (int i = 0; i < incomes.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
        incomes[i].setDateInt(dateInt);
    }

    //sorting by date from earliest to latest:
    sort(incomes.begin(), incomes.end(), compareIncomes);

    int firstDayOfCurrentMonth = 0;
    string currentDate = OperationOnDates::getTodaysDate();

    string firstDayThisMonth = OperationOnDates::changeCurrentDateToFirstDayOfMonth(currentDate);
    firstDayOfCurrentMonth = OperationOnDates::dateStringToInt(firstDayThisMonth);

    int firstDayOfPreviousMonth = 0;
    string firstDayPrevMonth = OperationOnDates::changeCurrentDateToFirstDayOfPreviousMonth(currentDate);

    firstDayOfPreviousMonth = OperationOnDates::dateStringToInt(firstDayPrevMonth);

    //printing on screen:
    system("cls");
    float sumIncomes = 0;
    if (!incomes.empty())
    {
        cout << "        >>> Balance from previous month. <<<" << endl;
        cout << "         Incomes: " << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < incomes.size(); i++)
        {
            if(incomes[i].getDateInt() >= firstDayOfPreviousMonth && incomes[i].getDateInt() < firstDayOfCurrentMonth)
            {
                cout << "Income Id:              " << incomes[i].getIncomeId() << endl;
                cout << "Date:                   " << incomes[i].getDate() << endl;
                cout << "Item:                   " << incomes[i].getTypeOfIncome() << endl;
                cout << "Amount:                 " << incomes[i].getAmountString() << endl;
                sumIncomes += stof(incomes[i].getAmountString());
                system("pause");
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have incomes yet." << endl << endl;
        system("pause");
    }

    //convert dates in vector expenses from string to int:
    for (int i = 0; i < expenses.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(expenses[i].getDate());
        expenses[i].setDateInt(dateInt);
    }

    //sorting by date from earliest to latest:
    sort(expenses.begin(), expenses.end(), compareExpenses);

    //printing on screen:
    float sumExpenses = 0;
    if (!expenses.empty())
    {
        cout << "         Expenses: " << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < expenses.size(); i++)
        {
            if(expenses[i].getDateInt() >= firstDayOfPreviousMonth && expenses[i].getDateInt() < firstDayOfCurrentMonth)
            {
                cout << "Expense Id:             " << expenses[i].getExpenseId() << endl;
                cout << "Date:                   " << expenses[i].getDate() << endl;
                cout << "Item:                   " << expenses[i].getTypeOfExpense() << endl;
                cout << "Amount:                 " << expenses[i].getAmountString() << endl;
                sumExpenses += stof(expenses[i].getAmountString());
                system("pause");
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have expenses yet." << endl << endl;
        system("pause");
    }

    cout << endl << "Sum of incomes:                            " << sumIncomes << endl;
    cout << endl << "Sum of expenses:                           " << sumExpenses << endl;
    cout << endl << "Difference between incomes and expenses:   " << sumIncomes - sumExpenses << endl << endl;
    system("pause");
}

void BudgetManager::showBalanceFromSelectedPeriod()
{
    int dateInt = 0;
    string date1 = "";
    string date2 = "";

    date1 = OperationOnDates::loadAndCheckDate();
    date2 = OperationOnDates::loadAndCheckDate();

    //convert dates in vector incomes from string to int:
    for (int i = 0; i < incomes.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
        incomes[i].setDateInt(dateInt);
    }

    //sorting by date from earliest to latest:
    sort(incomes.begin(), incomes.end(), compareIncomes);

    int date1Integer = OperationOnDates::dateStringToInt(date1);
    int date2Integer = OperationOnDates::dateStringToInt(date2);

    //printing on screen:
    system("cls");
    float sumIncomes = 0;
    if (!incomes.empty())
    {
        cout << "        >>> Balance from selected period. <<<" << endl;
        cout << "         Incomes: " << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < incomes.size(); i++)
        {
            if(incomes[i].getDateInt() >= date1Integer && incomes[i].getDateInt() <= date2Integer)
            {
                cout << "Income Id:              " << incomes[i].getIncomeId() << endl;
                cout << "Date:                   " << incomes[i].getDate() << endl;
                cout << "Item:                   " << incomes[i].getTypeOfIncome() << endl;
                cout << "Amount:                 " << incomes[i].getAmountString() << endl;
                sumIncomes += stof(incomes[i].getAmountString());
                system("pause");
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have incomes yet." << endl << endl;
        system("pause");
    }

    //convert dates in vector expenses from string to int:
    for (int i = 0; i < expenses.size(); i++)
    {
        dateInt = OperationOnDates::dateStringToInt(expenses[i].getDate());
        expenses[i].setDateInt(dateInt);
    }

    //sorting by date from earliest to latest:
    sort(expenses.begin(), expenses.end(), compareExpenses);

    //printing on screen:
    float sumExpenses = 0;
    if (!expenses.empty())
    {
        cout << "         Expenses: " << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < expenses.size(); i++)
        {
            if(expenses[i].getDateInt() >= date1Integer && expenses[i].getDateInt() <= date2Integer)
            {
                cout << "Expense Id:             " << expenses[i].getExpenseId() << endl;
                cout << "Date:                   " << expenses[i].getDate() << endl;
                cout << "Item:                   " << expenses[i].getTypeOfExpense() << endl;
                cout << "Amount:                 " << expenses[i].getAmountString() << endl;
                sumExpenses += stof(expenses[i].getAmountString());
                system("pause");
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "You don't have expenses yet." << endl << endl;
        system("pause");
    }

    cout << endl << "Sum of incomes:                            " << sumIncomes << endl;
    cout << endl << "Sum of expenses:                           " << sumExpenses << endl;
    cout << endl << "Difference between incomes and expenses:   " << sumIncomes - sumExpenses << endl << endl;
    system("pause");
}

void BudgetManager::showAllIncomes()
{
    for (int i = 0; i < incomes.size(); i++)
    {
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
        cout << expenses[i].getExpenseId() << endl;
        cout << expenses[i].getUserId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getTypeOfExpense() << endl;
        cout << expenses[i].getAmountString() << endl;
        system("pause");
    }
}
