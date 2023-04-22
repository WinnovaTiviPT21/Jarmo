#include <QCoreApplication>
#include <iostream>
#include <random>
#include <chrono>
#include "sim.h"
using namespace std;

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}

int main()
{
    Sim sim;

    sim.run1();
    sim.run2();

    cout << "" << endl;
    return 0;
}
