TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    location.h \
    locationinfo.h \
    weather.h \
    weather_global.h

SOURCES += \
    location.cpp \
    locationinfo.cpp \
    main.cpp \
    weather.cpp
