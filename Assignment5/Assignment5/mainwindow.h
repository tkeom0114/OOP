#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushMatrix_clicked();

    void on_pushNumeric_clicked();

    void on_pushString_clicked();

    void on_pushPlus_clicked();

    void on_pushMinus_clicked();

    void on_pushMul_clicked();

    void on_pushDiv_clicked();

    void on_pushEdit_clicked();

    void on_pushDelete_clicked();

    void on_pushClear_clicked();

    void printAllValues();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
