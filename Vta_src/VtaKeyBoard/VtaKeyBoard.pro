#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T10:23:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VtaKeyBoard
TEMPLATE = app


SOURCES += main.cpp\
        vtakeyboard.cpp \
    vtakey.cpp \
    getactivewindow.cpp \
    globlevar.cpp

HEADERS  += vtakeyboard.h \
    vtakey.h \
    getactivewindow.h \
    globlevar.h

FORMS    += vtakeyboard.ui

RESOURCES +=

unix|win32: LIBS += -lQt5Test
