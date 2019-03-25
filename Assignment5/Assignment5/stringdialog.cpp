#include "stringdialog.h"
#include "ui_stringdialog.h"
#include "strvalue.h"
#include <list>
#include <QMessageBox>

using namespace std;

extern list<Operand*> Operands;

StringDialog::StringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StringDialog)
{
    ui->setupUi(this);
}

StringDialog::~StringDialog()
{
    delete ui;
}

void StringDialog::on_pushOK_clicked()
{
    QString name=ui->EditName->text();
    QString value=ui->EditValue->text();
    if(name == "result")
    {
        QMessageBox::warning(this,"Error","The variable name(=\"result\")is not available");
        return;
    }
    list<Operand*>::iterator iterEnd=Operands.end();
    for(list<Operand*>::iterator iterPos=Operands.begin();iterPos!=iterEnd;iterPos++)
    {
        if(name==(*iterPos)->getName())
        {
            QMessageBox::warning(this,"Error","The variable name already exists");
            return;
        }
    }
    StrValue* strvalue = new StrValue(name,value);
    Operands.push_back(strvalue);
    emit addString();
    close();
}
