#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

private slots:
    void on_pushOK_2_clicked();
    void changeLabel1(QString);
    void changeLabel2(QString);
signals:
    void addOperation();
private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
