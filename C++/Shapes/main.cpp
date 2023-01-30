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

// Luo instansseja sattumanvaraisesti 10000 kappaletta.
// Käytä std::vector:ia ja std::shared_ptr:ia.
// Hae pinta-alaltaan suurin shape ja tulosta sen tiedot.
int main()
{
    mt19937 rng{}; // Instantiate a 32-bit Mersenne Twister
    uniform_int_distribution die1{1, 5};
    uniform_int_distribution die2{1, 100};

    vector<shared_ptr<Shape>> shapes;

    for(unsigned int i = 0; i < shapes.size(); i++){
        shared_ptr<Shape> shape = shapes[i];
        shape->print();
    }

    for(unsigned int i = 0; i < 10; i++){
        int x = die1(rng);
        int y = die2(rng);
        if(x == 1){
            shared_ptr<Shape> shape(new Rectangle (y, y));
            shapes.push_back(shape);
            shape->print();
        }
        if(x == 2){
            shared_ptr<Shape> shape(new Square (y));
            shapes.push_back(shape);
            shape->print();
        }
        if(x == 3){
            shared_ptr<Shape> shape(new Ellipse (y, y));
            shapes.push_back(shape);
            shape->print();
        }
        if(x == 4){
            shared_ptr<Shape> shape(new Circle (y));
            shapes.push_back(shape);
            shape->print();
        }
        if(x == 5){
            shared_ptr<Shape> shape(new Triangle (y, y));
            shapes.push_back(shape);
            shape->print();
        }
    }

    shared_ptr<Shape> s;

    shared_ptr<Shape> largest = shapes[0];
    for(unsigned int i = 0; i < shapes.size(); i++){
        shared_ptr<Shape> s = shapes[i];
        if(s->area() < largest->area()){
            largest = s;
        }
    }

    cout << "Pinta-alaltaan suurin shape: " << s->area() << endl;

    /*
    shared_ptr<Shape> shape1(new Rectangle (10, 20));
    shapes.push_back(shape1);
    shape1->print();

    shared_ptr<Shape> shape2(new Square (30));
    shapes.push_back(shape2);
    shape2->print();

    shared_ptr<Shape> shape3(new Ellipse (10, 20));
    shapes.push_back(shape3);
    shape3->print();

    shared_ptr<Shape> shape4(new Circle (10));
    shapes.push_back(shape4);
    shape4->print();

    shared_ptr<Shape> shape5(new Triangle (10, 20));
    shapes.push_back(shape5);
    shape5->print();

    cout << "--------------------------------------" << endl;

        // Print a bunch of random numbers
        for (int count{ 1 }; count <= 40; ++count)
        {
            // cout << rng() << '\t'; // generate a random number
            cout << die1(rng) << '\t';

            // If we've printed 5 numbers, start a new row
            if (count % 5 == 0)
                cout << '\n';
        }

    cout << "--------------------------------------" << endl;

    // rng testausta, oletin että shape 6 ja 7, sekä tulostukset saisivat samat arvot,
    // mutta olinki väärässä, mitä tämä johtuu, miksi ne saa eri arvot?
    // Ilmeisesti muistaa mikä arvo on viimeksi antanut ja antaa seuraavan.
    shared_ptr<Shape> shape6(new Rectangle (die2(rng), die2(rng)));
    shapes.push_back(shape6);
    shape6->print();

    shared_ptr<Shape> shape7(new Rectangle (die2(rng), die2(rng)));
    shapes.push_back(shape7);
    shape7->print();

    cout << die2(rng) << endl;
    cout << die2(rng) << endl;
    cout << die2(rng) << endl;
    */

    return 0;
}
