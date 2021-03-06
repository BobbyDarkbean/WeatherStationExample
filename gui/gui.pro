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
    dateselectwidget.h \
    imageloader.h \
    locationselectionwidget.h \
    newlocationdialog.h \
    weatherwidget.h \
    wsgui_shared.h

SOURCES += \
    dateselectwidget.cpp \
    imageloader.cpp \
    locationselectionwidget.cpp \
    newlocationdialog.cpp \
    weatherwidget.cpp

DEFINES += WS_GUI_LIB
