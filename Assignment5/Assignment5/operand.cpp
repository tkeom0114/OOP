#include "operand.h"

Operand::Operand(QString _name,QString _type)
{
    name=_name;
    type=_type;
}

Operand::Operand()
{
    ;
}

Operand::~Operand()
{
    ;
}

QString Operand::getName()const
{
    return name;
}

void Operand::setName(QString _name)
{
    name=_name;
}

QString Operand::getType()
{
    return type;
}
