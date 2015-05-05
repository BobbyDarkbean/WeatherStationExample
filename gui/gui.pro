TEMPLATE = lib
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += \
    ../kernel

LIBS += \
    ../bin/libkernel.a

DESTDIR = ../bin
TARGET = gui

HEADERS += \
    newlocationdialog.h \
    wsgui_shared.h

SOURCES += \
    newlocationdialog.cpp

DEFINES += WS_GUI_LIB
