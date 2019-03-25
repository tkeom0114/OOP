#include "strvalue.h"

StrValue::StrValue(QString _name,QString _value):Operand (_name,"String")
{
    value=_value;
}

StrValue::StrValue():Operand ()
{
    ;
}

StrValue::~StrValue()
{
    ;
}

void StrValue::printValue(QTextBrowser *textBrowser)
{
    textBrowser->append(getName()+" =");
    textBrowser->append("\t"+value);
}

void StrValue::setValue(QString _value)
{
    value=_value;
}

QString StrValue::getValue()const
{
    return value;
}

