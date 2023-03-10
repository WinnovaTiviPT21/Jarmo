#ifndef PELI_H
#define PELI_H

#include <iostream>
#include <random>

class Peli
{

public:
    Peli();

    void startClicked();
    void guessClicked();

    int getRngNro();
    int getDisplay();
    int setDisplay(int&);
    int getCounter();
    std::string getGuide();

    void rngNroChanged();
    void displayChanged();
    void counterChanged();
    void guideChanged();

private:
    int m_rngNro = 0;
    int m_display = 0;
    int m_counter = 0;
    std::string m_guide = "Arvaa luku 0 - 100 väliltä.";
};

#endif // PELI_H
