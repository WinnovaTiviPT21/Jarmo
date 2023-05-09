#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Mittaus
{
public:
    int i = 1;

    std::vector<Data> datavector;

    QChart *mittaus(int i, std::vector<Data> datavector, QLineSeries *series);
//    QChart *ilman_lampotila(QLineSeries *series);
};

#endif // DATA_H
