#include <iostream>
#include "square.h"

float Square::area(){
    return m_length * m_length;
}

float Square::perimerer(){
    return 4 * m_length;
}
