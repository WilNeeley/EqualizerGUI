#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T18:05:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = EqualizerGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    soundprocessor.cpp \
    soundacquirer.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    soundprocessor.h \
    soundacquirer.h

FORMS    += mainwindow.ui
