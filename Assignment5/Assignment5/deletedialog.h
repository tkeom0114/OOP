#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialog(QWidget *parent = nullptr);
    ~DeleteDialog();

private slots:
    void on_pushOK_clicked();
    void changeLabel(QString);
signals:
    void deleteValue();
private:
    Ui::DeleteDialog *ui;
};

#endif // DELETEDIALOG_H
