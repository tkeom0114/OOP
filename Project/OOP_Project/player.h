#ifndef PLAYER_H
#define PLAYER_H

#include "mover.h"
#include "weapon.h"
#include "armor.h"
#include "potion.h"


class Player:public Mover
{
public:
    Player(int);
    Weapon* &getWeapon();
    Armor* &getArmor();
    Potion* &getPotion(int);
    int &getLife();
private:
    Weapon *weapon;
    Armor *armor;
    Potion *potions[4];
    int life;
};

#endif // PLAYER_H
