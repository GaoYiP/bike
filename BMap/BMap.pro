#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T15:16:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BMap
TEMPLATE = app


SOURCES += main.cpp\
        baidumap.cpp

HEADERS  += baidumap.h

CONFIG += mobility
MOBILITY = 

DISTFILES +=

RESOURCES += \
    map.qrc

