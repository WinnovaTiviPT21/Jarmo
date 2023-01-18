#include <iostream>
#include "date.h"
// using namespace std; // Ei tarvita?

// Opettajan esimerkistä jatkettua
bool Date::isValid()
{
    if (day < 1 || day > 31)
        return false;
    if (month < 1 || month > 12)
        return false;
    if ((day == 29 && month == 2 && kVuosi() == true))
        return true;
    if ((day > 28 && month == 2) || (day > 30 && month == 4) || (day > 30 && month == 6) || (day > 30 && month == 9) || (day > 30 && month == 11))
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

