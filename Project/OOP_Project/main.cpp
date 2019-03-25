#include <QApplication>
#include "mainwindow.h"
#include "tile.h"
#include <ctime>
#include "choosedialog.h"
#include "thing.h"
#include <QObject>


int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Thing::getOccupied().reset();
    Thing::getOccupiedNum()=0;
    QApplication a(argc, argv);
    MainWindow w;
    ChooseDialog choosedialog;
    choosedialog.show();
    QObject::connect(&choosedialog,SIGNAL(gameStart()),&w,SLOT(setGame()));


    return a.exec();
}

