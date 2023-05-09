/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QChartView *widget;
    QSplitter *splitter;
    QCheckBox *checkBox_rain;
    QCheckBox *checkBox_snow;
    QCheckBox *checkBox_temperatureAir;
    QCheckBox *checkBox_temperatureGround;
    QCheckBox *checkBox_temperatureMin;
    QCheckBox *checkBox_temperatureMax;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1102, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QChartView(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 911, 541));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(940, 10, 151, 152));
        splitter->setOrientation(Qt::Vertical);
        checkBox_rain = new QCheckBox(splitter);
        checkBox_rain->setObjectName(QString::fromUtf8("checkBox_rain"));
        checkBox_rain->setChecked(true);
        splitter->addWidget(checkBox_rain);
        checkBox_snow = new QCheckBox(splitter);
        checkBox_snow->setObjectName(QString::fromUtf8("checkBox_snow"));
        splitter->addWidget(checkBox_snow);
        checkBox_temperatureAir = new QCheckBox(splitter);
        checkBox_temperatureAir->setObjectName(QString::fromUtf8("checkBox_temperatureAir"));
        splitter->addWidget(checkBox_temperatureAir);
        checkBox_temperatureGround = new QCheckBox(splitter);
        checkBox_temperatureGround->setObjectName(QString::fromUtf8("checkBox_temperatureGround"));
        splitter->addWidget(checkBox_temperatureGround);
        checkBox_temperatureMin = new QCheckBox(splitter);
        checkBox_temperatureMin->setObjectName(QString::fromUtf8("checkBox_temperatureMin"));
        splitter->addWidget(checkBox_temperatureMin);
        checkBox_temperatureMax = new QCheckBox(splitter);
        checkBox_temperatureMax->setObjectName(QString::fromUtf8("checkBox_temperatureMax"));
        splitter->addWidget(checkBox_temperatureMax);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1102, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(checkBox_rain, SIGNAL(toggled(bool)), widget, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox_rain->setText(QCoreApplication::translate("MainWindow", "Rain", nullptr));
        checkBox_snow->setText(QCoreApplication::translate("MainWindow", "Snow", nullptr));
        checkBox_temperatureAir->setText(QCoreApplication::translate("MainWindow", "Temperature Air", nullptr));
        checkBox_temperatureGround->setText(QCoreApplication::translate("MainWindow", "Temperature Ground", nullptr));
        checkBox_temperatureMin->setText(QCoreApplication::translate("MainWindow", "Temperature Min", nullptr));
        checkBox_temperatureMax->setText(QCoreApplication::translate("MainWindow", "Temperatire Max", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
