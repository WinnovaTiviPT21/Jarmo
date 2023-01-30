#include <iostream>
#include <cmath>
#include "ellipse.h"
using namespace std;

Ellipse::Ellipse(float a, float b){
    m_aAkseli = a;
    m_bAkseli = b;
}

float Ellipse::area(){
    return 3.14 * m_aAkseli * m_bAkseli;
}
float Ellipse::perimeter(){
    return M_PI * (3 * (m_aAkseli + m_bAkseli) - sqrt((3 * m_aAkseli + m_bAkseli) * (m_aAkseli + 3 * m_bAkseli)));
}
void Ellipse::print(){
    cout << "Soikion pinta-ala on: " << Ellipse::area() << endl;
    cout << "Soikion ymparysmitta on: " << Ellipse::perimeter() << endl;
    cout << endl;
}
