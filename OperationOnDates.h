#ifndef OPERATIONONDATES_H
#define OPERATIONONDATES_H

#include <iostream>

using namespace std;

class OperationOnDates
{
private:
    static bool isLeapYear(string date);
    static int checkDaysOfMonths(bool lapyear, string date);

public:
    static string loadAndCheckDate();
    static string getTodaysDate();
    static int dateStringToInt(string date);
    static string changeCurrentDateToFirstDayOfMonth(string date);
    static string changeCurrentDateToFirstDayOfPreviousMonth(string date);

};

#endif
