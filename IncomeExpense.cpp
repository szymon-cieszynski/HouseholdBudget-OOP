#include "IncomeExpense.h"

using namespace std;

//Setters:
void IncomeExpense::setAmount(float newAmount)
{
    if (newAmount >= 0)
        amount = newAmount;
}

void IncomeExpense::setDate(string newDate)
{
    date = newDate;
}

void IncomeExpense::setTypeOfItem(string newTypeOfItem)
{
    item = newTypeOfItem;
}

void IncomeExpense::setOperationId(int newOperationId)
{
    if (newOperationId >= 0)
    operationId = newOperationId;
}

void IncomeExpense::setUserId(int newUserId)
{
    if (newUserId >= 0)
    userId = newUserId;
}

void IncomeExpense::setDateInt(int newDateInt)
{
    if (newDateInt >= 0)
    dateInt = newDateInt;
}


//Getters:
float IncomeExpense::getAmount()
{
    return amount;
}

string IncomeExpense::getDate()
{
    return date;
}

string IncomeExpense::getTypeOfItem()
{
    return item;
}

int IncomeExpense::getOperationId()
{
    return operationId;
}

int IncomeExpense::getUserId()
{
    return userId;
}

int IncomeExpense::getDateInt()
{
    return dateInt;
}
