#ifndef AUXILLARYMETHODS_H
#define AUXILLARYMETHODS_H


#include <iostream>

class AuxillaryMethods
{
public:
    static char loadCharacter();
    static std::string changeFirstLetterToCapitalAndOthersToLower(std::string text);
    static std::string loadLine();
    static std::string floatToString(float amount);
    static std::string checkComma(std::string amountString);
};

#endif
