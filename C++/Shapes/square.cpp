#include <iostream>
#include "square.h"
using namespace std;

//Square::Square(float l){
//    m_length = l;
//}

float Square::area(){
    return m_length * m_length;
}

float Square::perimeter(){
    return 4 * m_length;
}

void Square::print(){
    cout << "Nelion pinta-ala on: " << Square::area() << endl;
    cout << "Nelion ypmarysmitta on: " << Square::perimeter() << endl;
}
