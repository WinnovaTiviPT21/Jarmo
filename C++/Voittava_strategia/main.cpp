#include <QCoreApplication>
#include <iostream>
#include <random>
#include <chrono>
#include "peli.h"
#include "sim.h"
using namespace std;

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}

int main()
{
    //Peli startClicked;
    Sim sim;
    sim.run();

    cout << "" << endl;
    return 0;
}
