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

win32 {
	QMAKE_LFLAGS += -L..\\libusb\\lib
	INCLUDEPATH += ..\\libusb\\include
}

linux {
	INCLUDEPATH += /usr/include/libusb-1.0
}

macx-clang {
	INCLUDEPATH += /usr/local/include/libusb
	QMAKE_LFLAGS += -L/usr/local/lib
}

LIBS += -lusb-1.0

DISTFILES +=

RESOURCES += \
    tbdm_resource.qrc
