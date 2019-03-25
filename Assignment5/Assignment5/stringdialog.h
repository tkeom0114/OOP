#ifndef STRINGDIALOG_H
#define STRINGDIALOG_H

#include <QDialog>

namespace Ui {
class StringDialog;
}

class StringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StringDialog(QWidget *parent = nullptr);
    ~StringDialog();

private slots:
    void on_pushOK_clicked();
signals:
    void addString();
private:
    Ui::StringDialog *ui;
};

#endif // STRINGDIALOG_H
