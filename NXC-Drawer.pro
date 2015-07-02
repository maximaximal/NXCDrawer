#-------------------------------------------------
#
# Project created by QtCreator 2015-07-02T22:39:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NXC-Drawer
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    NXCDrawingScreen.cpp \
    AddLineStrip.cpp

HEADERS  += MainWindow.hpp \
    NXCDrawingScreen.hpp \
    AddLineStrip.hpp

FORMS    += MainWindow.ui
