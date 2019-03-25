/********************************************************************************
** Form generated from reading UI file 'deletedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDIALOG_H
#define UI_DELETEDIALOG_H

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

class Ui_DeleteDialog
{
public:
    QSplitter *splitter;
    QPushButton *pushOK;
    QPushButton *pushCancel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *DisplayLabel;

    void setupUi(QDialog *DeleteDialog)
    {
        if (DeleteDialog->objectName().isEmpty())
            DeleteDialog->setObjectName(QStringLiteral("DeleteDialog"));
        DeleteDialog->resize(400, 300);
        splitter = new QSplitter(DeleteDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(190, 230, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK = new QPushButton(splitter);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        splitter->addWidget(pushOK);
        pushCancel = new QPushButton(splitter);
        pushCancel->setObjectName(QStringLiteral("pushCancel"));
        splitter->addWidget(pushCancel);
        widget = new QWidget(DeleteDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 331, 91));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        DisplayLabel = new QLabel(widget);
        DisplayLabel->setObjectName(QStringLiteral("DisplayLabel"));

        verticalLayout_2->addWidget(DisplayLabel);


        retranslateUi(DeleteDialog);
        QObject::connect(pushCancel, SIGNAL(clicked()), DeleteDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(DeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteDialog)
    {
        DeleteDialog->setWindowTitle(QApplication::translate("DeleteDialog", "Dialog", nullptr));
        pushOK->setText(QApplication::translate("DeleteDialog", "OK", nullptr));
        pushCancel->setText(QApplication::translate("DeleteDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("DeleteDialog", "Delete Variable", nullptr));
        label_3->setText(QString());
        DisplayLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteDialog: public Ui_DeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDIALOG_H
