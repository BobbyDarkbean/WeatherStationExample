TEMPLATE = lib
QT = core

DESTDIR = ../bin
TARGET = kernel

HEADERS += \
    kernel_shared.h \
    location.h \
    locationinfo.h \
    locationpool.h \
    locationselector.h \
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
    locationpool.cpp \
    locationselector.cpp \
    randomweatherservice.cpp \
    unitinfo.cpp \
    unitselector.cpp \
    weather.cpp \
    weather_helper.cpp \
    weatherservice.cpp

DEFINES += WS_KERNEL_LIB
