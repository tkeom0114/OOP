#include "tile.h"
#include "player.h"
#include "mover.h"
#include "mainwindow.h"
#include <list>
#include <cmath>

using std::list;
using namespace game;

Tile::Tile(QWidget *parent,int _name,int _x,int _y):ClickQLabel (parent),Thing(_name,_x,_y)
{

}

void Tile::tileDisplay()
{

    if((this->getx()+this->gety())%2)
        this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
}

void Tile::mousePressEvent(QMouseEvent *event)
{
    bool take=false;
    list <Mover*>::iterator iterEnd1 = allMovers.end();
    for(list <Mover*>::iterator iterPos1 = allMovers.begin();iterPos1 != iterEnd1;++iterPos1)
        if((*iterPos1)!=player && (*iterPos1)->getx()==this->getx() && (*iterPos1)->gety()==this->gety())
            return;
    Thing::getOccupied().flip(static_cast<size_t>(player->gety()*8+player->getx()));
    if(abs(this->getx()-player->getx())+abs(this->gety()-player->gety())>1)
    {
        Thing::getOccupied().flip(static_cast<size_t>(player->gety()*8+player->getx()));
        return;
    }    
    player->move(this->getx(),this->gety());
    list <Thing*>::iterator iterEnd2 = allItems.end();
    for(list <Thing*>::iterator iterPos2 = allItems.begin();iterPos2 != iterEnd2;++iterPos2)
        if((*iterPos2)->getx()==this->getx() && (*iterPos2)->gety()==this->gety())
            take=true;
    if(!take)
        Thing::getOccupied().flip(static_cast<size_t>(player->gety()*8+player->getx()));
    emit proceedNextTurn();
    return;
}

