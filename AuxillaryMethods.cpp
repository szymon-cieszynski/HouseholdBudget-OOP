#include "AuxillaryMethods.h"
#include <sstream>
#include <algorithm>
#include <sstream>
#include <windows.h>
#include<string>

using namespace std;

/*string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}*/

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

/*int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string input = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}*/
