#-------------------------------------------------
#
# Project created by QtCreator 2015-07-02T22:39:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NXC-Drawer
TEMPLATE = app

QT += bluetooth
QT += serialport


SOURCES += main.cpp\
        MainWindow.cpp \
    NXCDrawingScreen.cpp \
    AddLineStrip.cpp \
    NXTCommunicator.cpp \
    ConnectNXT.cpp

HEADERS  += MainWindow.hpp \
    NXCDrawingScreen.hpp \
    AddLineStrip.hpp \
    NXTCommunicator.h \
    ConnectNXT.h

FORMS    += MainWindow.ui \
            ConnectNXT.ui

CONFIG += c++11
