#include "data.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <vector>

QChart* Mittaus::mittaus(int input, std::vector<Data> datavector, QLineSeries *series)
{
    for(Data row : datavector) {
        if (input == 0) {
            QDateTime momentInTime;
            momentInTime.setDate(QDate(row.v, row.kk, row.pv));
            series->append(momentInTime.toMSecsSinceEpoch(), row.sademaara);
        }
        if (input == 1) {
            QDateTime momentInTime;
            momentInTime.setDate(QDate(row.v, row.kk, row.pv));
            series->append(momentInTime.toMSecsSinceEpoch(), row.lumensyvyys);
        }
        if (input == 2) {
            QDateTime momentInTime;
            momentInTime.setDate(QDate(row.v, row.kk, row.pv));
            series->append(momentInTime.toMSecsSinceEpoch(), row.ilman_lampotila);
        }
        if (input == 3) {
            QDateTime momentInTime;
            momentInTime.setDate(QDate(row.v, row.kk, row.pv));
            series->append(momentInTime.toMSecsSinceEpoch(), row.alin_lampotila);
        }
        if (input == 4) {
            QDateTime momentInTime;
            momentInTime.setDate(QDate(row.v, row.kk, row.pv));
            series->append(momentInTime.toMSecsSinceEpoch(), row.ylin_lampotila);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Insert title here");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Tieteellinen teksti tähän");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    return chart;
}
