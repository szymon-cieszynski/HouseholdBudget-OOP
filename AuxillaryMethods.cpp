#include "AuxillaryMethods.h"
#include <sstream>
#include <algorithm>
#include <sstream>
#include <windows.h>
#include<string>

using namespace std;

char AuxillaryMethods::loadCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "That is not single character. Type again." << endl;
    }
    return character;
}

string AuxillaryMethods::changeFirstLetterToCapitalAndOthersToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxillaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string AuxillaryMethods::floatToString(float amount)
{
    ostringstream ss;
    ss << amount;
    string str = ss.str();
    return str;
}


string AuxillaryMethods::checkComma(string amountString)
{
    double amount;
    size_t dot_position;
    if (amountString.find(',') != string::npos)
    {
        dot_position = amountString.find(',');
        amountString[dot_position] = '.';
    }

    return amountString;
}
