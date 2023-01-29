#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape{
    float m_base, m_height;
public:
    Triangle(float b, float h);
    float area();
    float perimeter();
    void print();
};

#endif // TRIANGLE_H
