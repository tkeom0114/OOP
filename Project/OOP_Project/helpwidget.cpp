#include "helpwidget.h"
#include "ui_helpwidget.h"

HelpWidget::HelpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpWidget)
{
    ui->setupUi(this);
    page = 0;
    ui->label->setPixmap(QPixmap(":/Images/page0.PNG"));
    ui->nextLabel->setPixmap(QPixmap(":/Images/right_arrow.png"));
    ui->prevLabel->setPixmap(QPixmap(":/Images/left_arrow.png"));
    ui->prevLabel->hide();
    QObject::connect(ui->nextLabel,SIGNAL(mousePressed()),this,SLOT(nextPage()));
    QObject::connect(ui->prevLabel,SIGNAL(mousePressed()),this,SLOT(prevPage()));
}

HelpWidget::~HelpWidget()
{
    delete ui;
}

void HelpWidget::nextPage()
{
    if(page<4)
        page++;
    switch(page){
    case 1:
        ui->label->setPixmap(QPixmap(":/Images/page1.PNG"));
        ui->prevLabel->show();
        break;
    case 2:
        ui->label->setPixmap(QPixmap(":/Images/page2.PNG"));
        break;
    case 3:
        ui->label->setPixmap(QPixmap(":/Images/page3.PNG"));
        break;
    case 4:
        ui->label->setPixmap(QPixmap(":/Images/page4.PNG"));
        ui->nextLabel->hide();
        break;
    }
}

void HelpWidget::prevPage()
{
    if (page>0)
        page--;
    switch(page){
    case 0:
        ui->label->setPixmap(QPixmap(":/Images/page0.PNG"));
        ui->prevLabel->hide();
        break;
    case 1:
        ui->label->setPixmap(QPixmap(":/Images/page1.PNG"));
        break;
    case 2:
        ui->label->setPixmap(QPixmap(":/Images/page2.PNG"));
        break;
    case 3:
        ui->label->setPixmap(QPixmap(":/Images/page3.PNG"));
        ui->nextLabel->show();
        break;
    }


}
