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

//#include <QtWidgets/QCheckBox>

#include <iostream>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    Mittaus m;

    QLineSeries *series = new QLineSeries();

    /*

    QFile sunSpots(":sun");
    if (!sunSpots.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream stream(&sunSpots);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.startsWith("#") || line.startsWith(":"))
            continue;
        QStringList values = line.split(QLatin1Char(' '), Qt::SkipEmptyParts);
        QDateTime momentInTime;
        momentInTime.setDate(QDate(values[0].toInt(), values[1].toInt() , 15));
        series->append(momentInTime.toMSecsSinceEpoch(), values[2].toDouble());
    }
    sunSpots.close();

    */

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

    /*
    ESIMERRKI

    m_aaCheckBox = new QCheckBox();
    m_animationsCheckBox = new QCheckBox();
    m_animationsCheckBox->setCheckState(Qt::Checked);
    m_legendCheckBox = new QCheckBox();

    connect(m_aaCheckBox, &QCheckBox::toggled, this, &MainWidget::updateChartSettings);
    connect(m_animationsCheckBox, &QCheckBox::toggled, this, &MainWidget::updateChartSettings);
    connect(m_legendCheckBox, &QCheckBox::toggled, this, &MainWidget::updateChartSettings);
    */

    QChart *chart = m.mittaus(m.datavector, series);

    ui->widget->setRenderHint(QPainter::Antialiasing);
    ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
    ui->widget->setChart(chart);

//    chart = m.ilman_lampotila(series);
//    ui->widget->setRenderHint(QPainter::Antialiasing);
//    ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
//    ui->widget->setChart(chart);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_rain_stateChanged(int arg1)
{

}

