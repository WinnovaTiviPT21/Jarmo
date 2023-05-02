#include "mainwindow.h"
#include "qlistwidget.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <map>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Avataan json tiedosto
    QFile file_obj("dictionary.json");
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug() << "Failed to open " << "dictionary.json";
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll(); // Luetaan koko json yhteen stringiin
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

    json_map = json_obj.toVariantMap();

    for (QVariantMap::Iterator it = json_map.begin(); it != json_map.end(); it++) {
        ui->listWidget->addItem(it.key());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->label_2->clear();

    QString input_txt = ui->textEdit->toPlainText();

    for (QVariantMap::Iterator it = json_map.begin(); it != json_map.end(); it++) {
        QString str = it.key();

        if (input_txt == str.left(input_txt.length())) {
            ui->listWidget->addItem(it.key());
            //ui->listWidget_2->selectedItems();
            //ui->listWidget_2->scrollToItem();
            //ui->listWidget->findItems(it.key(), Qt::MatchStartsWith);
            //break;
        }
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_2->clear();

    QString str1 = item->text();

    QVariantMap::Iterator it = json_map.find(str1);
    if (it != json_map.end()){
        ui->label_2->setText(it.value().toString());
    }

    for (QVariantMap::Iterator it2 = json_map.begin(); it2 != json_map.end(); it2++){
        QString str2 = it2.key();

        if (it.key() != it2.key()) {
            str1.remove(' ').remove('-');
            str2.remove(' ').remove('-');
            sort(str1.begin(), str1.end());
            sort(str2.begin(), str2.end());

            if (str1 == str2) {
                ui->listWidget_2->addItem(it2.key());
            }
        }
    }
}

void MainWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    QVariantMap::iterator it = json_map.find(item->text());;
    if (it != json_map.end()){
        ui->label_2->setText(it.value().toString());
    }
}

