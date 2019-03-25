#include "matrix.h"
#include "numeric.h"
#include "strvalue.h"

Matrix operator+(const Matrix &a,const Matrix &b)
{
    Matrix c= Matrix("result",a.rows,a.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<a.cols;j++)
            c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
    return c;
}
Matrix operator-(const Matrix &a,const Matrix &b)
{
    Matrix c=Matrix("result",a.rows,a.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<a.cols;j++)
            c.mat[i][j]=a.mat[i][j]-b.mat[i][j];
    return c;
}
Matrix operator*(const Matrix &a,const Matrix &b)
{
    Matrix c=Matrix("result",a.rows,b.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<b.cols;j++)
            for(int k=0;k<a.cols;k++)
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
    return c;
}
Matrix operator+(const Matrix &a,const Numeric &b)
{
    Matrix c=Matrix("result",a.rows,a.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<a.cols;j++)
            c.mat[i][j]=a.mat[i][j]+b.value;
    return c;
}

Matrix operator-(const Matrix &a,const Numeric &b)
{
    Matrix c=Matrix("result",a.rows,a.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<a.cols;j++)
            c.mat[i][j]=a.mat[i][j]-b.value;
    return c;
}
Matrix operator*(const Matrix &a,const Numeric &b)
{
    Matrix c=Matrix("result",a.rows,a.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<a.cols;j++)
            c.mat[i][j]=a.mat[i][j]*b.value;
    return c;
}
Matrix operator/(const Matrix &a,const Numeric &b)
{
    Matrix c=Matrix("result",a.rows,a.cols,0);
    for(int i=0;i<a.rows;i++)
        for(int j=0;j<a.cols;j++)
            c.mat[i][j]=a.mat[i][j]/b.value;
    return c;
}
Matrix operator+(const Numeric &a,const Matrix &b)
{
    return b+a;
}
Matrix operator-(const Numeric &a,const Matrix &b)
{
    return b-a;
}
Matrix operator*(const Numeric &a,const Matrix &b)
{
    return b*a;
}
Matrix operator/(const Numeric &a,const Matrix &b)
{
    return b/a;
}
Numeric operator+(const Numeric &a,const Numeric &b)
{
    return Numeric("result",a.value+b.value);
}
Numeric operator-(const Numeric &a,const Numeric &b)
{
    return Numeric("result",a.value-b.value);
}
Numeric operator*(const Numeric &a,const Numeric &b)
{
    return Numeric("result",a.value*b.value);
}
Numeric operator/(const Numeric &a,const Numeric &b)
{
    return Numeric("result",a.value/b.value);
}
StrValue operator+(const StrValue &a,const StrValue &b)
{
    return StrValue("result",a.value+b.value);
}
StrValue operator+(const StrValue &a,const Numeric &b)
{
    return StrValue("result",a.value+QString::number(b.value));
}
StrValue operator*(const StrValue &a,const Numeric &b)
{
    int c=static_cast<int>(b.value);
    QString curstring="";
    for(int i=0;i<c;i++)
        curstring+=a.value;
    return StrValue("result",curstring);
}
StrValue operator+(const Numeric &a,const StrValue &b)
{
    return StrValue("result",QString::number(a.value)+b.value);
}
StrValue operator*(const Numeric &a,const StrValue &b)
{
    return b*a;
}
