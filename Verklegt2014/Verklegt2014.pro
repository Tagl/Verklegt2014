#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T15:45:44
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Verklegt2014
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ConsoleUI.cpp \
    Date.cpp \
    Person.cpp \
    PersonRepository.cpp \
    PersonService.cpp \
    Verklegt2014.cpp \
    ComputerRepository.cpp \
    ComputerService.cpp \
    RelationRepository.cpp \
    RelationService.cpp \
    Database.cpp \
    mainwindow.cpp \
    AddScientistDialog.cpp \
    AddComputerDialog.cpp \
    Computer.cpp

HEADERS += \
    ConsoleUI.h \
    Date.h \
    Person.h \
    PersonRepository.h \
    PersonService.h \
    ComputerRepository.h \
    ComputerService.h \
    RelationRepository.h \
    RelationService.h \
    Database.h \
    Sort.h \
    mainwindow.h \
    AddScientistDialog.h \
    AddComputerDialog.h \
    Computer.h

FORMS += \
    mainwindow.ui \
    AddScientistDialog.ui \
    AddComputerDialog.ui
