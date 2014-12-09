#pragma once

#include <iostream>
#include "PersonService.h"
#include "ComputerService.h"

#define ALIVE Date(0,1,1)

class ConsoleUI
{
private:
    static const int IDWIDTH = 4 ,NAMEWIDTH = 15, DATEWIDTH = 12, GENDERWIDTH = 8, DESCWIDTH = 40;

	PersonService serv;

	void addPerson();
    void addComputer();
	void searchMenu();
	void sortMenu();
	void displayPersons();
    void displayComputers();
    void connect();
public:
	void mainMenu();
};
