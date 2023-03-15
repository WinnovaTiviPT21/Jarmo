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
    //float side = 64.8;
    float isInside = 0;
    int samples = 10000000;

    mt19937 gen{ 42 };
    uniform_real_distribution<> distA(0, 40);
    uniform_real_distribution<> distB(0, 32.4);

    Circle a{40.0, 40.0, 20.0};
    Circle b{32.4, 32.4, 16.2};
    for(int i = 0; i < samples; i++) {
        float x = distA(gen);
        float y = distA(gen);

        if (a.isInside(x,y)) {
            isInside++;
        }
    }

    float areaOfSquare = side * side;
    float areaOfCircle = isInside/samples * areaOfSquare;
    cout << "Ympyran pinta-ala " << areaOfCircle << endl;

    cout << "" << endl;
    return 0;
}
