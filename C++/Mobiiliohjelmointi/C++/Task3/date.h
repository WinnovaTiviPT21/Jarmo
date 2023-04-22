#ifndef DATE_H
#define DATE_H
#include <string>

// The only difference between a struct and class in C++ is the default accessibility of member variables and methods.
// In a struct they are public; in a class they are private.
class Date
{ public:
    int day;
    int month;
    int year;

    bool isValid();
    bool kVuosi();

    std::string birthDate;
    std::string hiringDate;

    Date(){

    }

    Date(int m_day, int m_month, int m_year){
        day = m_day;
        month = m_month;
        year = m_year;
    }

    friend bool operator < (const Date& d1, const Date& d2);
};

#endif // DATE_H
