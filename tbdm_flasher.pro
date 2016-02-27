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
	mainwindow.cpp \
    bdmdevice.cpp \
    bdmcommand.cpp \
    teensybdmdevice.cpp

HEADERS  += mainwindow.h \
    bdmdevice.h \
    bdmcommand.h \
    teensybdmdevice.h

FORMS    += mainwindow.ui

LIBS += -lusb-1.0

DISTFILES +=
