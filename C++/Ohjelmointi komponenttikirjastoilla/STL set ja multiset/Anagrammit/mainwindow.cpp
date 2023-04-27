#include "mainwindow.h"
#include "qlistwidget.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <map>

#include <QFile>
#include <QTextStream>
#include <QListWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QFile json("dictionary.json");
//    if (!json.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        return;
//    }

//    QTextStream stream(&json);
//    while (!stream.atEnd()) {
//        QString line = stream.readLine();
//        if (line.startsWith("{") || line.startsWith("}")) {
//            continue;
//        }
//        QStringList values = line.split(QLatin1Char(':'));
//        mymap.insert({values[0], values[1]});
//        ui->listWidget->addItem(values[0]);
//    }
//    json.close();

    QFile file_obj("dictionary.json");
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug() << "Failed to open " << "dictionary.json";
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();

    auto json_doc = QJsonDocument::fromJson(json_bytes);

    if(json_doc.isNull()){
        qDebug() << "Failed to create JSON doc.";
        exit(2);
    }
    if(!json_doc.isObject()){
        qDebug() << "JSON is not an object.";
        exit(3);
    }

    QJsonObject json_obj = json_doc.object();

    if(json_obj.isEmpty()){
        qDebug() << "JSON object is empty.";
        exit(4);
    }

    QVariantMap json_map = json_obj.toVariantMap();

    qDebug() << json_map[0].toString();
    qDebug() << json_map["name"].toString();
    qDebug() << json_map["enemy"].toString();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{

}

