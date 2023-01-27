#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(float l, float h){
    m_length = l;
    m_height = h;
}

float Rectangle::area(){
    return m_height * m_length;
}
float Rectangle::perimeter(){
    return 2 * m_length + 2 * m_height;
}
void Rectangle::print(){
    cout << "Suorakulmion pinta-ala on: " << Rectangle::area() << endl;
    cout << "Suorakulmion ypmarysmitta on: " << Rectangle::perimeter() << endl;
}
