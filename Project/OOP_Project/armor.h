#ifndef ARMOR_H
#define ARMOR_H

#include "thing.h"

class Armor:public Thing
{
public:
    Armor(int,int,int);
    virtual int getDefense();
private:
    int defense;
};

#endif // ARMOR_H
