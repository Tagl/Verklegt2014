#pragma once

#include <iostream>
#include "PersonService.h"

class ConsoleUI
{
private:
	static const int NAMEWIDTH = 12, DATEWIDTH = 12, GENDERWIDTH = 8, DESCWIDTH = 22;

	PersonService serv;

	void addPerson();
	void saveMenu();
	void loadMenu();
	void searchMenu();
	void sortMenu();
	void displayPersons();
public:
	void mainMenu();
};