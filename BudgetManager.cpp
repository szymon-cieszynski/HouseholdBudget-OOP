#include "BudgetManager.h"

using namespace std;

void BudgetManager::addIncome(int idLoggedUser)
{
    Income income;

    income.setIncomeId(establishNewIncomeID());
    income.setUserId(idLoggedUser);

    cout << "Income from today? y/n" << endl;
    char choice = AuxillaryMethods::loadCharacter();

    string date = "";
    if (choice == 'y')
    {
        date = OperationOnDates::getTodaysDate();
        income.setDate(date);
    }
    else
    {
        date = OperationOnDates::loadAndCheckDate();
        income.setDate(date);
    }

    string typeOfIncome = "";
    cout<< "What kind of income is this?" << endl;

    typeOfIncome = AuxillaryMethods::loadLine();
    income.setTypeOfIncome(typeOfIncome);

    float amount = 0;
    cout<< "How many is that?" << endl;

    cin >> amount;
    income.setAmount(amount);

    incomes.push_back(income);

    fileWithIncomesXML.addIncomeToFile(income);

    cout << endl << "Your income is added successfully!" << endl << endl;
    system("pause");

}

int BudgetManager::establishNewIncomeID()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void BudgetManager::addExpense()
{

}

void BudgetManager::showBalanceFromCurrentMonth()
{

}

void BudgetManager::showBalanceFromPreviousMonth()
{

}

void BudgetManager::showBalanceFromSelectedPeriod()
{

}
