#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T10:08:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP_Project
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
    tile.cpp \
    thing.cpp \
    player.cpp \
    weapon.cpp \
    potion.cpp \
    armor.cpp \
    mover.cpp \
    monster.cpp \
    choosedialog.cpp \
    clickqlabel.cpp \
    endingwidget.cpp \
    helpwidget.cpp

HEADERS += \
        mainwindow.h \
    tile.h \
    thing.h \
    player.h \
    weapon.h \
    potion.h \
    armor.h \
    mover.h \
    monster.h \
    choosedialog.h \
    clickqlabel.h \
    endingwidget.h \
    helpwidget.h

FORMS += \
        mainwindow.ui \
    choosedialog.ui \
    endingwidget.ui \
    helpwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
