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

    QVariantMap json_map = json_obj.toVariantMap();

    for (QVariantMap::Iterator it = json_map.begin(); it != json_map.end(); it++) {
        mymap.insert({it.key(), it.value()});
    }

    for (map<QString, QVariant>::iterator it = mymap.begin(); it != mymap.end(); it++){
        ui->listWidget->addItem(it->first);
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

    bool notfound = true;
    for (map<QString, QVariant>::iterator it = mymap.begin(); it != mymap.end(); it++){
        int charsfound = 0;

        for (int i = 0; i < input_txt.length(); i++) {
            if (input_txt[i] == it->first[i] && it->first.length() >= input_txt.length()) {
                charsfound++;
            } else {
                break;
            }
        }

        if (charsfound == input_txt.length()) {
            ui->listWidget->addItem(it->first);
            notfound = false;
        }
    }

    if (notfound == true) {
        ui->listWidget->clear();
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->listWidget_2->clear();

    QString str1 = item->text();

    map<QString, QVariant>::iterator it = mymap.find(str1);;
    if (it != mymap.end()){
        ui->label_2->setText(it->second.toString());
    }

    sort(str1.begin(), str1.end());
    for (map<QString, QVariant>::iterator it2 = mymap.begin(); it2 != mymap.end(); it2++){
        QString str2 = it2->first;
        sort(str2.begin(), str2.end());

        bool match = false;
        if (str1.length() == str2.length()) {
            for(int i = 0; i < str1.length(); i++) {
                if (str1[i] != str2[i]) {
                    match = false;
                    break;
                } else {
                    match = true;
                }
            }
        }

        if (match == true) {
            ui->listWidget_2->addItem(it2->first);
        }
    }
}

