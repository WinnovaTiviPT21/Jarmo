#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

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

    QFile kevo("UtsjokiKevo.csv");
    if (!kevo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream stream(&kevo);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.startsWith("V"))
            continue;
        QStringList values = line.split(QLatin1Char(','), Qt::SkipEmptyParts);
        QDateTime momentInTime;
        momentInTime.setDate(QDate(values[0].toInt(), values[1].toInt() , 15));
        series->append(momentInTime.toMSecsSinceEpoch(), values[2].toDouble());
    }
    kevo.close();

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

    ui->widget->setRenderHint(QPainter::Antialiasing);
    ui->widget->setRubberBand(QChartView::HorizontalRubberBand);
    ui->widget->setChart(chart);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_rain_stateChanged(int arg1)
{

}

