#pragma once

#include <iostream>
#include "PersonService.h"
#include "ComputerService.h"
#include "RelationService.h"

#define ALIVE Date(0,0,0)

class ConsoleUI
{
private:
    static const int IDWIDTH = 4, NAMEWIDTH = 15, TYPEWIDTH = 20, DATEWIDTH = 12, GENDERWIDTH = 8, DESCWIDTH = 40;

    PersonService pserv;
    ComputerService cserv;
    RelationService rserv;

	void addPerson();
    void addComputer();
    void personSearchMenu();
    void personSortMenu();
    void computerSearchMenu();
    void computerSortMenu();
	void displayPersons();
    void displayComputers();
    void removePerson();
    void removeComputer();
    void connect();
public:
	void mainMenu();
};
