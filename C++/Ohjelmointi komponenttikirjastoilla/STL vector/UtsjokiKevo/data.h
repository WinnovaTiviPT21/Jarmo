#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include "ui_mainwindow.h"

struct Data {
    std::string aikavyohyke, klo;
    int v, kk, pv, lumensyvyys;
    double sademaara, ilman_lampotila, maanpintaminimi, ylin_lampotila, alin_lampotila;
};

class Mittaus
{
public:
    std::vector<Data> datavector;

    QChart *sademaara(std::vector<Data> datavector, QLineSeries *series);
    QChart *lumensyvyys(std::vector<Data> datavector, QLineSeries *series);
    QChart *ilman_lampotila(std::vector<Data> datavector, QLineSeries *series);
    QChart *maanpintaminimi(std::vector<Data> datavector, QLineSeries *series);
    QChart *alin_lampotila(std::vector<Data> datavector, QLineSeries *series);
    QChart *ylin_lampotila(std::vector<Data> datavector, QLineSeries *series);
};

#endif // DATA_H
