#include "OperationOnDates.h"
#include <string>
#include <time.h>

string OperationOnDates::loadAndCheckDate()
{
    string date = "";

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int currentYear = aTime->tm_year + 1900;
    int currentMonth = aTime->tm_mon + 1;

    while (true)
    {
        cout << endl << "Type date in format YYYY-MM-DD" << endl;
        getline (cin, date);

        if(date[4] == '-' && date[7] == '-' && date.size() == 10 )
        {
            bool lapyear = isLeapYear(date);

            string daysOfMonthString = date.substr (8,2);
            int daysOfMonth = stoi(daysOfMonthString);

            string yearString = date.substr (0,4);
            int typedYear = stoi(yearString);

            string monthString = date.substr (5,2);
            int typedMonth = stoi(monthString);
            if(date[0]!='2')
            {
                cout << endl << "Earliest year has to be from 2000 year!"  << endl;
            }
            else if (typedMonth > 12)
            {
                cout << endl << "Incorrect month!"  << endl;
            }
            else if (typedMonth > currentMonth && typedYear >= currentYear || typedYear > currentYear )
            {
                cout << endl << "You can enter value this month at the latest."  << endl;
            }
            else if (daysOfMonth > checkDaysOfMonths(lapyear, date))
            {
                cout << endl << "Incorrect days of typed month!"  << endl;
            }
            else
            {
                return date;
            }
        }
        else cout << "Incorrect format of date!" << endl;
    }
}

int OperationOnDates::checkDaysOfMonths(bool lapyear, string date)
{
    int days = 0;
    int month = 0;

    string monthString = date.substr (5,2);
    month = stoi(monthString);


    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return days = 30;
    }
    else if (month == 2)
    {
        if (lapyear == false)
        {
            return days = 28;
        }
        else
        {
            return days = 29;
        }
    }
    else
        return days = 31;
}

bool OperationOnDates::isLeapYear(string date)
{
    int year = 0;
    string yearString = date.substr (0,4);
    year = stoi(yearString);

    bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leapyear == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string OperationOnDates::getTodaysDate()
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    string yearString = to_string(year);
    string monthString = to_string(month);
    string dayString = to_string(day);
    if(monthString.size() == 1)
    {
        string zero = "0";
        monthString.insert(0, zero);
    }

    if(dayString.size() == 1)
    {
        string zero = "0";
        dayString.insert(0, zero);
    }

    string date = yearString + '-' + monthString + '-' + dayString;

    return date;
}

int OperationOnDates::dateStringToInt(string date)
{
    int dateInt = 0;
    size_t dash_position;

    for(int i = 0 ; i < date.size() ; i++)
    {
        if (date.find('-') != string::npos)
        {
            dash_position = date.find('-');
            date.erase(dash_position, 1);
        }
    }
    dateInt = stoi(date);
    return dateInt;
}

string OperationOnDates::changeCurrentDateToFirstDayOfMonth(string date)
{
    string firstDay = date.replace(8, 2, "01");
    return firstDay;
}

string OperationOnDates::changeCurrentDateToFirstDayOfPreviousMonth(string date)
{

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int  previousMonth = aTime->tm_mon;
    if (previousMonth == 0) previousMonth = 12;
    string previousMonthString = to_string(previousMonth);


    if(previousMonthString.size() == 1)
    {
        string zero = "0";
        previousMonthString.insert(0, zero);
    }
    string firstDay = date.replace(8, 2, "01");
    firstDay = date.replace(5, 2, previousMonthString);

    return firstDay;
}
