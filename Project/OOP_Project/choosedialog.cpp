#include "choosedialog.h"
#include "ui_choosedialog.h"
#include "mainwindow.h"
#include "helpwidget.h"
#include <list>

#include "thing.h"
#include "player.h"

using std::list;
using namespace game;

ChooseDialog::ChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseDialog)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/Images/start.PNG"));
    ui->startLabel->setPixmap(QPixmap(":/Images/start_button.png"));
    QObject::connect(ui->startLabel,SIGNAL(mousePressed()),this,SLOT(characterChoose()));
}

ChooseDialog::~ChooseDialog()
{
    delete ui;
}

void ChooseDialog::characterChoose()
{
    ui->startLabel->hide();
    ui->label->setPixmap(QPixmap(":/Images/choose_character.png"));
    ui->textLabel->setPixmap(QPixmap(":/Images/character_label.png"));
    ui->characterLabel_1->setPixmap(QPixmap(":/Images/character_none.png"));
    ui->characterLabel_2->setPixmap(QPixmap(":/Images/character_math.png"));
    ui->characterLabel_3->setPixmap(QPixmap(":/Images/character_bio.png"));
    ui->characterLabel_4->setPixmap(QPixmap(":/Images/character_elec.png"));
    ui->characterLabel_5->setPixmap(QPixmap(":/Images/character_com.png"));
    this->show();
    QObject::connect(ui->characterLabel_1,SIGNAL(mousePressed()),this,SLOT(character1()));
    QObject::connect(ui->characterLabel_2,SIGNAL(mousePressed()),this,SLOT(character2()));
    QObject::connect(ui->characterLabel_3,SIGNAL(mousePressed()),this,SLOT(character3()));
    QObject::connect(ui->characterLabel_4,SIGNAL(mousePressed()),this,SLOT(character4()));
    QObject::connect(ui->characterLabel_5,SIGNAL(mousePressed()),this,SLOT(character5()));
    QObject::connect(ui->characterLabel_1,SIGNAL(mouseEntered()),this,SLOT(characterOnExp1()));
    QObject::connect(ui->characterLabel_2,SIGNAL(mouseEntered()),this,SLOT(characterOnExp2()));
    QObject::connect(ui->characterLabel_3,SIGNAL(mouseEntered()),this,SLOT(characterOnExp3()));
    QObject::connect(ui->characterLabel_4,SIGNAL(mouseEntered()),this,SLOT(characterOnExp4()));
    QObject::connect(ui->characterLabel_5,SIGNAL(mouseEntered()),this,SLOT(characterOnExp5()));
    QObject::connect(ui->characterLabel_1,SIGNAL(mouseLeaved()),this,SLOT(characterOffExp1()));
    QObject::connect(ui->characterLabel_2,SIGNAL(mouseLeaved()),this,SLOT(characterOffExp2()));
    QObject::connect(ui->characterLabel_3,SIGNAL(mouseLeaved()),this,SLOT(characterOffExp3()));
    QObject::connect(ui->characterLabel_4,SIGNAL(mouseLeaved()),this,SLOT(characterOffExp4()));
    QObject::connect(ui->characterLabel_5,SIGNAL(mouseLeaved()),this,SLOT(characterOffExp5()));
}

void ChooseDialog::playCharacter(int name)
{
    Thing::getOccupied().reset();
    player = new Player(name);
    allMovers.push_back(player);
    emit gameStart();
    close();
    HelpWidget *w = new HelpWidget();
    w->show();
    return ;
}

void ChooseDialog::character1()
{
    playCharacter(NONE);
}

void ChooseDialog::character2()
{
    playCharacter(MATH);
}

void ChooseDialog::character3()
{
    playCharacter(BIO);
}

void ChooseDialog::character4()
{
    playCharacter(ELECTIC);
}

void ChooseDialog::character5()
{
    playCharacter(COMPUTER);
}

void ChooseDialog::characterOnExp1()
{
    ui->expLabel_1->setPixmap(QPixmap(":/Images/explain_none.png"));
    ui->expLabel_1->show();
}

void ChooseDialog::characterOnExp2()
{
    ui->expLabel_2->setPixmap(QPixmap(":/Images/explain_math.png"));
    ui->expLabel_2->show();
}

void ChooseDialog::characterOnExp3()
{
    ui->expLabel_3->setPixmap(QPixmap(":/Images/explain_bio.png"));
    ui->expLabel_3->show();
}

void ChooseDialog::characterOnExp4()
{
    ui->expLabel_4->setPixmap(QPixmap(":/Images/explain_elec.png"));
    ui->expLabel_4->show();
}

void ChooseDialog::characterOnExp5()
{
    ui->expLabel_5->setPixmap(QPixmap(":/Images/explain_com.png"));
    ui->expLabel_5->show();
}

void ChooseDialog::characterOffExp1()
{
    ui->expLabel_1->hide();
}

void ChooseDialog::characterOffExp2()
{
    ui->expLabel_2->hide();
}

void ChooseDialog::characterOffExp3()
{
    ui->expLabel_3->hide();
}

void ChooseDialog::characterOffExp4()
{
    ui->expLabel_4->hide();
}

void ChooseDialog::characterOffExp5()
{
    ui->expLabel_5->hide();
}

