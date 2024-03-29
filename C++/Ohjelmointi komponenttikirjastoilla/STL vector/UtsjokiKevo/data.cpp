#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <vector>

QChart *Mittaus::sademaara(std::vector<Data> datavector, QLineSeries *series)
{
    /*
    for(Data row : datavector) {

        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));

        if (input == 1) {
            series->append(momentInTime.toMSecsSinceEpoch(), row.sademaara);
        }
        if (input == 2) {
            series->append(momentInTime.toMSecsSinceEpoch(), row.lumensyvyys);
        }
        if (input == 3) {
            series->append(momentInTime.toMSecsSinceEpoch(), row.ilman_lampotila);
        }
        if (input == 4) {
            series->append(momentInTime.toMSecsSinceEpoch(), row.alin_lampotila);
        }
        if (input == 5) {
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

    chart->setAnimationOptions(QChart::AllAnimations);
    */

    for(Data row : datavector) {
        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));
        series->append(momentInTime.toMSecsSinceEpoch(), row.sademaara);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Sateen määrä 1962 - 2014");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("d MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Sademäärä (mm)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);

    return chart;
}

QChart *Mittaus::lumensyvyys(std::vector<Data> datavector, QLineSeries *series)
{
    for(Data row : datavector) {
        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));
        series->append(momentInTime.toMSecsSinceEpoch(), row.lumensyvyys);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Lumen määrä 1962 - 2014");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("d MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Lumensyvyys (cm)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);

    return chart;
}

QChart *Mittaus::ilman_lampotila(std::vector<Data> datavector, QLineSeries *series)
{
    for(Data row : datavector) {
        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));
        series->append(momentInTime.toMSecsSinceEpoch(), row.ilman_lampotila);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Ilman lämpötila 1962 - 2014");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("d MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Lämpötila (degC)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);

    return chart;
}

QChart *Mittaus::maanpintaminimi(std::vector<Data> datavector, QLineSeries *series)
{
    for(Data row : datavector) {
        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));
        series->append(momentInTime.toMSecsSinceEpoch(), row.maanpintaminimi);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Maanpinnan lämpötila 1962 - 2014");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("d MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Lämpötila (degC)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);

    return chart;
}

QChart *Mittaus::alin_lampotila(std::vector<Data> datavector, QLineSeries *series)
{
    for(Data row : datavector) {
        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));
        series->append(momentInTime.toMSecsSinceEpoch(), row.alin_lampotila);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Alin lämpötila 1962 - 2014");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("d MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Lämpötila (degC)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);

    return chart;
}

QChart *Mittaus::ylin_lampotila(std::vector<Data> datavector, QLineSeries *series)
{
    for(Data row : datavector) {
        QDateTime momentInTime;
        momentInTime.setDate(QDate(row.v, row.kk, row.pv));
        series->append(momentInTime.toMSecsSinceEpoch(), row.ylin_lampotila);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Ylin lämpötila 1962 - 2014");

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("d MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Lämpötila (degC)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setAnimationOptions(QChart::AllAnimations);

    return chart;
}
