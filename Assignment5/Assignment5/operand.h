#ifndef OPERAND_H
#define OPERAND_H

#include <QString>
#include <QTextBrowser>

class Operand;

class Operand
{
public:
    Operand(QString,QString);
    Operand();
    QString getName()const;
    void setName(QString);
    QString getType();
    virtual ~Operand();
    virtual void printValue(QTextBrowser*)=0;
private:
    QString name;
    QString type;
};

#endif // OPERAND_H
