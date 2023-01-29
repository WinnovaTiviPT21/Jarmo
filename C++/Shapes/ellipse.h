#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape{
    float m_aAkseli, m_bAkseli;
public:
    Ellipse(float a, float b);
    float area();
    float perimeter();
    void print();
};

#endif // ELLIPSE_H
