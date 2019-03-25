#ifndef MULDIALOG_H
#define MULDIALOG_H

#include <QDialog>

namespace Ui {
class MulDialog;
}

class MulDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MulDialog(QWidget *parent = nullptr);
    ~MulDialog();

private slots:
    void on_pushOK_2_clicked();
    void changeLabel1(QString);
    void changeLabel2(QString);
signals:
    void mulOperation();
private:
    Ui::MulDialog *ui;
};

#endif // MULDIALOG_H
