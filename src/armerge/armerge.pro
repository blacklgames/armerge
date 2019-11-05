#-------------------------------------------------
#
# Project created by QtCreator 2019-11-03T14:38:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = armerge
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


SOURCES += \
    controller/commands/command.cpp \
    controller/commands/initcommand.cpp \
    controller/communication/controllerproxy.cpp \
    controller/communication/controllersubject.cpp \
    controller/controller.cpp \
    utils/xml/pugixml.cpp \
    view/communication/viewproxy.cpp \
    view/screens/mergescreen.cpp \
    utils/patterns/observer/observer.cpp \
    utils/patterns/observer/subject.cpp \
    view/mainwindow.cpp \
    main.cpp \
    view/screens/changesscreen.cpp \
    view/communication/viewsubject.cpp

HEADERS += \
    controller/commands/command.h \
    controller/commands/initcommand.h \
    controller/communication/controllerproxy.h \
    controller/communication/controllersubject.h \
    controller/controller.h \
    utils/xml/pugiconfig.hpp \
    utils/xml/pugixml.hpp \
    view/communication/viewproxy.h \
    view/screens/mergescreen.h \
    utils/patterns/observer/observer.h \
    utils/patterns/observer/subject.h \
    view/mainwindow.h \
    view/screens/changesscreen.h \
    view/communication/viewsubject.h

FORMS += \
    forms/changesscreen.ui \
    forms/mainwindow.ui \
    forms/mergescreen.ui

