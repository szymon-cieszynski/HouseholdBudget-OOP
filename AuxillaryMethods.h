#ifndef AUXILLARYMETHODS_H
#define AUXILLARYMETHODS_H


#include <iostream>

using namespace std;

class AuxillaryMethods
{
    public:
    /*static string konwerjsaIntNaString(int liczba); //robimy statycznie zeby dzialalo w metodzie z PlikZUzytkownikami i PlikZAdresatami
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int konwersjaStringNaInt(string liczba);*/

    static char loadCharacter();
    static string changeFirstLetterToCapitalAndOthersToLower(string text);
    static string loadLine();
    static string floatToString(float amount);
    static string checkComma(string amountString);
    //static double stringToFloat(string amountString);
    /*static int wczytajLiczbeCalkowita();*/


};

#endif
