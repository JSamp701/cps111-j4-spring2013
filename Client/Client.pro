#-------------------------------------------------
#
# Project created by QtCreator 2013-02-27T22:09:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    startwindow.cpp \
    scorewindow.cpp

HEADERS  += mainwindow.h \
    startwindow.h \
    scorewindow.h

FORMS    += mainwindow.ui \
    startwindow.ui \
    scorewindow.ui

RESOURCES += \
    resources.qrc
