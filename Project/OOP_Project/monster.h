#ifndef MONSTER_H
#define MONSTER_H

#include "mover.h"

class Monster:public Mover
{
public:
    Monster(int);
    int getReward();
private:
    int reward;
};

#endif // MONSTER_H
