#ifndef SHAPE_H
#define SHAPE_H

class Shape{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;

    Shape();

    virtual void print() = 0;

};

/*
void Shape::print(){

}
*/

#endif // SHAPE_H
