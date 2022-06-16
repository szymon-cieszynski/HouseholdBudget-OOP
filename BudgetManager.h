#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm> //for sort
#include <windows.h>

#include "IncomeExpense.h"
#include "AuxillaryMethods.h"
#include "OperationOnDates.h"
#include "FileWithIncomesXML.h"
#include "FileWithExpensesXML.h"

class BudgetManager
{
public:
    BudgetManager(unsigned int idLoggedUser):
        ID_OF_LOGGED_USER(idLoggedUser),
        fileWithIncomesXML(),
        fileWithExpensesXML(),
        incomes(fileWithIncomesXML.loadIncomesFromFile(ID_OF_LOGGED_USER)),
        expenses(fileWithExpensesXML.loadExpensesFromFile(ID_OF_LOGGED_USER))
    {};

    void addIncome(unsigned int idLoggedUser);
    void addExpense(unsigned int idLoggedUser);
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();

private:
    const unsigned int ID_OF_LOGGED_USER;
    FileWithIncomesXML fileWithIncomesXML;
    FileWithExpensesXML fileWithExpensesXML;
    std::vector <IncomeExpense> incomes;
    std::vector <IncomeExpense> expenses;
};


#endif
