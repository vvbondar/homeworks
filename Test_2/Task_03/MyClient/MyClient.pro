QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = MyClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myclient.cpp

HEADERS += \
    myclient.h
