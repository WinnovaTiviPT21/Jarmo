#ifndef DATE_H
#define DATE_H
#include <string>

// Opettajan esimerkki
struct /*class*/ Date
{
    int day;
    int month;
    int year;

    std::string hiihtoLoma;

    bool isValid();
    bool kVuosi();
};

#endif // DATE_H
