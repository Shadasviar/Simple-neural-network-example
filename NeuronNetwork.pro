#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T16:02:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NeuronNetwork
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kohonennet.cpp \
    neuron.cpp

HEADERS  += mainwindow.h \
    kohonennet.h \
    neuron.h

FORMS    += mainwindow.ui
