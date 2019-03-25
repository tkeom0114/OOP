#include "adddialog.h"
#include "ui_adddialog.h"
#include "operand.h"
#include "matrix.h"
#include "numeric.h"
#include "strvalue.h"
#include <list>
#include <QMessageBox>

using namespace std;

extern list<Operand*> Operands;

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    list<Operand*>::iterator iterEnd=Operands.end();
    connect(this->ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(changeLabel1(QString)));
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        ui->comboBox->addItem((*iterPos)->getName());
    ui->comboBox_2->clear();
    connect(this->ui->comboBox_2,SIGNAL(currentTextChanged(QString)),this,SLOT(changeLabel2(QString)));
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        ui->comboBox_2->addItem((*iterPos)->getName());
}

void AddDialog::changeLabel1(QString name)
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
    ui->labelOperand1->setText(curstring);
    ui->labelOperand1->show();
}

void AddDialog::changeLabel2(QString name)
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
    ui->labelOperand2->setText(curstring);
    ui->labelOperand2->show();
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushOK_2_clicked()
{
    list<Operand*>::iterator iterEnd=Operands.end();
    list<Operand*>::iterator iterPos1 = Operands.begin();
    list<Operand*>::iterator iterPos2 = Operands.begin();
    for(iterPos1 = Operands.begin();iterPos1!=iterEnd;iterPos1++)
        if((*iterPos1)->getName()==ui->comboBox->currentText())
            break;
    for(iterPos2 = Operands.begin();iterPos2!=iterEnd;iterPos2++)
        if((*iterPos2)->getName()==ui->comboBox_2->currentText())
            break;
    if(((*iterPos1)->getType()=="Matrix" && (*iterPos2)->getType()=="String")
            || ((*iterPos2)->getType()=="Matrix" && (*iterPos1)->getType()=="String"))
    {
        QMessageBox::warning(this,"Error","Cannot Calculate");
        return;
    }
    Operand *c;
    if((*iterPos1)->getType()=="Matrix" && (*iterPos2)->getType()=="Matrix")
    {
        if(dynamic_cast<Matrix*>(*iterPos1)->getCols()!=dynamic_cast<Matrix*>(*iterPos2)->getCols()
                || dynamic_cast<Matrix*>(*iterPos1)->getRows()!=dynamic_cast<Matrix*>(*iterPos2)->getRows())
        {
            QMessageBox::warning(this,"Error","Cannot Calculate");
            return;
        }        
        Matrix *a=dynamic_cast<Matrix*>((*iterPos1));
        Matrix *b=dynamic_cast<Matrix*>((*iterPos2));
        c= new Matrix((*a)+(*b));
    }
    if((*iterPos1)->getType()=="Matrix" && (*iterPos2)->getType()=="Numeric")
    {
        Matrix *a=dynamic_cast<Matrix*>((*iterPos1));
        Numeric *b=dynamic_cast<Numeric*>((*iterPos2));
        c= new Matrix((*a)+(*b));
    }
    if((*iterPos1)->getType()=="Numeric" && (*iterPos2)->getType()=="Matrix")
    {
        Numeric *a=dynamic_cast<Numeric*>((*iterPos1));
        Matrix *b=dynamic_cast<Matrix*>((*iterPos2));
        c= new Matrix((*a)+(*b));
    }
    if((*iterPos1)->getType()=="Numeric" && (*iterPos2)->getType()=="Numeric")
    {
        Numeric *a=dynamic_cast<Numeric*>((*iterPos1));
        Numeric *b=dynamic_cast<Numeric*>((*iterPos2));
        c= new Numeric((*a)+(*b));
    }
    if((*iterPos1)->getType()=="String" && (*iterPos2)->getType()=="Numeric")
    {
        StrValue *a=dynamic_cast<StrValue*>((*iterPos1));
        Numeric *b=dynamic_cast<Numeric*>((*iterPos2));
        c= new StrValue((*a)+(*b));
    }
    if((*iterPos1)->getType()=="Numeric" && (*iterPos2)->getType()=="String")
    {
        Numeric *a=dynamic_cast<Numeric*>((*iterPos1));
        StrValue *b=dynamic_cast<StrValue*>((*iterPos2));
        c= new StrValue((*a)+(*b));
    }
    if((*iterPos1)->getType()=="String" && (*iterPos2)->getType()=="String")
    {
        StrValue *a=dynamic_cast<StrValue*>((*iterPos1));
        StrValue *b=dynamic_cast<StrValue*>((*iterPos2));
        c= new StrValue((*a)+(*b));
    }
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        if((*iterPos)->getName()=="result")
        {
            delete (*iterPos);
            Operands.erase(iterPos);
        }
    Operands.push_back(c);
    emit addOperation();
    close();
}
