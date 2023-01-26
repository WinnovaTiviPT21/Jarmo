#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square : public Rectangle{
    float m_length;
public:
    Square(float l);
    float area();
    float perimeter();
    void print();
};



#endif // SQUARE_H
