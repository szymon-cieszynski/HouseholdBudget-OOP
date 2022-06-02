#ifndef AUXILLARYMETHODS_H
#define AUXILLARYMETHODS_H


#include <iostream>

using namespace std;

class AuxillaryMethods
{
    public:
    static char loadCharacter();
    static string changeFirstLetterToCapitalAndOthersToLower(string text);
    static string loadLine();
    static string floatToString(float amount);
    static string checkComma(string amountString);
};

#endif
