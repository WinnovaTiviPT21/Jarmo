#ifndef DATE_H
#define DATE_H

// Opettajan esimerkki
struct /*class*/ Date
{
    int day;
    int month;
    int year;

    bool isValid();
    bool kVuosi();
};

#endif // DATE_H
