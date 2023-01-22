#ifndef DATE_H
#define DATE_H

class Date
{ public:
    int m_day;
    int m_month;
    int m_year;

    bool isValid();
    bool kVuosi();

    /* Default consturctor, ei saa(tarvitse) mitään parametreja.
     * Luokassa voi olla useita eri consturctoreita kunhan eivät
     * ole identtisiä rakenteeltaan! */
    Date(){
        m_day = 0;      // Tulevien atribuuttien alustus,
        m_month = 0;    // ei pakollista, mutta suositeltavaa.
        m_year = 0;
    }

    // Consturctor jolle on asetettu parametrit
    Date(int day, int month, int year){
        m_day = day;
        m_month = month;
        m_year = year;
    }

    /* Tämä tarvitaan "custom" operaattorin toimiseksi main ohjelmassa,
     * tämä tuo lainauksen custom operaattorista Date luokkaan. Ohjelma
     * toimii myös, jos vertailuoperaattori kirjoitetaan suoraan luokan
     * sisälle, mutta myös silloin se tarvitsee friend etuliitteen,
     * tämän syytä en täysin osaa selittää. */
    friend bool operator< (const Date& d1, const Date& d2);
};

#endif // DATE_H
