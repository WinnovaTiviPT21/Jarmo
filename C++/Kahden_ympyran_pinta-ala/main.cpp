/***************************
** Kahden ympyrän pinta-ala
** Jarmo Vuorinen
** 01.03.2023
***************************/

#include <iostream>
#include <random>

using namespace std;

int main()
{
    // Laske sinisen alueen pinta-ala Monte-Carlo simulaatiolla.
    // Alusta satunnaislukugeneraattori luvulla 42.

    const float rSin = 20.0;
    const float rVal = 16.2;
    const int piste = 1000000;
    float sinisen_sisalla = 0;
    float valkoisen_sisalla = 0;

    mt19937 gen{ 42 };
    uniform_real_distribution<> disSin(-20, 20);
    uniform_real_distribution<> disVal(-16.2, 16.2);

    for (int i = 0; i <= piste; ++i) {
        float xSin = disSin(gen), ySin = disSin(gen);
        float xVal = disVal(gen), yVal = disVal(gen);

        if (xSin * xSin + ySin * ySin <= rSin * rSin) {
            sinisen_sisalla++;
        }
        if (xVal * xVal + yVal * yVal <= rVal * rVal) {
            valkoisen_sisalla++;
        }
    }

    float melkein_pi_sin = sinisen_sisalla / piste * 4;
    float melkein_pi_val = valkoisen_sisalla / piste * 4;

    cout << "Sinisen ympyran pinta-ala on arviolta noin: " << melkein_pi_sin * rSin * rSin << endl;
    cout << "Valkoisen ympyran pinta-ala on arviolta noin: " << melkein_pi_val * rVal * rVal << endl;
    cout << "\n";

    return 0;
}
