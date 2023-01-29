#include <iostream>
#include "square.h"
using namespace std;

// Parempia tapoja kirjoittaa/toteuttaa?
Square::Square(float s) : Rectangle(s, s) {
    m_side = s;
}

float Square::area(){
    return m_side * m_side;
}

float Square::perimeter(){
    return 4 * m_side;
}

void Square::print(){
    cout << "Nelion pinta-ala on: " << Square::area() << endl;
    cout << "Nelion ypmarysmitta on: " << Square::perimeter() << endl;
}
