#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>

#include <QFile>
#include <QTextStream>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QFile json("dictionary.json");
    if (!json.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream stream(&json);
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.startsWith("{") || line.startsWith("}") || line.endsWith(",")) {
            //ui->listWidget->addItem(line);
            continue;
        }
        QStringList values = line.split(QLatin1Char(':'), Qt::SkipEmptyParts);
    }
    json.close();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{

}

