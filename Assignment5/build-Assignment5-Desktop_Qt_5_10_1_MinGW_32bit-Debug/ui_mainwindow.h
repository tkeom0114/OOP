/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushMatrix;
    QPushButton *pushPlus;
    QPushButton *pushMinus;
    QPushButton *pushNumeric;
    QPushButton *pushMul;
    QPushButton *pushDiv;
    QPushButton *pushString;
    QPushButton *pushEdit;
    QPushButton *pushDelete;
    QPushButton *pushClear;
    QMenuBar *menuBar;
    QMenu *menu_Result;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 480, 591));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 600, 481, 135));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushMatrix = new QPushButton(widget);
        pushMatrix->setObjectName(QStringLiteral("pushMatrix"));

        gridLayout->addWidget(pushMatrix, 0, 0, 1, 1);

        pushPlus = new QPushButton(widget);
        pushPlus->setObjectName(QStringLiteral("pushPlus"));

        gridLayout->addWidget(pushPlus, 0, 1, 1, 1);

        pushMinus = new QPushButton(widget);
        pushMinus->setObjectName(QStringLiteral("pushMinus"));

        gridLayout->addWidget(pushMinus, 0, 2, 1, 1);

        pushNumeric = new QPushButton(widget);
        pushNumeric->setObjectName(QStringLiteral("pushNumeric"));

        gridLayout->addWidget(pushNumeric, 1, 0, 1, 1);

        pushMul = new QPushButton(widget);
        pushMul->setObjectName(QStringLiteral("pushMul"));

        gridLayout->addWidget(pushMul, 1, 1, 1, 1);

        pushDiv = new QPushButton(widget);
        pushDiv->setObjectName(QStringLiteral("pushDiv"));

        gridLayout->addWidget(pushDiv, 1, 2, 1, 1);

        pushString = new QPushButton(widget);
        pushString->setObjectName(QStringLiteral("pushString"));

        gridLayout->addWidget(pushString, 2, 0, 1, 1);

        pushEdit = new QPushButton(widget);
        pushEdit->setObjectName(QStringLiteral("pushEdit"));

        gridLayout->addWidget(pushEdit, 2, 1, 1, 1);

        pushDelete = new QPushButton(widget);
        pushDelete->setObjectName(QStringLiteral("pushDelete"));

        gridLayout->addWidget(pushDelete, 2, 2, 1, 1);

        pushClear = new QPushButton(widget);
        pushClear->setObjectName(QStringLiteral("pushClear"));

        gridLayout->addWidget(pushClear, 3, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 26));
        menu_Result = new QMenu(menuBar);
        menu_Result->setObjectName(QStringLiteral("menu_Result"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Result->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushMatrix->setText(QApplication::translate("MainWindow", "Matrix", nullptr));
        pushPlus->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushMinus->setText(QApplication::translate("MainWindow", "-", nullptr));
        pushNumeric->setText(QApplication::translate("MainWindow", "Numeric", nullptr));
        pushMul->setText(QApplication::translate("MainWindow", "x", nullptr));
        pushDiv->setText(QApplication::translate("MainWindow", "/", nullptr));
        pushString->setText(QApplication::translate("MainWindow", "String", nullptr));
        pushEdit->setText(QApplication::translate("MainWindow", "Edit Value", nullptr));
        pushDelete->setText(QApplication::translate("MainWindow", "Delete Variable", nullptr));
        pushClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        menu_Result->setTitle(QApplication::translate("MainWindow", "[Result]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
