#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

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
    void on_Backspace_clicked();
    void displayUpdate(QString s);

    void on_B1_clicked();

    void on_B0_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_B4_clicked();

    void on_B5_clicked();

    void on_B6_clicked();

    void on_B7_clicked();

    void on_B8_clicked();

    void on_B9_clicked();

    void on_Clear_clicked();

    void on_ClearAll_clicked();

    void on_Plus_clicked();

    void on_Pilkku_clicked();

    void on_Miinus_clicked();

    void on_Jako_clicked();

    void on_Kerto_clicked();

    void on_Onyhtakuin_clicked();

    void on_PlusMiinus_clicked();

    void on_Neliojuuri_clicked();

    void on_x2_clicked();

    void on_YksiKauttaX_clicked();

    void on_MC_clicked();

    void on_MR_clicked();

    void on_MS_clicked();

    void on_Mplus_clicked();

private:
    Ui::MainWindow *ui;

    Calculator m_calculator;
};
#endif // MAINWINDOW_H
