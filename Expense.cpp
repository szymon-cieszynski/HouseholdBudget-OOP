#include "Expense.h"

using namespace std;


//Setters:
void Expense::setAmount(float newAmount)
{
    if (newAmount >= 0)
        amount = newAmount;
}

void Expense::setDate(string newDate)
{
    date = newDate;
}

void Expense::setTypeOfExpense(string newTypeOfExpense)
{
    typeOfExpense = newTypeOfExpense;
}

void Expense::setExpenseId(int newExpenseId)
{
    if (newExpenseId >= 0)
    expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId)
{
    if (newUserId >= 0)
    userId = newUserId;
}

void Expense::setDateInt(int newDateInt)
{
    if (newDateInt >= 0)
    dateInt = newDateInt;
}

//Getters:
float Expense::getAmount()
{
    return amount;
}

string Expense::getDate()
{
    return date;
}

string Expense::getTypeOfExpense()
{
    return typeOfExpense;
}

int Expense::getExpenseId()
{
    return expenseId;
}

int Expense::getUserId()
{
    return userId;
}

int Expense::getDateInt()
{
    return dateInt;
}
