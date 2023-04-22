/***************************
** Kahden ympyrän pinta-ala
** Jarmo Vuorinen
** 01.03.2023
**
** Laske sinisen alueen pinta-ala Monte-Carlo simulaatiolla.
** Alusta satunnaislukugeneraattori luvulla 42.
***************************/
#include <iostream>
#include <random>
#include "circle.h"

using namespace std;

int main()
{
    int side = 80;
    float isInside = 0;
    int samples = 1e8;

    mt19937 gen{ 42 };
    uniform_real_distribution<float> distA(0, 80);

    Circle a{40.0, 40.0, 20.0};
    Circle b{32.0, 40.0, 16.2};
    for(int i = 0; i < samples; i++) {
        float x = distA(gen);
        float y = distA(gen);

        if (a.isInside(x,y) && !b.isInside(x,y)) {
            isInside++;
        }
    }

    float areaOfSquare = side * side;
    float areaOfCrescent = isInside/samples * areaOfSquare;
    cout << "Sinisen alueen pinta-ala: " << areaOfCrescent << endl;

    cout << "" << endl;
    return 0;
}
