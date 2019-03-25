/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QSplitter *splitter;
    QPushButton *pushOK;
    QPushButton *pushCancel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *DisplayLabel;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *EditRow;
    QLineEdit *EditColumn;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *EditValue;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QStringLiteral("EditDialog"));
        EditDialog->resize(400, 300);
        splitter = new QSplitter(EditDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(180, 230, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK = new QPushButton(splitter);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        splitter->addWidget(pushOK);
        pushCancel = new QPushButton(splitter);
        pushCancel->setObjectName(QStringLiteral("pushCancel"));
        splitter->addWidget(pushCancel);
        widget = new QWidget(EditDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 351, 177));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        DisplayLabel = new QLabel(widget);
        DisplayLabel->setObjectName(QStringLiteral("DisplayLabel"));

        verticalLayout_2->addWidget(DisplayLabel);


        verticalLayout_4->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        EditRow = new QLineEdit(widget);
        EditRow->setObjectName(QStringLiteral("EditRow"));

        gridLayout->addWidget(EditRow, 1, 0, 1, 1);

        EditColumn = new QLineEdit(widget);
        EditColumn->setObjectName(QStringLiteral("EditColumn"));

        gridLayout->addWidget(EditColumn, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        EditValue = new QLineEdit(widget);
        EditValue->setObjectName(QStringLiteral("EditValue"));

        verticalLayout_3->addWidget(EditValue);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(EditDialog);
        QObject::connect(pushCancel, SIGNAL(clicked()), EditDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "Dialog", nullptr));
        pushOK->setText(QApplication::translate("EditDialog", "OK", nullptr));
        pushCancel->setText(QApplication::translate("EditDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("EditDialog", "Select Edit Variable", nullptr));
        DisplayLabel->setText(QString());
        label_2->setText(QApplication::translate("EditDialog", "Row", nullptr));
        label_3->setText(QApplication::translate("EditDialog", "Column", nullptr));
        label_4->setText(QApplication::translate("EditDialog", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
