#include "deletedialog.h"
#include "ui_deletedialog.h"
#include "operand.h"
#include "matrix.h"
#include "numeric.h"
#include "strvalue.h"
#include <list>
#include <QMessageBox>

using namespace std;

extern list<Operand*> Operands;

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    list<Operand*>::iterator iterEnd=Operands.end();
    connect(this->ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(changeLabel(QString)));
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        ui->comboBox->addItem((*iterPos)->getName());
}

void DeleteDialog::changeLabel(QString name)
{
    QString curstring;
    list<Operand*>::iterator iterEnd=Operands.end();
    list<Operand*>::iterator iterPos;
    for(iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
    {
        if(name==(*iterPos)->getName())
            break;
    }
    curstring="Type = ";
    if((*iterPos)->getType()=="Matrix")
    {
        curstring+="Matrix ";
        curstring += "/ Rows = "+QString::number(dynamic_cast<Matrix*>(*iterPos)->getRows());
        curstring += "/ Cols = "+QString::number(dynamic_cast<Matrix*>(*iterPos)->getCols());
    }
    else if((*iterPos)->getType()=="Numeric")
    {
        curstring+="Numeric";
    }
    else if((*iterPos)->getType()=="String")
    {
        curstring+="String";
    }
    ui->DisplayLabel->setText(curstring);
    ui->DisplayLabel->show();
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_pushOK_clicked()
{
    list<Operand*>::iterator iterEnd=Operands.end();
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        if((*iterPos)->getName()==ui->comboBox->currentText())
        {
            delete (*iterPos);
            Operands.erase(iterPos);
        }
    //emit deleteValue();
    close();
}


