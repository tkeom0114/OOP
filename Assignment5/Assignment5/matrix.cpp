#include "matrix.h"
#include "numeric.h"

Matrix::Matrix(QString _name, int _rows,int _cols, double _initial):Operand (_name,"Matrix")
{
    rows=_rows;
    cols=_cols;
    mat=static_cast<double**>(malloc(static_cast<unsigned>(rows)*sizeof(double*)));
    for(int i=0;i<rows;i++)
    {
        mat[i]=static_cast<double*>(malloc(static_cast<unsigned>(cols)*sizeof(double)));
        for(int j=0;j<cols;j++)
            mat[i][j]=_initial;
    }

}

Matrix::Matrix():Operand ()
{
    ;
}

Matrix::~Matrix()
{
    ;
}

void Matrix::printValue(QTextBrowser *textBrowser)
{
    textBrowser->append(getName()+" =");
    for(int i=0;i<rows;i++)
    {
        QString curstring ="";
        if(i==0)
            curstring += "{";
        curstring += "[";
        for(int j=0;j<cols;j++)
            curstring += QString::number(mat[i][j])+", ";
        curstring += "]";
        textBrowser->append(curstring);
    }
    textBrowser->append("}");
}

int Matrix::getCols()const
{
    return cols;
}

int Matrix::getRows()const
{
    return rows;
}

double Matrix::getValue(int i,int j)const
{
    return mat[i][j];
}

bool Matrix::setValue(int i,int j,double value)
{
    if(i>=rows || i<0 || j>=cols || j<0)
        return false;
    mat[i][j]=value;
    return true;
}



