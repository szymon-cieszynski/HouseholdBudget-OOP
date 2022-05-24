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

    string amountString = "";
    cout<< "How many is that?" << endl;

    amountString = AuxillaryMethods::loadLine();

    //float amount = AuxillaryMethods::checkComma(amountString);
    amountString = AuxillaryMethods::checkComma(amountString);
    income.setAmountString(amountString);

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

vector <Income> BudgetManager::loadIncomesFromFile(int idLoggedUser)
{
    incomes = fileWithIncomesXML.loadIncomesFromFile(idLoggedUser);
    return incomes;
}

void BudgetManager::showAllIncomes()
{
    for (int i = 0; i < incomes.size(); i++)
    {
        /*cout<< incomes.size() << endl;
        system("pause");*/
        cout << incomes[i].getIncomeId() << endl;
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getTypeOfIncome() << endl;
        cout << incomes[i].getAmount() << endl;
        system("pause");
    }
}
