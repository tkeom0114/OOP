#include "thing.h"
#include "mover.h"
#include "tile.h"
#include <list>
#include <cmath>
#include <iostream>
#include "mainwindow.h"

using namespace game;

bitset<64> Thing::occupied;
int Thing::occupiedNum;

Thing::Thing(int _name)
{
    name=_name;
    do{
        x=rand()%8;
        y=rand()%8;
        if(!occupied.test(static_cast<size_t>(8*y+x)))
            break;
    }while(true);
    occupied.flip(static_cast<size_t>(8*y+x));
    occupiedNum++;
}

int& Thing::getx()
{
    return x;
}

int& Thing::gety()
{
    return y;
}

int& Thing::getName()
{
    return name;
}

bitset<64>& Thing::getOccupied()
{
    return occupied;
}

int& Thing::getOccupiedNum()
{
    return occupiedNum;
}

Thing::~Thing()
{
    ;
}
