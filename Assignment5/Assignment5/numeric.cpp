#include "numeric.h"
#include "matrix.h"
#include "strvalue.h"

Numeric::Numeric(QString _name,double _value):Operand (_name,"Numeric")
{
    value=_value;
}

Numeric::Numeric():Operand ()
{
    ;
}

Numeric::~Numeric()
{
    ;
}

void Numeric::printValue(QTextBrowser *textBrowser)
{
    textBrowser->append(getName()+" =");
    textBrowser->append("\t"+QString::number(value));
}

double Numeric::getValue()const
{
    return value;
}

void Numeric::setValue(double _value)
{
    value=_value;
}


