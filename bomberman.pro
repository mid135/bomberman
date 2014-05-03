#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T13:53:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bomberman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    elements.cpp

HEADERS  += mainwindow.h \
    arena.h \
    elements.h \
    coordinator.h

FORMS    += mainwindow.ui
