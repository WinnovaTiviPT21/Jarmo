#ifndef SHAPE_H
#define SHAPE_H

class Shape{
public:
    virtual float area();
    virtual float perimeter();

    Shape();

    void print();

};

void Shape::print(){

}

#endif // SHAPE_H
