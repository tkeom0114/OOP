#include "numericdialog.h"
#include "ui_numericdialog.h"
#include "numeric.h"
#include <list>
#include <QMessageBox>

using namespace std;

extern list<Operand*> Operands;

NumericDialog::NumericDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumericDialog)
{
    ui->setupUi(this);
}

NumericDialog::~NumericDialog()
{
    delete ui;
}

void NumericDialog::on_pushOK_clicked()
{
    QString name=ui->EditName->text();
    double value=ui->EditValue->text().toDouble();
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
    Numeric* numeric = new Numeric(name,value);
    Operands.push_back(numeric);
    emit addNumeric();
    close();
}
