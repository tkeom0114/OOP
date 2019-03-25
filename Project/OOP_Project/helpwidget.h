#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>

namespace Ui {
class HelpWidget;
}

class HelpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWidget(QWidget *parent = nullptr);
    ~HelpWidget();

private:
    Ui::HelpWidget *ui;
    int page;
private slots:
    void nextPage();
    void prevPage();
};

#endif // HELPWIDGET_H
