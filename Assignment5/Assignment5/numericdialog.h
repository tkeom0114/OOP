#ifndef NUMERICDIALOG_H
#define NUMERICDIALOG_H

#include <QDialog>

namespace Ui {
class NumericDialog;
}

class NumericDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumericDialog(QWidget *parent = nullptr);
    ~NumericDialog();

private slots:
    void on_pushOK_clicked();
signals:
    void addNumeric();
private:
    Ui::NumericDialog *ui;
};

#endif // NUMERICDIALOG_H
