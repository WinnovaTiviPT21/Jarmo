#include <iostream>
#include "circle.h"

using namespace std;

float Circle::area(){
  return 3.14 * m_radius * m_radius;
}

float Circle::perimerer(){
    return 2 * 3.14 * m_radius;
}
