#include <iostream>
#include <cmath>
#include "triangle.h"
using namespace std;

Triangle::Triangle(float b, float h){
    m_base = b;
    m_height = h;
}

float Triangle::area(){
    return m_base * m_height / 2;
}

float Triangle::perimeter(){
    return 2 * sqrt(2 * Triangle::area() / m_base) + m_base;
}

void Triangle::print(){
    cout << "Kolmion pinta-ala on: " << Triangle::area() << endl;
    cout << "Kolmion ymparysmitta on: " << Triangle::perimeter() << endl;
    cout << endl;
}
