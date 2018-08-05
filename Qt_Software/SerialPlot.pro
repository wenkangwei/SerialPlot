#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T00:36:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPlot
TEMPLATE = app
CONFIG+=static

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

QT += widgets printsupport \
    serialport
INSTALLS    =target
target.path =/home/pi/Qt-Debug/Debug-SerialPlot
target.files=SerialPlot

#create Makefile
DISTFILES += \
    Makefile
