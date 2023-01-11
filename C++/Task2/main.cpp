#include <iostream>
using namespace std;

// Opettajan esimerkki
struct Date
{
    int day;
    int month;
    int year;

    bool isValid();
    bool kVuosi();
};

// Opettajan esimerkki
bool Date::isValid()
{
    if (day < 1)
        return false;
    if (month < 1 || month > 12)
        return false;
    return true;
}

// Omaa koodia
// Tarkistetaan onko kyseessä karkausvuosi
bool Date::kVuosi()
{
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return true;
    else if(year % 4 == 0)
        return true;
    return false;
}

int main()
{
    // Opettajan esimerkki
    Date pvml;

    cout << "Anna pvm: ";
    char c;
    cin >> pvml.day >> c >> pvml.month >> c >> pvml.year;

    cout << "Annoit: " << pvml.day << c << pvml.month << c << pvml.year << endl;
    if (pvml.isValid() == false){
        cout << "Pvm on virheellinen!" << endl;
    }

    // Oma koodi
    if (pvml.kVuosi() == true){
        cout << "Kyseessa on karkausvuosi" << endl;
    }

    return 0;
}
