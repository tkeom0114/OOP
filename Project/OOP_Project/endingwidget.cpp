#include "endingwidget.h"
#include "ui_endingwidget.h"
#include "mainwindow.h"
#include "player.h"

using namespace game;


EndingWidget::EndingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndingWidget)
{
    ui->setupUi(this);
    if(player->getHP()>=400)
    {
        ui->label->setPixmap(QPixmap(":/Images/excellent.PNG"));
    }
    else if(player->getHP()>=300)
    {
        ui->label->setPixmap(QPixmap(":/Images/good.PNG"));
    }
    else if(player->getHP()>=200)
    {
        ui->label->setPixmap(QPixmap(":/Images/not_good.PNG"));
    }
    else
    {
        ui->label->setPixmap(QPixmap(":/Images/dead.PNG"));
    }

}

EndingWidget::~EndingWidget()
{
    delete ui;
}
