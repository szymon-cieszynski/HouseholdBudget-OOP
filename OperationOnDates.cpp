#include "OperationOnDates.h"
#include <string>
#include <time.h>

string OperationOnDates::loadAndCheckDate()
{
    string date = "";

    while(true)
    {
        cout << endl << "Type date in format YYYY-MM-DD" << endl;
        getline (cin, date);

        bool lapyear = isLeapYear(date);

        string daysOfMonthString = date.substr (8,2);
        int daysOfMonth = stoi(daysOfMonthString);

        /*cout << daysOfMonth << endl;
        system("pause");*/

        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int currentYear = aTime->tm_year + 1900;
        int currentMonth = aTime->tm_mon + 1;

        string yearString = date.substr (0,4);
        int year = stoi(yearString);

        string monthString = date.substr (5,2);
        int month = 0;
        month = stoi(monthString);

        if(date[4] == '-' && date[7] == '-' && date.size() == 10)
        {
            if(date[0]!='2')
            {
                cout << endl << "Earliest year has to be from 2000 year!"  << endl;
                //break;
            }
            else if (month > currentMonth || currentYear < year )
            {
                cout << endl << "You can enter income this month at the latest."  << endl;
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

    // cout<< "This month has: " << days << " days" << endl;
}

bool OperationOnDates::isLeapYear(string date)
{
    int year = 0;
    string yearString = date.substr (0,4);
    year = stoi(yearString);

    bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leapyear == true)
    {
        // cout<< "This year is leapyear." << endl;
        return true;
    }
    else
    {
        //cout<< "This year is NOT leapyear." << endl;
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
