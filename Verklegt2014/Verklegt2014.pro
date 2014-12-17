#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T15:45:44
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Verklegt2014
CONFIG   += c++11
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    Verklegt2014.cpp \
    Database.cpp \
    Repositories/ComputerRepository.cpp \
    Repositories/PersonRepository.cpp \
    Repositories/RelationRepository.cpp \
    Services/ComputerService.cpp \
    Services/PersonService.cpp \
    Services/RelationService.cpp \
    GUI/AddComputerDialog.cpp \
    GUI/AddScientistDialog.cpp \
    GUI/MainWindow.cpp \
    Models/computer.cpp \
    Models/Date.cpp \
    Models/Person.cpp

HEADERS += \
    Database.h \
    Sort.h \
    Repositories/ComputerRepository.h \
    Repositories/PersonRepository.h \
    Repositories/RelationRepository.h \
    Services/ComputerService.h \
    Services/PersonService.h \
    Services/RelationService.h \
    GUI/AddComputerDialog.h \
    GUI/AddScientistDialog.h \
    GUI/MainWindow.h \
    Models/Computer.h \
    Models/Date.h \
    Models/Person.h

FORMS += \
    GUI/AddComputerDialog.ui \
    GUI/AddScientistDialog.ui \
    GUI/MainWindow.ui
