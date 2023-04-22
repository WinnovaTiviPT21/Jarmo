#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(&m_calculator, &Calculator::displayChanged,
            this, &MainWindow::displayUpdate);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayUpdate(QString s) {
    ui->lineEdit->setText(s);
}


void MainWindow::on_B0_clicked()
{
    m_calculator.digitClicked("0");
}


void MainWindow::on_B1_clicked()
{
    m_calculator.digitClicked("1");
}


void MainWindow::on_B2_clicked()
{
    m_calculator.digitClicked("2");
}


void MainWindow::on_B3_clicked()
{
    m_calculator.digitClicked("3");
}


void MainWindow::on_B4_clicked()
{
    m_calculator.digitClicked("4");
}


void MainWindow::on_B5_clicked()
{
    m_calculator.digitClicked("5");
}


void MainWindow::on_B6_clicked()
{
    m_calculator.digitClicked("6");
}


void MainWindow::on_B7_clicked()
{
    m_calculator.digitClicked("7");
}


void MainWindow::on_B8_clicked()
{
    m_calculator.digitClicked("8");
}


void MainWindow::on_B9_clicked()
{
    m_calculator.digitClicked("9");
}


void MainWindow::on_Backspace_clicked()
{
    m_calculator.backspaceClicked();
}


void MainWindow::on_Clear_clicked()
{
    m_calculator.clear();
}


void MainWindow::on_ClearAll_clicked()
{
    m_calculator.clearAll();
}


void MainWindow::on_Plus_clicked()
{
    m_calculator.additiveOperatorClicked(Calculator::Addition);
}


void MainWindow::on_Pilkku_clicked()
{
    m_calculator.pointClicked();
}


void MainWindow::on_Miinus_clicked()
{
    m_calculator.additiveOperatorClicked(Calculator::Subtraction);
}


void MainWindow::on_Kerto_clicked()
{
    m_calculator.multiplicativeOperatorClicked(Calculator::Multiplication);
}


void MainWindow::on_Jako_clicked()
{
    m_calculator.multiplicativeOperatorClicked(Calculator::Division);
}

void MainWindow::on_Onyhtakuin_clicked()
{
    m_calculator.equalClicked();
}


void MainWindow::on_PlusMiinus_clicked()
{
    m_calculator.changeSignClicked();
}


void MainWindow::on_Neliojuuri_clicked()
{
    m_calculator.unaryOperatorClicked(Calculator::SquareRoot);
}


void MainWindow::on_x2_clicked()
{
    m_calculator.unaryOperatorClicked(Calculator::Square);
}


void MainWindow::on_YksiKauttaX_clicked()
{
    m_calculator.unaryOperatorClicked(Calculator::Inverse);
}


void MainWindow::on_MC_clicked()
{
    m_calculator.clearMemory();
}


void MainWindow::on_MR_clicked()
{
    m_calculator.readMemory();
}


void MainWindow::on_MS_clicked()
{
    m_calculator.setMemory();
}


void MainWindow::on_Mplus_clicked()
{
    m_calculator.addToMemory();
}

