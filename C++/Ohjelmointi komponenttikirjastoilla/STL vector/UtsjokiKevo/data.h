#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Mittaus
{
public:
    QChart *mittaus(int i, std::vector<Data> datavector, QLineSeries *series);
    std::vector<Data> datavector;
    int i = 10;

};

#endif // DATA_H
