/*
 *
 * Utsjoki, Kevo
 *
 * Tehtävänanto 2 tiedosto(a)
 *
 * Tee sovellus, joka näyttää oheisen tiedoston mittaukset graafina. Oheinen zip-tiedosto sisältää projektin alun.
 * Mittaustiedossa on puuttuvia mittauksia. Puuttuviin mittaustietoihin voidaan käyttää oletusarvoa 0.
 *
 * Kerro palautuksessa GitHub kansion nimi.
 *
 * Mittaustiedot ladattu Ilmatieteen laitoksen avoimen datan latauspalvelusta maaliskuussa 2022. Lisenssiehdot Creative Commons Nimeä 4.0.
 *
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>


#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QFile UtsjokiKevo("UtsjokiKevo.csv");
    if (!UtsjokiKevo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream stream(&UtsjokiKevo);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.startsWith("V"))
            continue;
        // Jos tyhjä niin antaa automaattisesti arvoksi 0.
        QStringList values = line.split(QLatin1Char(',')/*, Qt::SkipEmptyParts*/);

        Data datastruct;
        datastruct.v = values[0].toDouble();
        datastruct.kk = values[1].toDouble();
        datastruct.pv = values[2].toDouble();
        //datastruct.klo = values[3].toStdString();
        //datastruct.aikavyohyke = values[4].toStdString();
        datastruct.sademaara = values[5].toDouble();
        datastruct.lumensyvyys = values[6].toDouble();
        datastruct.ilman_lampotila = values[7].toDouble();
        datastruct.maanpintaminimi = values[8].toDouble();
        datastruct.ylin_lampotila = values[9].toDouble();
        datastruct.alin_lampotila = values[10].toDouble();

        m.datavector.push_back (datastruct);
    }
    UtsjokiKevo.close();

    ui->checkBox_rain->setCheckState(Qt::Unchecked);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_rain_stateChanged(int arg1)
{
    if (ui->checkBox_rain->isChecked()) {
        QLineSeries *series = new QLineSeries();
        QChart *chart = m.sademaara(m.datavector, series);

        ui->widget->setRenderHint(QPainter::Antialiasing);
        ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
        ui->widget->setChart(chart);

        ui->checkBox_snow->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureAir->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureGround->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMin->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMax->setCheckState(Qt::Unchecked);

        ui->widget->setVisible(true);
    } else {
        ui->widget->setVisible(false);
    }
}


void MainWindow::on_checkBox_snow_stateChanged(int arg1)
{
    if (ui->checkBox_snow->isChecked()) {
        QLineSeries *series = new QLineSeries();
        QChart *chart = m.lumensyvyys(m.datavector, series);

        ui->widget->setRenderHint(QPainter::Antialiasing);
        ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
        ui->widget->setChart(chart);

        ui->checkBox_rain->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureAir->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureGround->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMin->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMax->setCheckState(Qt::Unchecked);

        ui->widget->setVisible(true);
    }   else {
        ui->widget->setVisible(false);
    }
}



void MainWindow::on_checkBox_temperatureAir_stateChanged(int arg1)
{
    if (ui->checkBox_temperatureAir->isChecked()) {
        QLineSeries *series = new QLineSeries();
        QChart *chart = m.ilman_lampotila(m.datavector, series);

        ui->widget->setRenderHint(QPainter::Antialiasing);
        ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
        ui->widget->setChart(chart);

        ui->checkBox_rain->setCheckState(Qt::Unchecked);
        ui->checkBox_snow->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureGround->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMin->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMax->setCheckState(Qt::Unchecked);

        ui->widget->setVisible(true);
    }   else {
        ui->widget->setVisible(false);
    }
}


void MainWindow::on_checkBox_temperatureGround_stateChanged(int arg1)
{
    if (ui->checkBox_temperatureGround->isChecked()) {
        QLineSeries *series = new QLineSeries();
        QChart *chart = m.maanpintaminimi(m.datavector, series);

        ui->widget->setRenderHint(QPainter::Antialiasing);
        ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
        ui->widget->setChart(chart);

        ui->checkBox_rain->setCheckState(Qt::Unchecked);
        ui->checkBox_snow->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureAir->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMin->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMax->setCheckState(Qt::Unchecked);

        ui->widget->setVisible(true);
    }   else {
        ui->widget->setVisible(false);
    }
}


void MainWindow::on_checkBox_temperatureMin_stateChanged(int arg1)
{
    if (ui->checkBox_temperatureMin->isChecked()) {
        QLineSeries *series = new QLineSeries();
        QChart *chart = m.alin_lampotila(m.datavector, series);

        ui->widget->setRenderHint(QPainter::Antialiasing);
        ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
        ui->widget->setChart(chart);

        ui->checkBox_rain->setCheckState(Qt::Unchecked);
        ui->checkBox_snow->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureAir->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureGround->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMax->setCheckState(Qt::Unchecked);

        ui->widget->setVisible(true);
    }   else {
        ui->widget->setVisible(false);
    }
}


void MainWindow::on_checkBox_temperatureMax_stateChanged(int arg1)
{
    if (ui->checkBox_temperatureMax->isChecked()) {
        QLineSeries *series = new QLineSeries();
        QChart *chart = m.ylin_lampotila(m.datavector, series);

        ui->widget->setRenderHint(QPainter::Antialiasing);
        ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
        ui->widget->setChart(chart);

        ui->checkBox_rain->setCheckState(Qt::Unchecked);
        ui->checkBox_snow->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureAir->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureGround->setCheckState(Qt::Unchecked);
        ui->checkBox_temperatureMin->setCheckState(Qt::Unchecked);

        ui->widget->setVisible(true);
    }   else {
        ui->widget->setVisible(false);
    }
}

