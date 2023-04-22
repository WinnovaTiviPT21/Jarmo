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
    // Instantiate a 32-bit Mersenne Twister
    mt19937 rng{};
    // rajaa rng arvojen alueen
    uniform_int_distribution die1{1, 5};
    uniform_int_distribution die2{1, 100};
    uniform_int_distribution die3{1, 100};

    vector<shared_ptr<Shape>> shapes;

    // luo x määrän sattumanvaraisia instansseja ja antaa niille sattumanvaraiset arvot
    for(unsigned int i = 0; i < 10000; i++){
        // rng muuttujia, saavat joka kierrolla uudet arvot
        int x = die1(rng);
        int y = die2(rng);
        int z = die3(rng);

        // muodon valinta die1:n "arpoman" luvun mukaan
        if(x == 1 && y != z){
            shared_ptr<Shape> shape(new Rectangle (y, z));
            shapes.push_back(shape);
            //shape->print();
        }
        if((x == 2) || (x == 1 && y == z)){
            shared_ptr<Shape> shape(new Square (y));
            shapes.push_back(shape);
            //shape->print();
        }
        if(x == 3 && y != z){
            shared_ptr<Shape> shape(new Ellipse (y, z));
            shapes.push_back(shape);
            //shape->print();
        }
        if((x == 4) || (x == 3 && y == z)){
            shared_ptr<Shape> shape(new Circle (y));
            shapes.push_back(shape);
            //shape->print();
        }
        if(x == 5){
            shared_ptr<Shape> shape(new Triangle (y, z));
            shapes.push_back(shape);
            //shape->print();
        }
    }

    // etsii suurimman muodon pinta-alan mukaan
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
