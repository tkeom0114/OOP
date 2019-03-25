#ifndef STRVALUE_H
#define STRVALUE_H

#include <QString>
#include "operand.h"
#include "numeric.h"

class Numeric;
class StrValue;

class StrValue : public Operand
{
public:
    StrValue(QString,QString);
    StrValue();
    ~StrValue();
    virtual void printValue(QTextBrowser*);
    QString getValue()const;
    void setValue(QString);
    friend StrValue operator+(const StrValue &,const StrValue &);
    friend StrValue operator+(const StrValue &,const Numeric &);
    friend StrValue operator*(const StrValue &,const Numeric &);
    friend StrValue operator+(const Numeric &,const StrValue &);
    friend StrValue operator*(const Numeric &,const StrValue &);
private:
    QString value;
};

#endif // STRVALUE_H
