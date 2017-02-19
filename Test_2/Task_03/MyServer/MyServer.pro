QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = MyServer
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp

HEADERS += \
    myserver.h
