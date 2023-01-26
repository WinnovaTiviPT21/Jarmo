#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape{
public:
    float area();
    float perimerer();
};

#endif // TRIANGLE_H
