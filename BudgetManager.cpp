#include "BudgetManager.h"
#include <windows.h> //function Sleep
#include <iomanip> // function setprecision()

using namespace std;

void BudgetManager::addIncome(unsigned int idLoggedUser)
{
    IncomeExpense incomeExpense;

    incomeExpense.setOperationId(fileWithIncomesXML.establishNewIncomeIdFromFile());
    incomeExpense.setUserId(idLoggedUser);

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
            incomeExpense.setDate(date);
            break;
        case 'n':
            flag = false;
            date = OperationOnDates::loadAndCheckDate();
            incomeExpense.setDate(date);
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
    incomeExpense.setTypeOfItem(typeOfIncome);

    string amountString = "";
    cout<< "How many is that?" << endl;

    cin >> amountString;
    amountString = AuxillaryMethods::checkComma(amountString);
    float amount = stof(amountString);
    incomeExpense.setAmount(amount);

    incomes.push_back(incomeExpense);
    fileWithIncomesXML.addIncomeToFile(incomeExpense);

    cout << endl << "Your income is added successfully!" << endl << endl;
    system("pause");

}

void BudgetManager::addExpense(unsigned int idLoggedUser)
{
    IncomeExpense incomeExpense;

    incomeExpense.setOperationId(fileWithExpensesXML.establishNewExpenseIdFromFile());
    incomeExpense.setUserId(idLoggedUser);

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
            incomeExpense.setDate(date);
            break;
        case 'n':
            flag = false;
            date = OperationOnDates::loadAndCheckDate();
            incomeExpense.setDate(date);
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
    incomeExpense.setTypeOfItem(typeOfExpense);

    string amountString = "";
    cout<< "How many is that?" << endl;

    amountString = AuxillaryMethods::loadLine();

    amountString = AuxillaryMethods::checkComma(amountString);
    float amount = stof(amountString);
    incomeExpense.setAmount(amount);

    fileWithExpensesXML.addExpenseToFile(incomeExpense);
    expenses.push_back(incomeExpense);

    cout << endl << "Your expense is added successfully!" << endl << endl;
    system("pause");

}

bool compare(IncomeExpense date1, IncomeExpense date2)
{
    return (date1.getDateInt() < date2.getDateInt());
}

void BudgetManager::showBalanceFromCurrentMonth()
{
    int dateInt = 0;
    if (incomes.empty() && expenses.empty())
    {
        cout << "You don't have any incomes or expenses." << endl;
        Sleep(1200);

    }
    else
    {
        //convert dates in vector incomes from string to int:
        for (int i = 0; i < incomes.size(); i++)
        {
            dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
            incomes[i].setDateInt(dateInt);
        }

        //sorting by date from earliest to latest:
        sort(incomes.begin(), incomes.end(), compare);

        int firstDayOfCurrentMonth = 0;
        string currentDate = OperationOnDates::getTodaysDate();
        string firstDay = OperationOnDates::changeCurrentDateToFirstDayOfMonth(currentDate);

        firstDayOfCurrentMonth = OperationOnDates::dateStringToInt(firstDay);

        //printing on screen:
        float sumIncomes = 0;
        bool flag1 = true;
        system("cls");
        if (!incomes.empty())
        {

            cout << "        >>> Balance from current month. <<<" << endl;
            cout << "         Incomes: " << endl;
            cout << "-----------------------------------------------" << endl;
            for (int i = 0; i < incomes.size(); i++)
            {
                if(incomes[i].getDateInt() >= firstDayOfCurrentMonth)
                {
                    cout << endl;
                    cout << "Date:                   " << incomes[i].getDate() << endl;
                    cout << "Item:                   " << incomes[i].getTypeOfItem() << endl;
                    cout << "Amount:                 " << fixed << setprecision(2) << incomes[i].getAmount() << endl;
                    cout << endl;
                    sumIncomes += incomes[i].getAmount();
                    flag1 = false;
                }
            }
            cout << endl;
            if(flag1 == true)
            {
                cout  << "No incomes to show from current month." << endl << endl;
                system("pause");
            }
        }

        //convert dates in vector expenses from string to int:
        for (int i = 0; i < expenses.size(); i++)
        {
            dateInt = OperationOnDates::dateStringToInt(expenses[i].getDate());
            expenses[i].setDateInt(dateInt);
        }

        //sorting by date from earliest to latest:
        sort(expenses.begin(), expenses.end(), compare);

        //printing on screen:
        float sumExpenses = 0;
        bool flag2 = true;
        if (!expenses.empty())
        {
            cout << "         Expenses: " << endl;
            cout << "-----------------------------------------------" << endl;
            for (int i = 0; i < expenses.size(); i++)
            {
                if(expenses[i].getDateInt() >= firstDayOfCurrentMonth)
                {
                    cout << endl;
                    cout << "Date:                   " << expenses[i].getDate() << endl;
                    cout << "Item:                   " << expenses[i].getTypeOfItem() << endl;
                    cout << "Amount:                 " << fixed << setprecision(2) << expenses[i].getAmount() << endl;
                    cout << endl;
                    sumExpenses += expenses[i].getAmount();
                    flag2 = false;
                }
            }
            cout << endl;
            if(flag2 == true)
            {
                cout << "No expenses to show from current month." << endl << endl;
                system("pause");
            }
        }

        if(flag1 == false || flag2 == false)
        {
            cout << endl << "Sum of incomes:                            " << sumIncomes << endl;
            cout << endl << "Sum of expenses:                           " << sumExpenses << endl;
            cout << endl << "Difference between incomes and expenses:   " << sumIncomes - sumExpenses << endl << endl;
            system("pause");
        }
    }
}

