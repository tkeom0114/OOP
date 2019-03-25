#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseDialog;
}

class ChooseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseDialog(QWidget *parent = nullptr);
    ~ChooseDialog();
    void playCharacter(int);

private slots:
    void characterChoose();
    void character1();
    void character2();
    void character3();
    void character4();
    void character5();
    void characterOnExp1();
    void characterOnExp2();
    void characterOnExp3();
    void characterOnExp4();
    void characterOnExp5();
    void characterOffExp1();
    void characterOffExp2();
    void characterOffExp3();
    void characterOffExp4();
    void characterOffExp5();
signals:
    void gameStart();

private:
    Ui::ChooseDialog *ui;
};

#endif // CHOOSEDIALOG_H
