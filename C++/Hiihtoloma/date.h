#ifndef DATE_H
#define DATE_H
#include <string>

// Opettajan esimerkki
class Date
{ public:
    int day;
    int month;
    int year;

    std::string hLoma;

    bool isValid();
    bool kVuosi();
};

#endif // DATE_H
