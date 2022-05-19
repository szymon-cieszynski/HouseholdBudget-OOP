#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxillaryMethods.h"
#include "OperationOnDates.h"
#include "FileWithIncomesXML.h"

using namespace std;

class BudgetManager
{
private:
    vector <Income> incomes;
    FileWithIncomesXML fileWithIncomesXML;
    int establishNewIncomeID();
    //const int ID_OF_LOGGED_USER;
    //OperationOnDates operationOnDates;

public:
    /*BudgetManager(int idLoggedUser) : ID_OF_LOGGED_USER(idLoggedUser)
    {

    };*/

    void addIncome(int idLoggedUser);
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
};


#endif
