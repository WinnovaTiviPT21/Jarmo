#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Mittaus
{
public:
    std::vector<Data> datavector;

    QChart *mittaus(std::vector<Data> datavector, QLineSeries *series);
//    QChart *ilman_lampotila(QLineSeries *series);
};

#endif // DATA_H
