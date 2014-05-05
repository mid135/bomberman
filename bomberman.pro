#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T13:53:01
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
INCLUDEPATH += -L/usr/lib/
INCLUDEPATH += -L/usr/lib64/
INCLUDEPATH += -L/usr/include/GL
         LIBS += -lglut


QMAKE_CXXFLAGS +=-o
QMAKE_CXXFLAGS +=opengl1
QMAKE_CXXFLAGS +=-lGL
QMAKE_CXXFLAGS +=-lstdc++
QMAKE_CXXFLAGS +=-lc
QMAKE_CXXFLAGS +=-lm
QMAKE_CXXFLAGS +=-lglut
QMAKE_CXXFLAGS +=-lGLU
QMAKE_CXXFLAGS +=-lglut
QMAKE_CXXFLAGS +=-lGLEW

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
