#ifndef INCOMEEXPENSE_H
#define INCOMEEXPENSE_H

#include <iostream>

class IncomeExpense
{
public:
    Income (float amount = 0, int dateInt = 0, std::string date = "", std::string item = "", int operationId = 0, int userId = 0)
    {};

    void setAmount(float newAmount);
    void setDate(std::string newDate);
    void setTypeOfItem(std::string newTypeOfItem);
    void setOperationId(int newOperationId);
    void setUserId(int newUserId);
    void setDateInt(int newDateInt);

    float getAmount();
    std::string getDate();
    std::string getTypeOfItem();
    int getOperationId();
    int getUserId();
    int getDateInt();

private:
    float amount;
    int dateInt;
    std::string date;
    std::string item;
    int operationId;
    int userId;
};

#endif
