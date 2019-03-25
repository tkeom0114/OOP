#ifndef CLICKQLABEL_H
#define CLICKQLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QDialog>

class ClickQLabel : public QLabel
{
    Q_OBJECT
public:
    ClickQLabel(QWidget *parent);
    virtual ~ClickQLabel();
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private slots:

signals:
    void mousePressed();
    void mouseEntered();
    void mouseLeaved();
};

#endif // CLICKQLABEL_H
