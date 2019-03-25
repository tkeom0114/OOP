#ifndef MATRIX_H
#define MATRIX_H

#include "operand.h"
#include "numeric.h"

class Matrix;
class Numeric;

class Matrix : public Operand
{
public:
    Matrix(QString,int,int,double);
    Matrix();
    ~Matrix();
    virtual void printValue(QTextBrowser*);
    int getCols()const;
    int getRows()const;
    double getValue(int,int)const;
    bool setValue(int,int,double);
    friend Matrix operator+(const Matrix&,const Matrix&);
    friend Matrix operator-(const Matrix&,const Matrix&);
    friend Matrix operator*(const Matrix&,const Matrix&);
    friend Matrix operator+(const Matrix&,const Numeric&);
    friend Matrix operator-(const Matrix&,const Numeric&);
    friend Matrix operator*(const Matrix&,const Numeric&);
    friend Matrix operator/(const Matrix&,const Numeric&);
    friend Matrix operator+(const Numeric&,const Matrix&);
    friend Matrix operator-(const Numeric&,const Matrix&);
    friend Matrix operator*(const Numeric&,const Matrix&);
    friend Matrix operator/(const Numeric&,const Matrix&);
private:
    int cols;
    int rows;
    double **mat;
};

#endif // MATRIX_H
