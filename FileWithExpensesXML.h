#ifndef FILEWITHEXPENSESXML_H
#define FILEWITHEXPENSESXML_H

#include <iostream>
#include <vector>

#include "IncomeExpense.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

class FileWithExpensesXML
{
public:
    void addExpenseToFile(IncomeExpense incomeExpense);
    std::vector <IncomeExpense> loadExpensesFromFile(int idLoggedUser);
    int establishNewExpenseIdFromFile();

};


#endif
