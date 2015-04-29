TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    weather_global.h \
    weather.h

SOURCES += \
    main.cpp \
    weather.cpp

