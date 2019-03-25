/********************************************************************************
** Form generated from reading UI file 'numericdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMERICDIALOG_H
#define UI_NUMERICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NumericDialog
{
public:
    QSplitter *splitter;
    QPushButton *pushOK;
    QPushButton *pushCancel;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *EditName;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *EditValue;

    void setupUi(QDialog *NumericDialog)
    {
        if (NumericDialog->objectName().isEmpty())
            NumericDialog->setObjectName(QStringLiteral("NumericDialog"));
        NumericDialog->resize(400, 300);
        splitter = new QSplitter(NumericDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(180, 240, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK = new QPushButton(splitter);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        splitter->addWidget(pushOK);
        pushCancel = new QPushButton(splitter);
        pushCancel->setObjectName(QStringLiteral("pushCancel"));
        splitter->addWidget(pushCancel);
        layoutWidget = new QWidget(NumericDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 331, 119));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        EditName = new QLineEdit(layoutWidget);
        EditName->setObjectName(QStringLiteral("EditName"));

        gridLayout->addWidget(EditName, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        EditValue = new QLineEdit(layoutWidget);
        EditValue->setObjectName(QStringLiteral("EditValue"));

        gridLayout->addWidget(EditValue, 4, 0, 1, 1);


        retranslateUi(NumericDialog);
        QObject::connect(pushCancel, SIGNAL(clicked()), NumericDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(NumericDialog);
    } // setupUi

    void retranslateUi(QDialog *NumericDialog)
    {
        NumericDialog->setWindowTitle(QApplication::translate("NumericDialog", "Dialog", nullptr));
        pushOK->setText(QApplication::translate("NumericDialog", "OK", nullptr));
        pushCancel->setText(QApplication::translate("NumericDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("NumericDialog", "Variable Name", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("NumericDialog", "Initial Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NumericDialog: public Ui_NumericDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMERICDIALOG_H
