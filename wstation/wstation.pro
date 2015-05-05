TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += \
    ../kernel \
    ../gui

LIBS += \
    ../bin/libkernel.a \
    ../bin/libgui.a

DESTDIR = ../bin
TARGET = ws

SOURCES += \
    main.cpp
