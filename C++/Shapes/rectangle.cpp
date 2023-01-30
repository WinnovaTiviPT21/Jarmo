#include <iostream>
#include "rectangle.h"
using namespace std;

// Kumpi olisi suositeltavampi tapa kirjoittaa?
// Rectangle::Rectangle(float w, float h) : width(w), height(h) {}
Rectangle::Rectangle(float w, float h){
    m_width = w;
    m_height = h;
}

float Rectangle::area(){
    return m_width * m_height;
}

float Rectangle::perimeter(){
    return 2 * (m_width + m_height);
}

void Rectangle::print(){
    cout << "Suorakulmion pinta-ala on: " << Rectangle::area() << endl;
    cout << "Suorakulmion ymparysmitta on: " << Rectangle::perimeter() << endl;
    cout << endl;
}
