#include "potion.h"
#include "player.h"
#include <cmath>


Potion::Potion(int _name,int x,int y):Thing(_name,x,y)
{
    if(_name>=DROP && _name<=BREAK_LIMIT)
        recovery=0;
    else if(_name==POTION1)
        recovery=50;
    else if(_name==POTION2)
        recovery=100;
    else if(_name==POTION3)
        recovery=150;
    else if(_name==HP_FULL)
        recovery=430;
}


int Potion::getRecovery()
{
    return recovery;
}


