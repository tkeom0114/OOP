#include "editdialog.h"
#include "ui_editdialog.h"
#include "operand.h"
#include "matrix.h"
#include "numeric.h"
#include "strvalue.h"
#include <list>
#include <QMessageBox>

using namespace std;

extern list<Operand*> Operands;

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    list<Operand*>::iterator iterEnd=Operands.end();
    connect(this->ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(changeLabel(QString)));
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        ui->comboBox->addItem((*iterPos)->getName());
}

void EditDialog::changeLabel(QString name)
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
        this->ui->label_2->setVisible(true);
        this->ui->label_3->setVisible(true);
        this->ui->EditColumn->setVisible(true);
        this->ui->EditRow->setVisible(true);
    }
    else if((*iterPos)->getType()=="Numeric")
    {
        curstring+="Numeric";
        this->ui->label_2->setVisible(false);
        this->ui->label_3->setVisible(false);
        this->ui->EditColumn->setVisible(false);
        this->ui->EditRow->setVisible(false);
    }
    else if((*iterPos)->getType()=="String")
    {
        curstring+="String";
        this->ui->label_2->setVisible(false);
        this->ui->label_3->setVisible(false);
        this->ui->EditColumn->setVisible(false);
        this->ui->EditRow->setVisible(false);
    }
    ui->DisplayLabel->setText(curstring);
    ui->DisplayLabel->show();
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_pushOK_clicked()
{
    list<Operand*>::iterator iterPos=Operands.begin();
    for(int i=0;i<this->ui->comboBox->currentIndex();i++)
        iterPos++;
    if((*iterPos)->getType()=="Matrix")
    {
        int row=ui->EditRow->text().toInt();
        int col=ui->EditColumn->text().toInt();
        double value=ui->EditValue->text().toDouble();
        if(!dynamic_cast<Matrix*>(*iterPos)->setValue(row-1,col-1,value))
        {
            QMessageBox::warning(this,"Error","Row or Column is out of range");
            return;
        }
    }
    else if((*iterPos)->getType()=="Numeric")
    {
        double value=ui->EditValue->text().toDouble();
        dynamic_cast<Numeric*>(*iterPos)->setValue(value);
    }
    else if((*iterPos)->getType()=="String")
    {
        QString value=ui->EditValue->text();
        dynamic_cast<StrValue*>(*iterPos)->setValue(value);
    }
    emit editValue();
    close();
    return;
}
