#include <iostream>
#include "circle.h"
using namespace std;

Circle::Circle(float r){
    m_radius = r;
}

float Circle::area(){
    return 3.14 * m_radius * m_radius;
}

float Circle::perimeter(){
    return 2 * 3.14 * m_radius;
}

void Circle::print(){
    cout << "Ympyran pinta-ala on: " << Circle::area() << endl;
    cout << "Ympyran ypmarysmitta on: " << Circle::perimeter() << endl;
}
