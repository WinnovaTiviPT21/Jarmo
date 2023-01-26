#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape{
//    float m_hight;
//    float m_length;
public:
//    Rectangle(float l, float h);
    float area();
    float perimeter();
};

#endif // RECTANGLE_H
