#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

class Circle : Ellipse{
    float m_radius;
public:
    Circle(float r);
    float area();
    float perimerer();
};

Circle::Circle(float r){
    m_radius = r;
}

#endif // CIRCLE_H
