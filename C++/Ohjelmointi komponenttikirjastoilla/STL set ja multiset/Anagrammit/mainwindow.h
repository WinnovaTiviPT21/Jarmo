#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_textEdit_textChanged();

    void on_listView_windowIconTextChanged(const QString &iconText);

    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H