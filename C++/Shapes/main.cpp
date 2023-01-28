#include <iostream>
#include <vector>
#include <memory>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
using namespace std;

int main()
{
    vector<shared_ptr<Shape>> shapes;

    for(unsigned int i = 0; i < shapes.size(); i++){
        shared_ptr<Shape> shape = shapes[i];
        shape->print();
    }

    shared_ptr<Shape> shape1(new Circle (10));
    shapes.push_back(shape1);
    shape1->print();

    cout << endl;

    shared_ptr<Shape> shape2(new Rectangle (10, 20));
    shapes.push_back(shape2);
    shape2->print();

    cout << endl;

    shared_ptr<Shape> shape3(new Square (30));
    shapes.push_back(shape3);
    shape3->print();

    cout << "----------------------------" << endl;
    return 0;
}
