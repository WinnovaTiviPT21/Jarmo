#ifndef SHAPE_H
#define SHAPE_H

class Shape{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual void print() = 0;

};

#endif // SHAPE_H
