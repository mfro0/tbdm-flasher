#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T14:21:08
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tbdm_flasher
TEMPLATE = app


SOURCES += main.cpp\
    bdmdevice.cpp \
    bdmcommand.cpp \
    teensybdmdevice.cpp \
    flasherwindow.cpp

HEADERS  += \
    bdmdevice.h \
    bdmcommand.h \
    teensybdmdevice.h \
    flasherwindow.h

FORMS    += \
    flasherwindow.ui

LIBS += -lusb-1.0

DISTFILES +=
