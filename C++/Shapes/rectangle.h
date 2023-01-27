#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape{
    float m_length;
    float m_height;
public:
    Rectangle(float l, float h);
    float area();
    float perimeter();
    void print();
};

#endif // RECTANGLE_H
