#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm> //for sort

#include "Income.h"
#include "Expense.h"
#include "AuxillaryMethods.h"
#include "OperationOnDates.h"
#include "FileWithIncomesXML.h"
#include "FileWithExpensesXML.h"

using namespace std;

class BudgetManager
{
private:
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomesXML fileWithIncomesXML;
    FileWithExpensesXML fileWithExpensesXML;

    int establishNewIncomeIdFromFile();
    int establishNewExpenseIdFromFile();
    //const int ID_OF_LOGGED_USER;
    //OperationOnDates operationOnDates;

public:
    /*BudgetManager(int idLoggedUser) : ID_OF_LOGGED_USER(idLoggedUser)
    {

    };*/

    void addIncome(int idLoggedUser);
    void addExpense(int idLoggedUser);
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
    vector <Income> loadIncomesFromFile(int idLoggedUser);
    vector <Expense> loadExpensesFromFile(int idLoggedUser);

    void showAllIncomes();
    void showAllExpenses();
};


#endif
