#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    float amount;
    string date;
    string typeOfExpense;
    int expenseId;
    int userId;
    string amountString;

public:
    void setAmount(float newAmount);
    void setDate(string newDate);
    void setTypeOfExpense(string newTypeOfExpense);
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setAmountString(string newAmountString);

    float getAmount();
    string getDate();
    string getTypeOfExpense();
    int getExpenseId();
    int getUserId();
    string getAmountString();
};

#endif
