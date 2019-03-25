#ifndef ENDINGWIDGET_H
#define ENDINGWIDGET_H

#include <QWidget>

namespace Ui {
class EndingWidget;
}

class EndingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EndingWidget(QWidget *parent = nullptr);
    ~EndingWidget();

private:
    Ui::EndingWidget *ui;
};

#endif // ENDINGWIDGET_H
