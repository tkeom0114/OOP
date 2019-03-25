#include "clickqlabel.h"


ClickQLabel::ClickQLabel(QWidget *parent):QLabel(parent)
{

}

void ClickQLabel::mousePressEvent(QMouseEvent *event)
{
    emit mousePressed();
    return;
}

void ClickQLabel::enterEvent(QEvent *event)
{
    emit mouseEntered();
    return;
}

void ClickQLabel::leaveEvent(QEvent *event)
{
    emit mouseLeaved();
    return;
}

ClickQLabel::~ClickQLabel()
{
    ;
}
