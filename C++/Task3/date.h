#ifndef DATE_H
#define DATE_H

// The only difference between a struct and class in C++ is the default accessibility of member variables and methods.
// In a struct they are public; in a class they are private.
struct /*class*/ Date
{ /*public*/
    int day;
    int month;
    int year;

    bool isValid();
    bool kVuosi();

//    std::string bDate;

    // ???
    friend bool operator < (Date d1, Date d2);
};

#endif // DATE_H
