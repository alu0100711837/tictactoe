QT += core
QT -= gui

TARGET = TicTacToe
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    gamestatus.cpp \
    player.cpp \
    humanplayer.cpp \
    iaplayer.cpp \
    scoreboard.cpp \
    gameplay.cpp

HEADERS += \
    gamestatus.h \
    player.h \
    humanplayer.h \
    iaplayer.h \
    scoreboard.h \
    gameplay.h



QMAKE_CXXFLAGS += -std=c++0x
