#ifndef POTION_H
#define POTION_H

#include "thing.h"


class Potion:public Thing
{
public:
    Potion(int,int,int);
    int getRecovery();
private:
    int recovery;
};

#endif // POTION_H
