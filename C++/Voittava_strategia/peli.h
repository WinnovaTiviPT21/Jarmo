#ifndef PELI_H
#define PELI_H

#include <QObject>
#include <iostream>
#include <random>

class Peli : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rngNro READ getRngNro NOTIFY rngNroChanged)
    Q_PROPERTY(int display READ getDisplay WRITE setDisplay NOTIFY displayChanged)
    Q_PROPERTY(int counter READ getCounter NOTIFY counterChanged)
    Q_PROPERTY(QString guide READ getGuide NOTIFY guideChanged)

public:
    Peli();

//public slots:
    void startClicked();
    void guessClicked();

    int getRngNro();
    int getDisplay();
    int setDisplay(int&);
    int getCounter();
    std::string getGuide();

//signals:
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
