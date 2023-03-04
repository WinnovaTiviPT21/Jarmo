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

void Peli::startClicked()
{
    // std::random_device ei toiminut jostain syystä
    // niin piti sen sijaan käyttää system clockia.
    uniform_int_distribution<> distr(0, 100);
    mt19937 gen {static_cast<unsigned int>(
                    chrono::steady_clock::now().time_since_epoch().count())
                };

    m_rngNro = distr(gen);
    cout << "Arvottu nro on: " << m_rngNro << endl;
}

void Peli::guessClicked()
{
    cout << "Annoit nron: " << m_display << endl;
    if (m_display == m_rngNro) {
        cout << "Voitit pelin" << endl;
    }
}

