#ifndef MINUSDIALOG_H
#define MINUSDIALOG_H

#include <QDialog>

namespace Ui {
class MinusDialog;
}

class MinusDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MinusDialog(QWidget *parent = nullptr);
    ~MinusDialog();

private slots:
    void on_pushOK_2_clicked();
    void changeLabel1(QString);
    void changeLabel2(QString);
signals:
    void minusOperation();
private:
    Ui::MinusDialog *ui;
};

#endif // MINUSDIALOG_H
