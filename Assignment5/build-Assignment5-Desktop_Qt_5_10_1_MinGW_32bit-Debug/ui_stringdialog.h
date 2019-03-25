/********************************************************************************
** Form generated from reading UI file 'stringdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRINGDIALOG_H
#define UI_STRINGDIALOG_H

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

class Ui_StringDialog
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
    QSplitter *splitter_2;

    void setupUi(QDialog *StringDialog)
    {
        if (StringDialog->objectName().isEmpty())
            StringDialog->setObjectName(QStringLiteral("StringDialog"));
        StringDialog->resize(400, 300);
        splitter = new QSplitter(StringDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(180, 230, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK = new QPushButton(splitter);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        splitter->addWidget(pushOK);
        pushCancel = new QPushButton(splitter);
        pushCancel->setObjectName(QStringLiteral("pushCancel"));
        splitter->addWidget(pushCancel);
        layoutWidget = new QWidget(StringDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 331, 119));
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

        splitter_2 = new QSplitter(StringDialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(260, 250, 186, 28));
        splitter_2->setOrientation(Qt::Horizontal);

        retranslateUi(StringDialog);
        QObject::connect(pushCancel, SIGNAL(clicked()), StringDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(StringDialog);
    } // setupUi

    void retranslateUi(QDialog *StringDialog)
    {
        StringDialog->setWindowTitle(QApplication::translate("StringDialog", "Dialog", nullptr));
        pushOK->setText(QApplication::translate("StringDialog", "OK", nullptr));
        pushCancel->setText(QApplication::translate("StringDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("StringDialog", "Variable Name", nullptr));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("StringDialog", "Initial Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StringDialog: public Ui_StringDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRINGDIALOG_H
