#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    float amount;
    int dateInt;
    string date;
    string typeOfIncome;
    int incomeId;
    int userId;
    string amountString;

public:
    Income (float amount = 0, int dateInt = 0, string date = "", string typeOfIncome = "", int incomeId = 0, int userId = 0, string amountString = "" )
    {

    }
    void setAmount(float newAmount);
    void setDate(string newDate);
    void setTypeOfIncome(string newTypeOfIncome);
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setAmountString(string newAmountString);
    void setDateInt(int newDateInt);

    float getAmount();
    string getDate();
    string getTypeOfIncome();
    int getIncomeId();
    int getUserId();
    string getAmountString();
    int getDateInt();
};

#endif
