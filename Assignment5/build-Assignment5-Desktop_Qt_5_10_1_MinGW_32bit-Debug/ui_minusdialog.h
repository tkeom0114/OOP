/********************************************************************************
** Form generated from reading UI file 'minusdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINUSDIALOG_H
#define UI_MINUSDIALOG_H

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

class Ui_MinusDialog
{
public:
    QSplitter *splitter;
    QPushButton *pushOK_2;
    QPushButton *pushCancel_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *labelOperand1;
    QLabel *label_5;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *labelOperand2;

    void setupUi(QDialog *MinusDialog)
    {
        if (MinusDialog->objectName().isEmpty())
            MinusDialog->setObjectName(QStringLiteral("MinusDialog"));
        MinusDialog->resize(400, 300);
        splitter = new QSplitter(MinusDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(170, 230, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK_2 = new QPushButton(splitter);
        pushOK_2->setObjectName(QStringLiteral("pushOK_2"));
        splitter->addWidget(pushOK_2);
        pushCancel_2 = new QPushButton(splitter);
        pushCancel_2->setObjectName(QStringLiteral("pushCancel_2"));
        splitter->addWidget(pushCancel_2);
        layoutWidget = new QWidget(MinusDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 331, 167));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        labelOperand1 = new QLabel(layoutWidget);
        labelOperand1->setObjectName(QStringLiteral("labelOperand1"));

        verticalLayout->addWidget(labelOperand1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        labelOperand2 = new QLabel(layoutWidget);
        labelOperand2->setObjectName(QStringLiteral("labelOperand2"));

        verticalLayout->addWidget(labelOperand2);


        retranslateUi(MinusDialog);
        QObject::connect(pushCancel_2, SIGNAL(clicked()), MinusDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(MinusDialog);
    } // setupUi

    void retranslateUi(QDialog *MinusDialog)
    {
        MinusDialog->setWindowTitle(QApplication::translate("MinusDialog", "Dialog", nullptr));
        pushOK_2->setText(QApplication::translate("MinusDialog", "OK", nullptr));
        pushCancel_2->setText(QApplication::translate("MinusDialog", "Cancel", nullptr));
        label_4->setText(QApplication::translate("MinusDialog", "Operand 1", nullptr));
        labelOperand1->setText(QString());
        label_5->setText(QString());
        label_2->setText(QApplication::translate("MinusDialog", "Operand 2", nullptr));
        labelOperand2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MinusDialog: public Ui_MinusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINUSDIALOG_H
