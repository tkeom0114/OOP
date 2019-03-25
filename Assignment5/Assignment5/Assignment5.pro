#-------------------------------------------------
#
# Project created by QtCreator 2018-11-25T14:47:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Assignment5
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    matrixdialog.cpp \
    numericdialog.cpp \
    stringdialog.cpp \
    operand.cpp \
    matrix.cpp \
    numeric.cpp \
    strvalue.cpp \
    deletedialog.cpp \
    editdialog.cpp \
    adddialog.cpp \
    minusdialog.cpp \
    muldialog.cpp \
    divdialog.cpp \
    operator.cpp

HEADERS += \
        mainwindow.h \
    matrixdialog.h \
    numericdialog.h \
    stringdialog.h \
    operand.h \
    matrix.h \
    numeric.h \
    strvalue.h \
    deletedialog.h \
    editdialog.h \
    adddialog.h \
    minusdialog.h \
    muldialog.h \
    divdialog.h

FORMS += \
        mainwindow.ui \
    matrixdialog.ui \
    numericdialog.ui \
    stringdialog.ui \
    deletedialog.ui \
    editdialog.ui \
    adddialog.ui \
    minusdialog.ui \
    muldialog.ui \
    divdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
