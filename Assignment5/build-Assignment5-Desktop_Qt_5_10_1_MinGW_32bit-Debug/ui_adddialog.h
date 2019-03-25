/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QSplitter *splitter;
    QPushButton *pushOK_2;
    QPushButton *pushCancel_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *labelOperand1;
    QLabel *label_5;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *labelOperand2;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QStringLiteral("AddDialog"));
        AddDialog->resize(400, 300);
        splitter = new QSplitter(AddDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(180, 240, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK_2 = new QPushButton(splitter);
        pushOK_2->setObjectName(QStringLiteral("pushOK_2"));
        splitter->addWidget(pushOK_2);
        pushCancel_2 = new QPushButton(splitter);
        pushCancel_2->setObjectName(QStringLiteral("pushCancel_2"));
        splitter->addWidget(pushCancel_2);
        widget = new QWidget(AddDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 40, 331, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        labelOperand1 = new QLabel(widget);
        labelOperand1->setObjectName(QStringLiteral("labelOperand1"));

        verticalLayout->addWidget(labelOperand1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        labelOperand2 = new QLabel(widget);
        labelOperand2->setObjectName(QStringLiteral("labelOperand2"));

        verticalLayout->addWidget(labelOperand2);


        retranslateUi(AddDialog);
        QObject::connect(pushCancel_2, SIGNAL(clicked()), AddDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QApplication::translate("AddDialog", "Dialog", nullptr));
        pushOK_2->setText(QApplication::translate("AddDialog", "OK", nullptr));
        pushCancel_2->setText(QApplication::translate("AddDialog", "Cancel", nullptr));
        label_4->setText(QApplication::translate("AddDialog", "Operand 1", nullptr));
        labelOperand1->setText(QString());
        label_5->setText(QString());
        label_2->setText(QApplication::translate("AddDialog", "Operand 2", nullptr));
        labelOperand2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
