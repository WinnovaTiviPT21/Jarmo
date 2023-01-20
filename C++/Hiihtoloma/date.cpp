#include <iostream>
#include "date.h"

// Tarkistaa onko päivämäärä oikein
bool Date::isValid()
{
    if (m_day < 1 || m_day > 31)
        return false;
    if (m_month < 1 || m_month > 12)
        return false;
    if ((m_day == 29 && m_month == 2 && kVuosi() == true))
        return true;
    if ((m_day > 28 && m_month == 2) || (m_day > 30 && m_month == 4) || (m_day > 30 && m_month == 6) || (m_day > 30 && m_month == 9) || (m_day > 30 && m_month == 11))
        return false;
    return true;
}

// Tarkistetaan onko kyseessä karkausvuosi
bool Date::kVuosi()
{
    if(m_year % 400 == 0)
        return true;
    else if(m_year % 100 == 0)
        return false;
    else if(m_year % 4 == 0)
        return true;
    return false;
}

// Custom vertailu operaattori (Overloading the comparison operators)
// jota käytetään tarkistamaan onko pvm hiihtoloma
bool operator< (const Date& d1, const Date& d2){
    if(d1.m_year == d2.m_year){
        if (d1.m_month == d2.m_month){
            return d1.m_day <= d2.m_day;
        }
        else{
            return d1.m_month <= d2.m_month;
        }
    }
    else{
        return d1.m_year <= d2.m_year;
    }
}
