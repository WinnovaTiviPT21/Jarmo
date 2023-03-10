#include <iostream>
#include <random>
#include <chrono>
#include "peli.h"
using namespace std;

Peli::Peli()
{

}

int Peli::getRngNro()
{
    return m_rngNro;
}

int Peli::getDisplay()
{
    return m_display;
}

int Peli::setDisplay(int& display)
{
    if (m_display != display) {
        m_display = display;
    }
    return m_display;
}

int Peli::getCounter()
{
    return m_counter;
}

string Peli::getGuide()
{
    return m_guide;
}

void Peli::startClicked()
{
    // std::random_device ei toiminut jostain syystä
    // niin piti sen sijaan käyttää system clockia.
    uniform_int_distribution<> distr(0, 100);
    mt19937 gen {static_cast<unsigned int>(
                    chrono::steady_clock::now().time_since_epoch().count())
                };

    m_rngNro = distr(gen);
    m_counter = 10;
    m_guide = "Arvaa luku 0 - 100 väliltä.";

    cout << "Yrityksia jaljella : " << m_counter << endl;
    //cout << "Arvottu nro on: " << m_rngNro << endl;

    emit guideChanged();
    emit counterChanged();
}

void Peli::guessClicked()
{
    if (m_display < m_rngNro)
    {
        m_guide = "Oikea numero on enemmän";
        m_counter--;
    }
    if (m_display > m_rngNro)
    {
        m_guide = "Oikea numero on vähemmän";
        m_counter--;
    }

    emit guideChanged();
    emit counterChanged();
}

