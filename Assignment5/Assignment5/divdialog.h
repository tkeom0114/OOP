#ifndef DIVDIALOG_H
#define DIVDIALOG_H

#include <QDialog>

namespace Ui {
class DivDialog;
}

class DivDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DivDialog(QWidget *parent = nullptr);
    ~DivDialog();

private slots:
    void on_pushOK_2_clicked();
    void changeLabel1(QString);
    void changeLabel2(QString);
signals:
    void divOperation();
private:
    Ui::DivDialog *ui;
};

#endif // DIVDIALOG_H
