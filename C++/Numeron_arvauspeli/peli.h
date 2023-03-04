#ifndef PELI_H
#define PELI_H

#include <QObject>
#include <random>

class Peli : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rngNro READ getRngNro NOTIFY rngNroChanged)
    Q_PROPERTY(int display READ getDisplay WRITE setDisplay NOTIFY displayChanged)

    int counter = 10;

public:
    Peli();

public slots:
    void startClicked();
    void guessClicked();

    int getRngNro();
    int getDisplay();
    int setDisplay(int&);

signals:
    void rngNroChanged();
    void displayChanged();

private:
    int m_rngNro = 0;
    int m_display = 0;
};

#endif // PELI_H
