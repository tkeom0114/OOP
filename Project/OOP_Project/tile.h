#ifndef TILE_H
#define TILE_H
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QDialog>
#include "clickqlabel.h"
#include "thing.h"

class Tile: public ClickQLabel, public Thing
{
    Q_OBJECT
public:
    Tile(QWidget*,int,int,int);
    void tileDisplay();
    void mousePressEvent(QMouseEvent *event);
private slots:

signals:
    void proceedNextTurn();
};

#endif // TILE_H
