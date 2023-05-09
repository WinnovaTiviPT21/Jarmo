#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();


private slots:
  void on_checkBox_rain_stateChanged(int arg1);

  void on_checkBox_snow_stateChanged(int arg1);

  void on_checkBox_temperatureAir_stateChanged(int arg1);

  void on_checkBox_temperatureGround_stateChanged(int arg1);

  void on_checkBox_temperatureMin_stateChanged(int arg1);

  void on_checkBox_temperatureMax_stateChanged(int arg1);

private:
  Ui::MainWindow *ui;
  Mittaus m;

};
#endif // MAINWINDOW_H
