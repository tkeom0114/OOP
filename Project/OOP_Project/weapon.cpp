#include "weapon.h"

Weapon::Weapon(int _name,int x,int y):Thing(_name,x,y)
{
    switch (_name) {
    case WEAPON1:
        deal=40;
        break;
    case WEAPON2:
        deal=80;
        break;
    case WEAPON3:
        deal=120;
        break;
    }
}

int Weapon::getDeal()
{
    return deal;
}
