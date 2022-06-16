#ifndef FILEWITHINCOMESXML_H
#define FILEWITHINCOMESXML_H

#include <iostream>
#include <vector>

#include "IncomeExpense.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

class FileWithIncomesXML
{
public:
    void addIncomeToFile(IncomeExpense incomeExpense);
    std::vector <IncomeExpense> loadIncomesFromFile(int idLoggedUser);
    int establishNewIncomeIdFromFile();
};


#endif
