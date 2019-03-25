#include "monster.h"
#include "weapon.h"
#include "player.h"
#include "mainwindow.h"
#include <list>
#include <iostream>

using std::list;
using namespace game;

Monster::Monster(int _name):Mover(_name)
{
    int seed=rand()%100;
    if(_name>=NONE_MONSTER && _name<EARTHQUAKE)
    {
        getHP()=170;
        getDeal()=80;
        getDefense()=0;
        if(player->getWeapon()->getName()==WEAPON1 || player->getArmor()->getName()==ARMOR1)
        {
            if(seed<20)
                reward=WEAPON2;
            else if(seed<40)
                reward=ARMOR2;
            else if(seed<58)
                reward=POTION1;
            else if(seed<76)
                reward=POTION2;
            else if(seed<85)
                reward=POTION3;
            else if(seed<90)
                reward=DROP;
            else
                reward=CARRY;
        }
        else//무기, 방어구 모두 2단계 획득했을시 보상(꽝도 있음)
        {
            if(seed<35)
                reward=-1;
            else if(seed<55)
                reward=POTION1;
            else if(seed<75)
                reward=POTION2;
            else if(seed<85)
                reward=POTION3;
            else if(seed<90)
                reward=DROP;
            else
                reward=CARRY;
        }

    }
    else if(_name==EARTHQUAKE)
    {
        getHP()=150;
        getDeal()=100;
        getDefense()=0;
        if(seed<30)
            reward=WEAPON3;
        else if(seed<60)
            reward=ARMOR3;
        else
            reward=BREAK_LIMIT;
    }
    else if(_name==EXAM)
    {
        getHP()=1000;
        getDeal()=120;
        getDefense()=50;
        reward=HP_FULL;
    }
}

int Monster::getReward()
{
    return reward;
}
