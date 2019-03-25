#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrixdialog.h"
#include "numericdialog.h"
#include "stringdialog.h"
#include "deletedialog.h"
#include "editdialog.h"
#include "adddialog.h"
#include "minusdialog.h"
#include "muldialog.h"
#include "divdialog.h"
#include "operand.h"
#include <list>

using namespace std;

list <Operand*> Operands;

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

void MainWindow::printAllValues()
{
    this->ui->textBrowser->clear();
    list<Operand*>::iterator iterEnd=Operands.end();
    for(list<Operand*>::iterator iterPos=Operands.begin();iterPos!=iterEnd;iterPos++)
    {
        (*iterPos)->printValue(this->ui->textBrowser);
    }
}

void MainWindow::on_pushMatrix_clicked()
{
    MatrixDialog *matrixdialog = new MatrixDialog();
    matrixdialog->show();
    QObject::connect(matrixdialog,SIGNAL(addMatrix(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushNumeric_clicked()
{
    NumericDialog *numericdialog = new NumericDialog();
    numericdialog->show();
    QObject::connect(numericdialog,SIGNAL(addNumeric(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushString_clicked()
{
    StringDialog *stringdialog = new StringDialog();
    stringdialog->show();
    QObject::connect(stringdialog,SIGNAL(addString(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushPlus_clicked()
{
    AddDialog *adddialog = new AddDialog();
    adddialog->show();
    QObject::connect(adddialog,SIGNAL(addOperation(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushMinus_clicked()
{
    MinusDialog *minusdialog = new MinusDialog();
    minusdialog->show();
    QObject::connect(minusdialog,SIGNAL(minusOperation(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushMul_clicked()
{
    MulDialog *muldialog = new MulDialog();
    muldialog->show();
    QObject::connect(muldialog,SIGNAL(mulOperation(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushDiv_clicked()
{
    DivDialog *divdialog = new DivDialog();
    divdialog->show();
    QObject::connect(divdialog,SIGNAL(divOperation(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushEdit_clicked()
{
    EditDialog *editdialog = new EditDialog();
    editdialog->show();
    QObject::connect(editdialog,SIGNAL(editValue(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushDelete_clicked()
{
    DeleteDialog *deletedialog = new DeleteDialog();
    deletedialog->show();
    QObject::connect(deletedialog,SIGNAL(deleteValue(void)),this,SLOT(printAllValues(void)));
}

void MainWindow::on_pushClear_clicked()
{
    list<Operand*>::iterator iterEnd=Operands.end();
    for(list<Operand*>::iterator iterPos = Operands.begin();iterPos!=iterEnd;iterPos++)
        delete (*iterPos);
    Operands.clear();
    printAllValues();
}
