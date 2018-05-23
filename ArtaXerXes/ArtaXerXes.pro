#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T10:58:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArtaXerXes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loby.cpp \
    gamepad.cpp \
    cam.cpp \
    xnetwork.cpp \
    sound.cpp \
    process.cpp \
    packetmaker.cpp \
    deck.cpp \
    keyboard.cpp \
    kinematic.cpp \
    motor.cpp

HEADERS  += mainwindow.h \
    loby.h \
    gamepad.h \
    cam.h \
    xnetwork.h \
    sound.h \
    process.h \
    packetmaker.h \
    deck.h \
    keyboard.h \
    kinematic.h \
    motor.h

FORMS    += mainwindow.ui
#OpenCV needs:
LIBS += `pkg-config opencv --cflags --libs`
#SFML needs:
LIBS += -L/usr/lib/x86_64-linux-gnu \
    -lsfml-window   \
    -lsfml-graphics \
    -lsfml-system

#Zbar needs:
LIBS += -L/usr/lib  \
    -lzbar
