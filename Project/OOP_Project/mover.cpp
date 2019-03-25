#include "mover.h"
#include "player.h"
#include "mainwindow.h"
#include <cmath>
#include <iostream>
#include <vector>

using std::vector;
using namespace game;

Mover::Mover(int _name):Thing(_name)
{

}

int &Mover::getHP()
{
    return hp;
}

int &Mover::getDeal()
{
    return deal;
}

int &Mover::getDefense()
{
    return defense;
}

void Mover::move(int _x,int _y)
{
    getx()=_x;
    gety()=_y;
}

void Mover::move()
{
    int x=getx();
    int y=gety();
    getOccupied().flip(static_cast<size_t>(8*y+x));
    int direction=0;
    int dx[5]={0,1,0,-1,0};
    int dy[5]={0,0,1,0,-1};
    vector<int> able;
    able.reserve(4);
    if(player->getName()!=ELECTIC || this->getHP()<150 || this->getName()==EXAM)
    {
        for(int i=1;i<5;i++)
        {
            if(x+dx[i]>-1 && x+dx[i]<8 &&  y+dy[i]>-1 && y+dy[i]<8 && !getOccupied().test(static_cast<size_t>(8*(y+dy[i])+x+dx[i])))
            {
                able.push_back(i);
                if(abs(x+dx[i]-player->getx())+abs(y+dy[i]-player->gety())
                    < abs(x+dx[direction]-player->getx())+abs(y+dy[direction]-player->gety()))
                        direction=i;
            }

        }
        if(direction==0 && able.size()!=0)
        {
           direction=able[static_cast<unsigned>(rand())%able.size()];
           if(abs(x-player->getx())+abs(y-player->gety())<=1)
               direction=0;
        }

    }
    else
    {
        do{
            direction=rand()%5;
            if(y+dy[direction]<8 && y+dy[direction]>-1
                    && x+dx[direction]<8 && x+dx[direction]>-1
                    && !getOccupied().test(static_cast<size_t>(8*(y+dy[direction])+x+dx[direction])))
                break;
        }while(true);
    }
    getx()=x+dx[direction];
    gety()=y+dy[direction];
    getOccupied().flip(static_cast<size_t>(gety()*8+getx()));
}
