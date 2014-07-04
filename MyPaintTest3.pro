#-------------------------------------------------
#
# Project created by QtCreator 2014-07-02T17:08:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPaintTest3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypaintwidget.cpp \
    shape.cpp \
    widthdialog.cpp

HEADERS  += mainwindow.h \
    mypaintwidget.h \
    shape.h \
    widthdialog.h

FORMS    += mainwindow.ui \
    widthdialog.ui

CONFIG += c++11

RESOURCES += \
    res.qrc
