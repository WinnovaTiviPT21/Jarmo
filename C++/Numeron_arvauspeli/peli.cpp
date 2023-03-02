#include <random>
#include "peli.h"

using namespace std;

Peli::Peli()
{

}



int Peli::rngNro()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);

    m_rngNro = distrib(gen);
    return m_rngNro;
}

int Peli::getRngNro()
{
    return m_rngNro;
}

int Peli::setRngNro()
{
    setRngNro();
    return m_rngNro;
}
