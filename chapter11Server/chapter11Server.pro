#-------------------------------------------------
#
# Project created by QtCreator 2019-04-23T12:16:07
#
#-------------------------------------------------
QT += network
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chapter11Server
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpserver.cpp \
    tcpsocket.cpp

HEADERS  += widget.h \
    tcpserver.h \
    tcpsocket.h

FORMS    += widget.ui

