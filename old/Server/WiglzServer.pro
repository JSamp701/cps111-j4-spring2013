#-------------------------------------------------
#
# Project created by QtCreator 2013-03-05T16:18:28
#
#-------------------------------------------------

QT       += core gui
QT       += core network

TARGET = WiglzServer
TEMPLATE = app


SOURCES += main.cpp\
        serverwindow.cpp \
    game.cpp \
    world.cpp \
    core.cpp \
    entity.cpp \
    tower.cpp \
    minion.cpp \
    plch.cpp \
    stats.cpp \
    counter.cpp \
    towershots.cpp \
    user.cpp

HEADERS  += serverwindow.h \
    game.h \
    world.h \
    entity.h \
    unit.h \
    core.h \
    tower.h \
    minion.h \
    plch.h \
    stats.h \
    counter.h \
    towershots.h \
    user.h

FORMS    += serverwindow.ui
