#ifndef OPERATIONONDATES_H
#define OPERATIONONDATES_H

#include <iostream>

class OperationOnDates
{
public:
    static std::string loadAndCheckDate();
    static std::string getTodaysDate();
    static int dateStringToInt(std::string date);
    static std::string changeCurrentDateToFirstDayOfMonth(std::string date);
    static std::string changeCurrentDateToFirstDayOfPreviousMonth(std::string date);

private:
    static bool isLeapYear(std::string date);
    static int checkDaysOfMonths(bool lapyear, std::string date);

};

#endif
