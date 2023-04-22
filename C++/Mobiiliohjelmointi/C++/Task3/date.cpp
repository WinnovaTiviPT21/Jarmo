#include <iostream>
#include "date.h"

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

bool Date::kVuosi()
{
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    return false;
}

bool operator < (const Date& d1, const Date& d2){
    if(d1.year == d2.year){
        if (d1.month == d2.month){
            return d1.day < d2.day;
        }
        else{
            return d1.month < d2.month;
        }
    }
    else{
        return d1.year < d2.year;
    }
}
