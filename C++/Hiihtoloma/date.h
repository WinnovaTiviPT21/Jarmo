#ifndef DATE_H
#define DATE_H

class Date
{ public:
    int m_day;
    int m_month;
    int m_year;

    bool isValid();
    bool kVuosi();

    // Default consturctor, ei tarvitse saada mitään arvoja
    Date(){
        m_day = 0; // Arvojen alustus, ei pakollinen, mutta suositeltavaa
        m_month = 0;
        m_year = 0;
    }

    Date(int day, int month, int year){
        m_day = day;
        m_month = month;
        m_year = year;
    }

    friend bool operator< (const Date& d1, const Date& d2);
};

#endif // DATE_H
