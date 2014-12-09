// Verklegt2014.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Database.h"
#include "ConsoleUI.h"

int main(int argc, char *argv[])
{
    Database db;
    ConsoleUI cui = ConsoleUI();
	cui.mainMenu();
    db.getDB().close();
	return 0;
}

