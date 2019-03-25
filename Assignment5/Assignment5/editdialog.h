#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

private slots:
    void on_pushOK_clicked();
    void changeLabel(QString);
signals:
    void editValue();
private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
