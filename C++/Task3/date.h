#ifndef DATE_H
#define DATE_H

// Opettajan esimerkki
class /*struct*/ Date
{
    int day;
    int month;
    int year;

    bool isValid();
    bool kVuosi();

    // friend bool operator < (Date d1, Date d2);
};

#endif // DATE_H
