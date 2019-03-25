#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"
#include "choosedialog.h"
#include "clickqlabel.h"
#include "endingwidget.h"
#include <list>
#include <cmath>
#include <QObject>
#include <QString>
#include <QPixmap>
#include "thing.h"
#include "player.h"
#include "monster.h"
#include "potion.h"



namespace {
    int turn=100;
    Tile *tile[8][8] = { { nullptr } };
}

namespace game {
    list<Mover*> allMovers;
    list<Thing*> allItems;
    Player *player;
    QString strings[]={"무은재","수학과","생명과학과","전자전기공학과","컴퓨터공학과","수강신청 실패","정리 증명","실험 레포트",
                       "회로설계","어싸인","음주","지진","기말고사"};
}

using std::min;
using std::max;
using namespace game;

void printLabel(QLabel *parent,int type);
void fight(Monster *monster);
void dropItem(Monster *monster,bool drop);
void takeItem();
void usingItem(Potion* &item);


void MainWindow::setGame()
{
    ui->label->setPixmap(QPixmap(":/Images/picture.png"));
    int i,j=0,hor,ver;
    //Create 64 tiles (allocating memories to the objects of Tile class)
    ver=100;
    for(i=0;i<8;i++)
    {
        hor=350;
        for(j=0;j<8;j++)
        {
            tile[i][j] = new Tile(this,-1,j,i);
            tile[i][j]->tileDisplay();
            tile[i][j]->setGeometry(hor,ver,100,100);
            hor+=100;
        }
        ver+=100;
    }
    for(int i=0;i<10;i++)
    {
        Monster* monster = new Monster(NONE_MONSTER+player->getName());
        allMovers.push_back(monster);
    }

    printAll();
    QObject::connect(ui->potionPic_1,SIGNAL(mousePressed()),this,SLOT(usingItem1()));
    QObject::connect(ui->potionPic_2,SIGNAL(mousePressed()),this,SLOT(usingItem2()));
    QObject::connect(ui->potionPic_3,SIGNAL(mousePressed()),this,SLOT(usingItem3()));
    QObject::connect(ui->potionPic_4,SIGNAL(mousePressed()),this,SLOT(usingItem4()));
    QObject::connect(ui->potionPic_1,SIGNAL(mouseEntered()),this,SLOT(potionExpression1()));
    QObject::connect(ui->potionPic_2,SIGNAL(mouseEntered()),this,SLOT(potionExpression2()));
    QObject::connect(ui->potionPic_3,SIGNAL(mouseEntered()),this,SLOT(potionExpression3()));
    QObject::connect(ui->potionPic_4,SIGNAL(mouseEntered()),this,SLOT(potionExpression4()));
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            QObject::connect(tile[i][j],SIGNAL(proceedNextTurn()),this,SLOT(nextTurn()));
}

