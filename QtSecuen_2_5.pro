#-------------------------------------------------
#
# Project created by QtCreator 2012-04-26T19:40:52
#
#-------------------------------------------------

QT       += core gui

TARGET = QrSecuen_2_5
TEMPLATE = app

CONFIG += qt

HEADERS += src/Headers/ventanaprincipal.h \
    src/Headers/ventanamatriz.h \
    src/Headers/convercion.h \
    src/Headers/alinearthread.h \
    src/Headers/puntaje.h \
    src/Headers/exportararchivo.h \
    src/Headers/dialog.h \
    src/Headers/getmatrizthread.h

SOURCES += src/Sources/ventanaprincipal.cpp \
    src/Sources/ventanamatriz.cpp \
    src/Sources/puntaje.cpp \
    src/Sources/main.cpp \
    src/Sources/convercion.cpp \
    src/Sources/alinearthread.cpp \
    src/Sources/exportararchivo.cpp \
    src/Sources/dialog.cpp \
    src/Sources/getmatrizthread.cpp

FORMS += src/Forms/ventanaprincipal.ui \
    src/Forms/ventanamatriz.ui \
    src/Forms/dialog.ui

RESOURCES += \
    Resorucess.qrc




