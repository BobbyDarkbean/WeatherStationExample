TEMPLATE = lib
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin
TARGET = gui

HEADERS += \
    newlocationdialog.h

SOURCES += \
    newlocationdialog.cpp