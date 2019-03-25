#include "armor.h"

Armor::Armor(int _name,int x,int y):Thing(_name,x,y)
{
    switch (_name) {
    case ARMOR1:
        defense=20;
        break;
    case ARMOR2:
        defense=40;
        break;
    case ARMOR3:
        defense=60;
        break;
    }
}

int Armor::getDefense()
{
    return defense;
}
