#ifndef WEAPON_H
#define WEAPON_H

#include "thing.h"

class Weapon:public Thing
{
public:
    Weapon(int,int,int);
    virtual int getDeal();
private:
    int deal;
};

#endif // WEAPON_H
