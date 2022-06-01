#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    float amount;
    int dateInt;
    string date;
    string typeOfExpense;
    int expenseId;
    int userId;
    string amountString;

public:
    Expense (float amount = 0, int dateInt = 0, string date = "", string typeOfExpense = "", int expenseId = 0, int userId = 0, string amountString = "" )
    {

    }
    void setAmount(float newAmount);
    void setDate(string newDate);
    void setTypeOfExpense(string newTypeOfExpense);
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setAmountString(string newAmountString);
    void setDateInt(int newDateInt);

    float getAmount();
    string getDate();
    string getTypeOfExpense();
    int getExpenseId();
    int getUserId();
    string getAmountString();
    int getDateInt();
};

#endif
