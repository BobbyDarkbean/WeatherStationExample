TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    weather_global.h \
    weather_helper.h

SOURCES += \
    main.cpp \
    weather_helper.cpp
