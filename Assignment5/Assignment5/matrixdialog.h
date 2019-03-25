#ifndef MATRIXDIALOG_H
#define MATRIXDIALOG_H

#include <QDialog>

namespace Ui {
class MatrixDialog;
}

class MatrixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MatrixDialog(QWidget *parent = nullptr);
    ~MatrixDialog();

private slots:
    void on_pushOK_clicked();
signals:
    void addMatrix();
private:
    Ui::MatrixDialog *ui;
};

#endif // MATRIXDIALOG_H
