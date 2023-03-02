#ifndef PELI_H
#define PELI_H

#include <QObject>

class Peli : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int rngNro READ getRngNro WRITE setRngNro NOTIFY rngNroChanged)

public:
    Peli();
//    Peli(QObject *parent = nullptr) : QObject(parent) {}
//    Peli(QObject *parent) : QObject(parent) {}
//    Peli(QObject *parent = 0);
//    ~Peli();

public slots:
    int rngNro();
    int getRngNro();
    int setRngNro();

signals:
    void rngNroChanged();

private:
    int m_rngNro;
};



#endif // PELI_H
