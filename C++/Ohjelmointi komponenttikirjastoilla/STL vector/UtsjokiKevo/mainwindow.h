#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Data {
    std::string aikavyohyke, klo;
    int v, kk, pv, lumensyvyys;
    float sademaara, ilman_lampotila, ylin_lampotila, alin_lampotila;
};

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();




private slots:
  void on_checkBox_rain_stateChanged(int arg1);


private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
