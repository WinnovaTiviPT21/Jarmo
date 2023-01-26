#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape{
public:
    float area();
    float perimeter();
    void print();
};



#endif // ELLIPSE_H
