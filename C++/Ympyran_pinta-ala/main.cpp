/********************
** Ympyrän pinta-ala
** Jarmo Vuorinen
** 03.01.2023
********************/

#include <iostream>
#include <random>

using namespace std;

int main()
{
    // Laske Monte Carlo simulaatiolla oheisen ympyrän pinta-ala. Eli arvot satunnaisesti pisteen neliön
    // sisälle ja testaat, onko piste ympyrän sisällä vai ei. Testaaminen onnistuu Pythagoraan lauseella.
    // Käytä luokkaa std::uniform_real_distribution. Alusta satunnaislukugeneraattori luvulla 42.

    const int r = 5;           // säde
    const int piste = 10000000; // pisteiden määrä
    float ympyran_sisalla = 0; // laskee pisteet ympyrän sisällä

    mt19937 gen{ 42 };
    uniform_real_distribution<> dis(-5, 5);

    for (int i = 0; i <= piste; ++i) {
        float x = dis(gen), y = dis(gen);
        if (x * x + y * y <= r * r) {
            ympyran_sisalla++;
        }
    }

    float melkein_pi = ympyran_sisalla / piste * 4;

    cout << "Piin arvio on: " << melkein_pi << endl;
    cout << "Ympyran pinta-ala on arviolta noin: " << melkein_pi * r * r << "\n\n";

    return 0;
}
