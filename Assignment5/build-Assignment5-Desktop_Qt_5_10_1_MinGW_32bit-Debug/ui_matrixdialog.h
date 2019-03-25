/********************************************************************************
** Form generated from reading UI file 'matrixdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXDIALOG_H
#define UI_MATRIXDIALOG_H

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

class Ui_MatrixDialog
{
public:
    QSplitter *splitter;
    QPushButton *pushOK;
    QPushButton *pushCancel;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *EditName;
    QLabel *label_5;
    QLineEdit *EditCols;
    QLabel *label_3;
    QLineEdit *EditRows;
    QLabel *label_4;
    QLineEdit *EditValue;

    void setupUi(QDialog *MatrixDialog)
    {
        if (MatrixDialog->objectName().isEmpty())
            MatrixDialog->setObjectName(QStringLiteral("MatrixDialog"));
        MatrixDialog->resize(400, 300);
        splitter = new QSplitter(MatrixDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(180, 240, 186, 28));
        splitter->setOrientation(Qt::Horizontal);
        pushOK = new QPushButton(splitter);
        pushOK->setObjectName(QStringLiteral("pushOK"));
        splitter->addWidget(pushOK);
        pushCancel = new QPushButton(splitter);
        pushCancel->setObjectName(QStringLiteral("pushCancel"));
        splitter->addWidget(pushCancel);
        layoutWidget = new QWidget(MatrixDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 385, 193));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 2);

        EditName = new QLineEdit(layoutWidget);
        EditName->setObjectName(QStringLiteral("EditName"));

        gridLayout->addWidget(EditName, 1, 0, 1, 2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 2);

        EditCols = new QLineEdit(layoutWidget);
        EditCols->setObjectName(QStringLiteral("EditCols"));

        gridLayout->addWidget(EditCols, 4, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        EditRows = new QLineEdit(layoutWidget);
        EditRows->setObjectName(QStringLiteral("EditRows"));

        gridLayout->addWidget(EditRows, 4, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 2);

        EditValue = new QLineEdit(layoutWidget);
        EditValue->setObjectName(QStringLiteral("EditValue"));

        gridLayout->addWidget(EditValue, 7, 0, 1, 2);


        retranslateUi(MatrixDialog);
        QObject::connect(pushCancel, SIGNAL(clicked()), MatrixDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(MatrixDialog);
    } // setupUi

    void retranslateUi(QDialog *MatrixDialog)
    {
        MatrixDialog->setWindowTitle(QApplication::translate("MatrixDialog", "Dialog", nullptr));
        pushOK->setText(QApplication::translate("MatrixDialog", "OK", nullptr));
        pushCancel->setText(QApplication::translate("MatrixDialog", "Cancel", nullptr));
        label_2->setText(QApplication::translate("MatrixDialog", "Rows", nullptr));
        label->setText(QApplication::translate("MatrixDialog", "Variable Name", nullptr));
        label_6->setText(QString());
        label_5->setText(QString());
        label_3->setText(QApplication::translate("MatrixDialog", "Cols", nullptr));
        label_4->setText(QApplication::translate("MatrixDialog", "Initial Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatrixDialog: public Ui_MatrixDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXDIALOG_H
