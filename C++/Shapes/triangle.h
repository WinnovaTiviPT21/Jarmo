#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape{
    float m_side1, m_side2, m_side3, s;
public:
    Triangle(float s1, float s2, float s3);
    float area();
    float perimeter();
    void print();
};

#endif // TRIANGLE_H