void MainWindow::nextTurn()
{
    turn--;



    list <Mover*>::iterator iterEnd = allMovers.end();
    for(list <Mover*>::iterator iterPos = allMovers.begin();iterPos != iterEnd;++iterPos)
    {
        if((*iterPos)!=player)//몬스터 이동 및 공격
        {
            (*iterPos)->move();
            if(abs((*iterPos)->getx()-player->getx())+abs((*iterPos)->gety()-player->gety())<2)
                fight(dynamic_cast<Monster*>(*iterPos));
            else if((*iterPos)->getName()==EARTHQUAKE &&
                    abs((*iterPos)->getx()-player->getx())<=2 && abs((*iterPos)->gety()-player->gety())<=2)
                fight(dynamic_cast<Monster*>(*iterPos));
        }
    }
    for(list <Mover*>::iterator iterPos = allMovers.begin();iterPos != iterEnd;++iterPos)
    {
        if((*iterPos)!=player && (*iterPos)->getHP()==0)//몬스터 사망
        {
            dropItem(dynamic_cast<Monster*>(*iterPos),true);
            delete (*iterPos);
            allMovers.erase(iterPos);
        }
    }
    if(turn==30)//기말고사 소환
    {
        Monster* exam = new Monster(EXAM);
        allMovers.push_back(exam);
    }
    int k=min(3,64-Thing::getOccupiedNum());
    if(k!=0)
    {
        int i=rand()%k;//몬스터 소환
        for(int j=0;j<i;j++)
        {
            Monster *monster;
            if(turn>=90)//처음 10턴의 경우 어드밴티지 적용
                monster = new Monster(NONE_MONSTER+player->getName());
            else if(turn>=60)
                monster = new Monster(NONE_MONSTER+(rand()%6));
            else
            {
                int seed=rand()%100;
                if(seed<90)
                    monster = new Monster(NONE_MONSTER+seed/15);
                else
                    monster = new Monster(EARTHQUAKE);
            }
            allMovers.push_back(monster);
        }
    }


    takeItem();
    if ( (player->getHP()==0 && --player->getLife()<=0) || turn==0)
    {
        if(turn==0)//마지막에 기말고사의 체력이 절반 이하로 줄지 않은 경우 학점 1점 감점
        {
            for(list <Mover*>::iterator iterPos = allMovers.begin();iterPos != iterEnd;++iterPos)
                if((*iterPos)->getName()==EXAM && (*iterPos)->getHP()>500)
                    player->getHP()=max(player->getHP()-100,0);
        }
        EndingWidget *w = new EndingWidget();
        w->show();
        close();
    }

    if(player->getHP()!=0 && player->getName()==NONE)
        player->getLife()=5;
    if(player->getName()==BIO)
        player->getHP()=min(player->getHP()+10,430);
    if(player->getLife()>0 && turn>0)
        printAll();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void printLabel(QLabel *parent,int type)
{
    switch (type) {
    case NONE:
        parent->setPixmap(QPixmap(":/Images/none.png"));
        break;
    case MATH:
        parent->setPixmap(QPixmap(":/Images/math.png"));
        break;
    case BIO:
        parent->setPixmap(QPixmap(":/Images/bio.png"));
        break;
    case ELECTIC:
        parent->setPixmap(QPixmap(":/Images/electric.png"));
        break;
    case COMPUTER:
        parent->setPixmap(QPixmap(":/Images/computer.png"));
        break;
    case NONE_MONSTER:
        parent->setPixmap(QPixmap(":/Images/none_monster.png"));
        break;
    case MATH_MONSTER:
        parent->setPixmap(QPixmap(":/Images/math_monster.png"));
        break;
    case BIO_MONSTER:
        parent->setPixmap(QPixmap(":/Images/bio_monster.png"));
        break;
    case ELEC_MONSTER:
        parent->setPixmap(QPixmap(":/Images/electric_monster.png"));
        break;
    case COM_MONSTER:
        parent->setPixmap(QPixmap(":/Images/computer_monster.png"));
        break;
    case EARTHQUAKE:
        parent->setPixmap(QPixmap(":/Images/earthquake.png"));
        break;
    case ALCOHOL:
        parent->setPixmap(QPixmap(":/Images/alcohol.png"));
        break;
    case EXAM:
        parent->setPixmap(QPixmap(":/Images/final_exam.png"));
        break;
    case WEAPON1:
        parent->setPixmap(QPixmap(":/Images/weapon1.png"));
        break;
    case WEAPON2:
        parent->setPixmap(QPixmap(":/Images/weapon2.png"));
        break;
    case WEAPON3:
        parent->setPixmap(QPixmap(":/Images/weapon3.png"));
        break;
    case ARMOR1:
        parent->setPixmap(QPixmap(":/Images/armor1.png"));
        break;
    case ARMOR2:
        parent->setPixmap(QPixmap(":/Images/armor2.png"));
        break;
    case ARMOR3:
        parent->setPixmap(QPixmap(":/Images/armor3.png"));
        break;
    case DROP:
        parent->setPixmap(QPixmap(":/Images/drop.png"));
        break;
    case CARRY:
        parent->setPixmap(QPixmap(":/Images/carry.png"));
        break;
    case BREAK_LIMIT:
        parent->setPixmap(QPixmap(":/Images/limit_break.png"));
        break;
    case POTION1:
        parent->setPixmap(QPixmap(":/Images/potion1.png"));
        break;
    case POTION2:
        parent->setPixmap(QPixmap(":/Images/potion2.png"));
        break;
    case POTION3:
        parent->setPixmap(QPixmap(":/Images/potion3.png"));
        break;
    case HP_FULL:
        parent->setPixmap(QPixmap(":/Images/hp_full.png"));
        break;
    case 26+NONE:
        parent->setPixmap(QPixmap(":/Images/big_none.png"));
        break;
    case 26+MATH:
        parent->setPixmap(QPixmap(":/Images/big_math.png"));
        break;
    case 26+BIO:
        parent->setPixmap(QPixmap(":/Images/big_bio.png"));
        break;
    case 26+ELECTIC:
        parent->setPixmap(QPixmap(":/Images/big_electric.png"));
        break;
    case 26+COMPUTER:
        parent->setPixmap(QPixmap(":/Images/big_computer.png"));
        break;
    }
    parent->pixmap();
}



void MainWindow::printAll()//게임에 대한 모든 정보 출력
{
    ui->potionPic_1->clear();
    ui->potionPic_2->clear();
    ui->potionPic_3->clear();
    ui->potionPic_4->clear();
    ui->monsterPic_1->clear();
    ui->monsterPic_2->clear();
    ui->monsterPic_3->clear();
    ui->monsterPic_4->clear();
    ui->monName_1->clear();
    ui->monName_2->clear();
    ui->monName_3->clear();
    ui->monName_4->clear();
    ui->monHP_1->clear();
    ui->monHP_2->clear();
    ui->monHP_3->clear();
    ui->monHP_4->clear();
    list <Mover*>::iterator iterEnd1 = allMovers.end();
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            tile[i][j]->clear();

    printLabel(ui->characterPic,player->getName()+26);
    printLabel(ui->weaponPic,player->getWeapon()->getName());
    printLabel(ui->armorPic,player->getArmor()->getName());
    ui->turnLabel->setText("남은 턴 수: "+QString::number(turn));
    ui->characterLabel->setText(strings[player->getName()]);
    QString cur;
    if(player->getHP()%100==0)
        cur="00";
    else if(player->getHP()%100<10)
        cur="0"+QString::number(player->getHP()%100);
    else
        cur=QString::number(player->getHP()%100);
    ui->hpLabel->setText("학점: "+QString::number(player->getHP()/100)+"."+cur);
    ui->damageLabel->setText("공격력: "+QString::number(player->getDeal()));
    if(player->getDefense()%100==0)
        cur="00";
    else if(player->getDefense()%100<10)
        cur="0"+QString::number(player->getHP()%100);
    else
        cur=QString::number(player->getDefense()%100);
    ui->defenseLabel->setText("방어력: "+QString::number(player->getDefense()/100)+"."+cur);
    if(player->getPotion(0)!=nullptr)
        printLabel(ui->potionPic_1,player->getPotion(0)->getName());
    if(player->getPotion(1)!=nullptr)
        printLabel(ui->potionPic_2,player->getPotion(1)->getName());
    if(player->getPotion(2)!=nullptr)
        printLabel(ui->potionPic_3,player->getPotion(2)->getName());
    if(player->getPotion(3)!=nullptr)
        printLabel(ui->potionPic_4,player->getPotion(3)->getName()); 
    for(list <Mover*>::iterator iterPos1 = allMovers.begin();iterPos1 != iterEnd1;++iterPos1)
        printLabel(tile[(*iterPos1)->gety()][(*iterPos1)->getx()],(*iterPos1)->getName());
    list<Thing*>::iterator iterEnd2 = allItems.end();
    for(list <Thing*>::iterator iterPos2 = allItems.begin();iterPos2 != iterEnd2;++iterPos2)
        printLabel(tile[(*iterPos2)->gety()][(*iterPos2)->getx()],(*iterPos2)->getName());

    for(list <Mover*>::iterator iterPos1 = allMovers.begin();iterPos1 != iterEnd1;++iterPos1)//몬스터 정보 출력
    {
        if((*iterPos1)->getx()==player->getx() && (*iterPos1)->gety()==player->gety()-1)
        {
            printLabel(ui->monsterPic_1,(*iterPos1)->getName());
            ui->monName_1->setText(strings[(*iterPos1)->getName()]);
            ui->monHP_1->setText("체력: "+QString::number((*iterPos1)->getHP()));
        }
        else if((*iterPos1)->getx()==player->getx()-1 && (*iterPos1)->gety()==player->gety())
        {
            printLabel(ui->monsterPic_2,(*iterPos1)->getName());
            ui->monName_2->setText(strings[(*iterPos1)->getName()]);
            ui->monHP_2->setText("체력: "+QString::number((*iterPos1)->getHP()));
        }
        else if((*iterPos1)->getx()==player->getx()+1 && (*iterPos1)->gety()==player->gety())
        {
            printLabel(ui->monsterPic_3,(*iterPos1)->getName());
            ui->monName_3->setText(strings[(*iterPos1)->getName()]);
            ui->monHP_3->setText("체력: "+QString::number((*iterPos1)->getHP()));
        }
        else if((*iterPos1)->getx()==player->getx() && (*iterPos1)->gety()==player->gety()+1)
        {
            printLabel(ui->monsterPic_4,(*iterPos1)->getName());
            ui->monName_4->setText(strings[(*iterPos1)->getName()]);
            ui->monHP_4->setText("체력: "+QString::number((*iterPos1)->getHP()));
        }
    }
    this->show();
}

void MainWindow::usingItem1()
{
    usingItem(player->getPotion(0));
    printAll();
}

void MainWindow::usingItem2()
{
    usingItem(player->getPotion(1));
    printAll();
}

void MainWindow::usingItem3()
{
    usingItem(player->getPotion(2));
    printAll();
}

void MainWindow::usingItem4()
{
    usingItem(player->getPotion(3));
    printAll();
}

void MainWindow::potionExpression1()
{
    potionExpression(player->getPotion(0));
}

void MainWindow::potionExpression2()
{
    potionExpression(player->getPotion(1));
}

void MainWindow::potionExpression3()
{
    potionExpression(player->getPotion(2));
}

void MainWindow::potionExpression4()
{
    potionExpression(player->getPotion(3));
}

void MainWindow::potionExpression(Potion *potion)
{
    if(potion==nullptr)
        return;
    switch(potion->getName()){
    case DROP:
        ui->potionLabel_2->setText("모든 과제들이 사라진다. 단, 아이템은 드랍되지 않고, 기말고사는 사라지지 않는다");
        break;
    case CARRY:
        ui->potionLabel_2->setText("1칸 내에 있는 모든 과제들이 사라진다.단, 기말고사에게는 150의 데미지를 준다");
        break;
    case BREAK_LIMIT:
        ui->potionLabel_2->setText("2칸 내에 있는 모든 과제들이 사라진다.단, 기말고사에게는 150의 데미지를 준다");
        break;
    case POTION1:
        ui->potionLabel_2->setText("학점이 0.5회복된다");
        break;
    case POTION2:
        ui->potionLabel_2->setText("학점이 1회복된다");
        break;
    case POTION3:
        ui->potionLabel_2->setText("학점이 1.5회복된다");
        break;
    case HP_FULL:
        ui->potionLabel_2->setText("학점이 4.3으로 회복된다");
        break;
    }
    ui->potionLabel_2->show();
}

void fight(Monster *monster)
{
    int deal = player->getDeal()-monster->getDefense();
    int damage = monster->getDeal()-player->getDefense();
    if(monster->getName()-player->getName()==5)//같은 속성
    {
        deal = deal*3/2;
        damage /=2;
    }
    deal=max(deal,0);
    damage=max(damage,0);
    if(abs(monster->getx()-player->getx())+abs(monster->gety()-player->gety())<2)
        monster->getHP()=max(monster->getHP()-deal,0);
    if(monster->getHP()!=0)
        player->getHP()=max(player->getHP()-damage,0);

}

void dropItem(Monster *monster,bool drop)
{
    if(!drop || monster->getReward()==-1)
    {
        Thing::getOccupied().flip(static_cast<size_t>(8*monster->gety()+monster->getx()));
        Thing::getOccupiedNum()--;
        return;
    }
    Thing *item;
    if(monster->getReward()>=WEAPON1 && monster->getReward()<=WEAPON3)//무기
    {
        item=new Weapon(monster->getReward(),monster->getx(),monster->gety());
    }
    else if(monster->getReward()>=ARMOR1 && monster->getReward()<=ARMOR3)//방어구
    {
        item=new Armor(monster->getReward(),monster->getx(),monster->gety());
    }
    else if(monster->getReward()>=DROP && monster->getReward()<=HP_FULL)//포션
    {
        item=new Potion(monster->getReward(),monster->getx(),monster->gety());
    }

    allItems.push_back(item);
}

void takeItem()
{
    Thing *item=nullptr;
    list<Thing*>::iterator iterEnd = allItems.end();
    for(list <Thing*>::iterator iterPos = allItems.begin();iterPos != iterEnd;++iterPos)
        if((*iterPos)->getx()==player->getx() && (*iterPos)->gety()==player->gety())
        {
            item=(*iterPos);
            allItems.erase(iterPos);
        }
    if(item==nullptr)
        return;
    if(item->getName()>=WEAPON1 && item->getName()<=WEAPON3)//무기
    {
        if(player->getWeapon()->getDeal()<dynamic_cast<Weapon*>(item)->getDeal())
        {
            free(player->getWeapon());
            player->getWeapon()=dynamic_cast<Weapon*>(item);
            if(player->getName()==MATH)
                player->getDeal()=player->getWeapon()->getDeal()*3/2;
            else
                player->getDeal()=player->getWeapon()->getDeal();
        }
        else
            free(item);
        Thing::getOccupiedNum()--;
    }
    else if(item->getName()>=ARMOR1 && item->getName()<=ARMOR3)//방어구
    {
        if(player->getArmor()->getDefense()<dynamic_cast<Armor*>(item)->getDefense())
        {
            free(player->getArmor());
            player->getArmor()=dynamic_cast<Armor*>(item);
            if(player->getName()==COMPUTER)
                player->getDefense()=player->getArmor()->getDefense()*3/2;
            else
                player->getDefense()=player->getArmor()->getDefense();
        }
        else
            free(item);
        Thing::getOccupiedNum()--;
    }
    else if(item->getName()>=DROP && item->getName()<=HP_FULL)//포션
    {
        for(int i=0;i<4;i++)
        {
            if(player->getPotion(i)==nullptr)
            {
                player->getPotion(i)=dynamic_cast<Potion*>(item);
                Thing::getOccupiedNum()--;
                break;
            }
            if(i==3)
                free(item);
        }
    }
}

void usingItem(Potion* &item)
{
    if(item==nullptr)
        return;
    if(item->getRecovery()!=0)
    {
        player->getHP()=min(player->getHP()+item->getRecovery(),430);
        if(player->getName()==NONE)
            player->getLife()=5;
    }
    else
    {
        list <Mover*>::iterator iterEnd = allMovers.end();
        for(list <Mover*>::iterator iterPos = allMovers.begin();iterPos != iterEnd;++iterPos)
        {
            if((*iterPos)!=player)
            {
                if(item->getName()==DROP)//드랍
                {
                    if((*iterPos)->getName()!=EXAM)
                    {
                        dropItem(dynamic_cast<Monster*>(*iterPos),false);
                        delete (*iterPos);
                        allMovers.erase(iterPos);
                    }
                }
                else if(item->getName()==CARRY && abs((*iterPos)->getx()-player->getx())<=1
                        && abs((*iterPos)->gety()-player->gety())<=1)//좁은 광역기
                {
                    if((*iterPos)->getName()==EXAM)
                    {
                        (*iterPos)->getHP()=max((*iterPos)->getHP()-150,0);
                    }
                    if((*iterPos)->getName()!=EXAM || (*iterPos)->getHP()==0)
                    {
                        dropItem(dynamic_cast<Monster*>(*iterPos),true);
                        delete (*iterPos);
                        allMovers.erase(iterPos);
                    }
                }
                else if(item->getName()==BREAK_LIMIT && abs((*iterPos)->getx()-player->getx())<=2
                        && abs((*iterPos)->gety()-player->gety())<=2)//넓은 광역기
                {
                    if((*iterPos)->getName()==EXAM)
                    {
                        (*iterPos)->getHP()=max((*iterPos)->getHP()-150,0);
                    }
                    if((*iterPos)->getName()!=EXAM || (*iterPos)->getHP()==0)
                    {
                        dropItem(dynamic_cast<Monster*>(*iterPos),true);
                        delete (*iterPos);
                        allMovers.erase(iterPos);
                    }
                }
            }

        }
    }
    free(item);
    item=nullptr;
}
