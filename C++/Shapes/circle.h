#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

class Circle : public Ellipse{
    float m_radius;
public:
    Circle(float r);
    float area();
    float perimerer();
    void print();
};


void Circle::print(){

}
#endif // CIRCLE_H
