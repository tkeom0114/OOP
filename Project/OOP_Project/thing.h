#ifndef THING_H
#define THING_H

#include <bitset>

using std::bitset;


class Thing//좌표를 가진 모든 것들의 base class(player, 무기, 방어구, 포션)
{
public:
    Thing(int _name,int _x, int _y){name=_name;x=_x;y=_y;}
    Thing(int);
    virtual ~Thing();
    int& getx();
    int& gety();
    int& getName();
    static bitset<64>& getOccupied();
    static int& getOccupiedNum();
private:
    static bitset<64> occupied;
    static int occupiedNum;
    int name;
    int x;//x좌표(-1의 경우 플레이어가 소지하고 있는 물품을 의미)
    int y;//y좌표
};

enum{
    NONE=0,
    MATH,
    BIO,
    ELECTIC,
    COMPUTER,
    NONE_MONSTER,
    MATH_MONSTER,
    BIO_MONSTER,
    ELEC_MONSTER,
    COM_MONSTER,
    ALCOHOL,
    EARTHQUAKE,
    EXAM,
    WEAPON1,
    WEAPON2,
    WEAPON3,
    ARMOR1,
    ARMOR2,
    ARMOR3,
    DROP,
    CARRY,
    BREAK_LIMIT, 
    POTION1,
    POTION2,
    POTION3,
    HP_FULL
};

#endif // THING_H