void BudgetManager::showBalanceFromPreviousMonth()
{
    int dateInt = 0;
    if (incomes.empty() && expenses.empty())
    {
        cout << "You don't have any incomes or expenses." << endl;
        Sleep(1200);
    }
    else
    {
        //convert dates in vector incomes from string to int:
        for (int i = 0; i < incomes.size(); i++)
        {
            dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
            incomes[i].setDateInt(dateInt);
        }

        //sorting by date from earliest to latest:
        sort(incomes.begin(), incomes.end(), compare);

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
        bool flag1 = true;
        if (!incomes.empty())
        {
            cout << "        >>> Balance from previous month. <<<" << endl;
            cout << "         Incomes: " << endl;
            cout << "-----------------------------------------------" << endl;
            for (int i = 0; i < incomes.size(); i++)
            {
                if(incomes[i].getDateInt() >= firstDayOfPreviousMonth && incomes[i].getDateInt() < firstDayOfCurrentMonth)
                {
                    cout << endl;
                    cout << "Date:                   " << incomes[i].getDate() << endl;
                    cout << "Item:                   " << incomes[i].getTypeOfItem() << endl;
                    cout << "Amount:                 " << fixed << setprecision(2) << incomes[i].getAmount() << endl;
                    cout << endl;
                    sumIncomes += incomes[i].getAmount();
                    flag1 = false;
                }
            }
            cout << endl;
            if(flag1 == true)
            {
                cout << "No incomes to show from previous month." << endl << endl;
                system("pause");
            }
        }

        //convert dates in vector expenses from string to int:
        for (int i = 0; i < expenses.size(); i++)
        {
            dateInt = OperationOnDates::dateStringToInt(expenses[i].getDate());
            expenses[i].setDateInt(dateInt);
        }

        //sorting by date from earliest to latest:
        sort(expenses.begin(), expenses.end(), compare);

        //printing on screen:
        float sumExpenses = 0;
        bool flag2 = true;
        if (!expenses.empty())
        {
            cout << "         Expenses: " << endl;
            cout << "-----------------------------------------------" << endl;
            for (int i = 0; i < expenses.size(); i++)
            {
                if(expenses[i].getDateInt() >= firstDayOfPreviousMonth && expenses[i].getDateInt() < firstDayOfCurrentMonth)
                {
                    cout << endl;
                    cout << "Date:                   " << expenses[i].getDate() << endl;
                    cout << "Item:                   " << expenses[i].getTypeOfItem() << endl;
                    cout << "Amount:                 " << fixed << setprecision(2) << expenses[i].getAmount() << endl;
                    cout << endl;
                    sumExpenses += expenses[i].getAmount();
                    flag2 = false;
                }
            }
            cout << endl;
            if(flag2 == true)
            {
                cout << "No expenses to show from previous month." << endl << endl;
                system("pause");
            }
        }
        if(flag1 == false || flag2 == false)
        {
            cout << endl << "Sum of incomes:                            " << sumIncomes << endl;
            cout << endl << "Sum of expenses:                           " << sumExpenses << endl;
            cout << endl << "Difference between incomes and expenses:   " << sumIncomes - sumExpenses << endl << endl;
            system("pause");
        }
    }
}

