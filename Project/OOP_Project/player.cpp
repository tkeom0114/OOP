#include "player.h"
#include "mover.h"

Player::Player(int _name):Mover(_name)
{
    getHP()=430;
    weapon=new Weapon(WEAPON1,-1,-1);
    armor=new Armor(ARMOR1,-1,-1);
    for(int i=0;i<4;i++)
        potions[i]=nullptr;
    if(_name==NONE)
        life=5;
    else
        life=1;
    if(_name==MATH)
        getDeal()=weapon->getDeal()*3/2;
    else
        getDeal()=weapon->getDeal();
    if(_name==COMPUTER)
        getDefense()=armor->getDefense()*3/2;
    else
        getDefense()=armor->getDefense();

}

Weapon* &Player::getWeapon()
{
    return weapon;
}

Armor* &Player::getArmor()
{
    return armor;
}

Potion* &Player::getPotion(int index)
{
    return potions[index];
}

int &Player::getLife()
{
    return life;
}
