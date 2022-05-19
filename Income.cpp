#include "Income.h"

using namespace std;

void Income::setAmount(float newAmount)
{
    if (newAmount >= 0)
        amount = newAmount;
}

void Income::setDate(string newDate)
{
    date = newDate;
}

void Income::setTypeOfIncome(string newTypeOfIncome)
{
    typeOfIncome = newTypeOfIncome;
}

void Income::setIncomeId(int newIncomeId)
{
    incomeId = newIncomeId;
}

void Income::setUserId(int newUserId)
{
    userId = newUserId;
}


float Income::getAmount()
{
    return amount;
}

string Income::getDate()
{
    return date;
}

string Income::getTypeOfIncome()
{
    return typeOfIncome;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}
