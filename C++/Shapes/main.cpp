#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

using namespace std;

int main()
{
    // Generating random numbers using Mersenne Twister
    mt19937 rng{}; // Instantiate a 32-bit Mersenne Twister
    uniform_int_distribution die1{1, 5}; // Noppa 1 rajoittaa arvot 1-5 välille
    uniform_int_distribution die2{1, 100}; // Noppa 2 rajoittaa arvot 1-100 välille

    vector<shared_ptr<Shape>> shapes;

    // luo x määrän sattumanvaraisia instansseja ja antaa niille sattumanvaraiset arvot
    for(unsigned int i = 0; i < 10000; i++){
        int x = die1(rng);
        int y = die2(rng);
        if(x == 1){
            shared_ptr<Shape> shape(new Rectangle (y, y));
            shapes.push_back(shape);
            //shape->print();
        }
        if(x == 2){
            shared_ptr<Shape> shape(new Square (y));
            shapes.push_back(shape);
            //shape->print();
        }
        if(x == 3){
            shared_ptr<Shape> shape(new Ellipse (y, y));
            shapes.push_back(shape);
            //shape->print();
        }
        if(x == 4){
            shared_ptr<Shape> shape(new Circle (y));
            shapes.push_back(shape);
            //shape->print();
        }
        if(x == 5){
            shared_ptr<Shape> shape(new Triangle (y, y));
            shapes.push_back(shape);
            //shape->print();
        }
        //cout << y << endl;
    }

    // etsii suurimman shapen arean mukaan
    shared_ptr<Shape> largest = shapes[0];
    for(unsigned int i = 0; i < shapes.size(); i++){
        shared_ptr<Shape> s = shapes[i];
        if(s->area() > largest->area()){
            largest = s;
        }
    }

    // tulostaa suurimman shapen tiedot
    cout << "Pinta-alaltaan suurin shape on: "  << endl;
    cout << "--------------------------------------" << endl;
    largest->print();
    cout << "--------------------------------------" << endl;

    return 0;
}