void BudgetManager::showBalanceFromSelectedPeriod()
{
    int dateInt = 0;
    string date1 = "";
    string date2 = "";

    if (incomes.empty() && expenses.empty())
    {
        cout << "You don't have any incomes or expenses." << endl;
        Sleep(1200);
    }
    else
    {
        date1 = OperationOnDates::loadAndCheckDate();
        date2 = OperationOnDates::loadAndCheckDate();
        //convert dates in vector incomes from string to int:
        for (int i = 0; i < incomes.size(); i++)
        {
            dateInt = OperationOnDates::dateStringToInt(incomes[i].getDate());
            incomes[i].setDateInt(dateInt);
        }

        //sorting by date from earliest to latest:
        sort(incomes.begin(), incomes.end(), compare);

        int date1Integer = OperationOnDates::dateStringToInt(date1);
        int date2Integer = OperationOnDates::dateStringToInt(date2);

        if (date1Integer >= date2Integer)
        {
            cout << "Invalid dates! Please enter earlier date first!" << endl;
            system("pause");
        }
        else
        {
            //printing on screen:
            system("cls");
            float sumIncomes = 0;
            bool flag1 = true;
            if (!incomes.empty())
            {
                cout << "        >>> Balance from selected period. <<<" << endl;
                cout << "         Incomes: " << endl;
                cout << "-----------------------------------------------" << endl;
                for (int i = 0; i < incomes.size(); i++)
                {
                    if(incomes[i].getDateInt() >= date1Integer && incomes[i].getDateInt() <= date2Integer)
                    {
                        cout << endl;
                        cout << "Date:                   " << incomes[i].getDate() << endl;
                        cout << "Item:                   " << incomes[i].getTypeOfItem() << endl;
                        cout << "Amount:                 " << fixed << setprecision(2) << incomes[i].getAmount() << endl;
                        cout << endl;
                        sumIncomes += incomes[i].getAmount();
                        flag1 = false;
                    }
                }
                cout << endl;
                if(flag1 == true)
                {
                    cout << "No incomes to show from selected time." << endl << endl;
                    system("pause");
                }
            }

            //convert dates in vector expenses from string to int:
            for (int i = 0; i < expenses.size(); i++)
            {
                dateInt = OperationOnDates::dateStringToInt(expenses[i].getDate());
                expenses[i].setDateInt(dateInt);
            }

            //sorting by date from earliest to latest:
            sort(expenses.begin(), expenses.end(), compare);

            //printing on screen:
            float sumExpenses = 0;
            bool flag2 = true;
            if (!expenses.empty())
            {
                cout << "         Expenses: " << endl;
                cout << "-----------------------------------------------" << endl;
                for (int i = 0; i < expenses.size(); i++)
                {
                    if(expenses[i].getDateInt() >= date1Integer && expenses[i].getDateInt() <= date2Integer)
                    {
                        cout << endl;
                        cout << "Date:                   " << expenses[i].getDate() << endl;
                        cout << "Item:                   " << expenses[i].getTypeOfItem() << endl;
                        cout << "Amount:                 " << fixed << setprecision(2) << expenses[i].getAmount() << endl;
                        cout << endl;
                        sumExpenses += expenses[i].getAmount();
                        flag2 = false;
                    }
                }
                cout << endl;
                if(flag2 == true)
                {
                    cout << "No expenses to show from selected time." << endl << endl;
                    system("pause");
                }
            }
            if(flag1 == false || flag2 == false)
            {
                cout << endl << "Sum of incomes:                            " << sumIncomes << endl;
                cout << endl << "Sum of expenses:                           " << sumExpenses << endl;
                cout << endl << "Difference between incomes and expenses:   " << sumIncomes - sumExpenses << endl << endl;
                system("pause");
            }
        }
    }
}
