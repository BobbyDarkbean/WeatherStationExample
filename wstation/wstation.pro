TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ../bin
TARGET = ws

SOURCES += \
    main.cpp