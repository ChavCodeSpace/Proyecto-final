#-------------------------------------------------
#
# Project created by QtCreator 2019-09-20T17:46:11
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pinball
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ball.cpp \
        balloneplayer.cpp \
        dialoglog.cpp \
        game.cpp \
        gamesolo.cpp \
        health.cpp \
        instruccion.cpp \
        levers.cpp \
        loginsolo.cpp \
        main.cpp \
        menu.cpp \
        multilog.cpp \
        nuevousuario.cpp \
        obstaculo.cpp \
        player.cpp

HEADERS += \
    ball.h \
    balloneplayer.h \
    dialoglog.h \
    game.h \
    gamesolo.h \
    health.h \
    instruccion.h \
    levers.h \
    loginsolo.h \
    menu.h \
    multilog.h \
    nuevousuario.h \
    obstaculo.h \
    player.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

FORMS += \
    dialoglog.ui \
    instruccion.ui \
    loginsolo.ui \
    menu.ui \
    multilog.ui \
    nuevousuario.ui
