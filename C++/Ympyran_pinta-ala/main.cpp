/********************
** Ympyrän pinta-ala
** Jarmo Vuorinen
** 01.03.2023
********************/

#include <iostream>
#include <random>

using namespace std;

int main()
{
    // Laske Monte Carlo simulaatiolla oheisen ympyrän pinta-ala. Eli arvot satunnaisesti pisteen neliön
    // sisälle ja testaat, onko piste ympyrän sisällä vai ei. Testaaminen onnistuu Pythagoraan lauseella.
    // Käytä luokkaa std::uniform_real_distribution. Alusta satunnaislukugeneraattori luvulla 42.

    /*
    ** Opettajan ratkaisu
    **
    ** class Circle {
    ** publec:
    **   float m_x;
    **   float m_y;
    **   float m_radius;
    **
    **   bool isInside(float x, float y);
    ** }
    **
    ** bool Circle::isInside(float x, float y) {
    **   float local_x = x - m_x;
    **   float local_y = y - m_y;
    **
    **   return local_x * local_x + local_y * local_y <= m_radius * m_radius;
    **
    ** int side = 20;
    ** mt19937 gen{ 42 };
    ** uniform_real_distribution<> dist(0, 10);
    **
    ** float isInside = 0;
    ** int samples = 10000000
    **
    ** Circle c{15.0, 10.0, 5.0}
    ** for(int i = 0; i < samples; i++) {
    **   float x = dist(generator)
    **   float y = dist(generator)
    **
    **   if (c.isInside(x,y)) {
    **      isInside++;
    **   }
    ** }
    **
    ** float aseaOfSquare = side * side;
    ** float areaOfCircle = isInside/samples * areaOfSquare;
    ** cout << "Ympyrän pinta-ala " << areaOfCiscle << endl;
    ** return 0;
    */

    const int r = 5;           // säde
    const int piste = 1000000; // pisteiden määrä
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
