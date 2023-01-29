#include <iostream>
#include <cmath>
#include "triangle.h"
using namespace std;

Triangle::Triangle(float s1, float s2, float s3){
    m_side1 = s1;
    m_side1 = s2;
    m_side1 = s3;
}

float Triangle::area(){
    float s = (m_side1 + m_side2 + m_side3) / 2;
    return sqrt(s * (s - m_side1) * (s - m_side2) * (s - m_side3));
}

float Triangle::perimeter(){
    return m_side1 + m_side2 + m_side3;
}

void Triangle::print(){
    cout << "Kolmion pinta-ala on: " << Triangle::area() << endl;
    cout << "Kolmion ypmarysmitta on: " << Triangle::perimeter() << endl;
}
