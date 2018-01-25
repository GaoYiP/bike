#-------------------------------------------------
#
# Project created by QtCreator 2018-01-22T10:01:30
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets qml quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = suixinxing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bike_socket/bike_socket.cpp \
    BMap/baidumap.cpp \
    imageButton/imagebutton.cpp \
    signdialog.cpp \
    topwigget.cpp \
    widget.cpp

HEADERS  += mainwindow.h \
    bike_socket/bike_socket.h \
    BMap/baidumap.h \
    imageButton/imagebutton.h \
    signdialog.h \
    topwigget.h \
    widget.h

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    icon.qrc \
    qml.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat
DEFINES += NO_ICONV
include(QZXing/QZXing.pri)
include(deployment.pri)
