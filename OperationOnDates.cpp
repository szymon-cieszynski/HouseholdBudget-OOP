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

        if(date[4] == '-' && date[7] == '-' /*&& date[0] == '2'*/ /*&& date[5]!='12'*/ && date.size() == 10)
        {
            if(date[0]!='2') //czy nie bedzie potrzebnych wiecej warunkow? np. to do maks ostatniego dnia beziacego miesiaca
            {
                cout << "Earliest year has to be from 2000 year!"  << endl;
                //break;
            }
            else
            {
                return date;
            }

        }
        else cout << "Incorrect format of date!" << endl;
    }
    //return date;
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
