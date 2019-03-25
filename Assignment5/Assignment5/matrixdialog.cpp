#include "matrixdialog.h"
#include "ui_matrixdialog.h"
#include "matrix.h"
#include <list>
#include <QMessageBox>

using namespace std;

extern list<Operand*> Operands;

MatrixDialog::MatrixDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixDialog)
{
    ui->setupUi(this);
}

MatrixDialog::~MatrixDialog()
{
    delete ui;
}

void MatrixDialog::on_pushOK_clicked()
{
    QString name=ui->EditName->text();
    int rows=ui->EditRows->text().toInt();
    int cols=ui->EditCols->text().toInt();
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
    if(rows<=0 || cols<=0)
    {
        QMessageBox::warning(this,"Error","Rows or Cols must be integer(>=1)");
        return;
    }
    Matrix *matrix = new Matrix(name,rows,cols,value);
    Operands.push_back(matrix);
    emit addMatrix();
    close();
}
