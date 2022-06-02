#ifndef FILEWITHEXPENSESXML_H
#define FILEWITHEXPENSESXML_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

using namespace std;

class FileWithExpensesXML
{
private:

public:
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int idLoggedUser);
    int establishNewExpenseIdFromFile();


};


#endif
