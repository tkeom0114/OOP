#ifndef NUMERIC_H
#define NUMERIC_H

#include "operand.h"
#include "matrix.h"
#include "strvalue.h"
#include <QString>

class Numeric;
class Matrix;
class StrValue;

class Numeric : public Operand
{
public:
    Numeric(QString,double);
    Numeric();
    ~Numeric();
    virtual void printValue(QTextBrowser*);
    double getValue()const;
    void setValue(double);
    friend Numeric operator+(const Numeric&,const Numeric&);
    friend Numeric operator-(const Numeric&,const Numeric&);
    friend Numeric operator*(const Numeric&,const Numeric&);
    friend Numeric operator/(const Numeric&,const Numeric&);
    friend Matrix operator+(const Matrix&,const Numeric&);
    friend Matrix operator-(const Matrix&,const Numeric&);
    friend Matrix operator*(const Matrix&,const Numeric&);
    friend Matrix operator/(const Matrix&,const Numeric&);
    friend Matrix operator+(const Numeric&,const Matrix&);
    friend Matrix operator-(const Numeric&,const Matrix&);
    friend Matrix operator*(const Numeric&,const Matrix&);
    friend Matrix operator/(const Numeric&,const Matrix&);
    friend StrValue operator+(const StrValue &,const Numeric &);
    friend StrValue operator*(const StrValue &,const Numeric &);
    friend StrValue operator+(const Numeric &,const StrValue &);
    friend StrValue operator*(const Numeric &,const StrValue &);
private:
    double value;
};

#endif // NUMERIC_H
