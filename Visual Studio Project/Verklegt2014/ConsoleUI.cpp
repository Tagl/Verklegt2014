#include "ConsoleUI.h"
#include "Person.h"
#include "PersonService.h"

using std::cout;
using std::cin;
using std::endl;


void ConsoleUI::mainMenu()
{
	int choice = 0;
	while(choice != 3)
	{
		cout << "1. Add person to list" << endl;
		cout << "2. Display list" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			addPerson();
			break;
		case 2:
			displayPersons();
			break;
		default:
			cout << "Invalid input! Please try again." << endl;
			break;
		}
	}
}

void ConsoleUI::addPerson()
{
	std::string firstname, surname, desc;
	Gender gender;
	Date dob, dod;
	cout << "First Name: ";
	cin >> firstname;
	cout << "Surname: ";
	cin >> surname;
	while(true)
	{
		cout << "Gender (M/F): ";
		cin >> gender;
		if(gender == UNSPECIFIED) cout << "Invalid input!" << endl;
		else break;
	}
	while(true)
	{
		cout << "Date of birth: ";
		cin >> dob;
		if(dob.isValid()) break;
		else cout << "Invalid input!" << endl;
	}
	cout << "Date of death: ";
	cin >> dod;
	cout << "Description: ";
	cin >> desc;
}

void ConsoleUI::displayPersons()
{
	
}