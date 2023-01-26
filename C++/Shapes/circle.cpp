#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle(float r){
    m_radius = r;
}

float Circle::area(){
  return 3.14 * m_radius * m_radius;
}

float Circle::perimerer(){
    return 2 * 3.14 * m_radius;
}
