#ifndef MOVER_H
#define MOVER_H

#include "thing.h"

class Mover:public Thing
{
public:
    Mover(int);
    int &getHP();
    virtual int &getDeal();
    virtual int &getDefense();
    void move(int,int);
    void move();
private:
    int hp;
    int deal;
    int defense;

};

#endif // MOVER_H
