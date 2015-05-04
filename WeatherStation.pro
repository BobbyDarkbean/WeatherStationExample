TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    location.h \
    locationinfo.h \
    randomweatherservice.h \
    unitinfo.h \
    unitselector.h \
    weather.h \
    weather_global.h \
    weather_helper.h \
    weatherservice.h

SOURCES += \
    location.cpp \
    locationinfo.cpp \
    main.cpp \
    randomweatherservice.cpp \
    unitinfo.cpp \
    unitselector.cpp \
    weather.cpp \
    weather_helper.cpp \
    weatherservice.cpp
