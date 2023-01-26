#include <iostream>
#include "square.h"

Square::Square(float l){
    m_length = l;
}

float Square::area(){
    return m_length * m_length;
}

float Square::perimerer(){
    return 4 * m_length;
}
