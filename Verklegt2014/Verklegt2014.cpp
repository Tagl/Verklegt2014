// Verklegt2014.cpp : Defines the entry point for the console application.
//
#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "Database.h"
#include "ConsoleUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

