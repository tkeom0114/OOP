#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "potion.h"
#include "mover.h"
#include "player.h"

using std::list;

class Player;

namespace Ui {
    class MainWindow;
}

namespace game {
    extern list<Mover*> allMovers;
    extern list<Thing*> allItems;
    extern Player *player;
    extern QString strings[];
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printAll();
    void clearAll();
    void potionExpression(Potion *potion);

private slots:
    void setGame();
    void nextTurn();
    void usingItem1();
    void usingItem2();
    void usingItem3();
    void usingItem4();
    void potionExpression1();
    void potionExpression2();
    void potionExpression3();
    void potionExpression4();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
