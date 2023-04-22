#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int main()
{
    // Olioiden luominen (luokka, nimi, arvot parametreille),
    // olioiden luominen ja käyttäminen poikkeaa C#:sta,
    // tämä aiheutti sekaannusta ja hämmennystä tehtävässä.
    Date start(20, 2, 2023);
    Date end(26, 2, 2023);

    // Date pvm; vaatii default(tyhjän) constructorin toimiakseen,
    // saa parametrit ja niille arvot käyttäjän syötteestä.
    Date pvm;

    // Ohjelma pyytää käyttäjältä pvm niin kauan kunnes saa validin pvm:n.
    while (!pvm.isValid()) {
        char c;
        cout << "Kirjoita paivamaara: ";

        // Tässä pvm(olio) saa käytettävät parametrit m_day, m_month ja m_year,
        // atribuutit on määritetty jo luokassa, ja ne saa käyttäjän syötteestä niille arvot.
        cin >> pvm.m_day >> c >> pvm.m_month >> c >> pvm.m_year;
    }

    // Päivämäärien verailua käyttämällä "custom" operaattoria (määritetty date.cpp:ssä).
    if(start < pvm && pvm < end) {
        cout << "Kyseessa on hiihtoloma." << endl;
    }
    else
        cout << "Kyseessa ei ole hiihtoloma." << endl;

    cout << endl;
    return 0;
}
