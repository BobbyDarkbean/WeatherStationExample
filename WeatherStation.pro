TEMPLATE = app
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    randomweatherservice.h \
    weather_global.h \
    weather_helper.h \
    weatherservice.h

SOURCES += \
    main.cpp \
    randomweatherservice.cpp \
    weather_helper.cpp \
    weatherservice.cpp
