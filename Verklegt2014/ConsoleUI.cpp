#include <iomanip>
#include "ConsoleUI.h"

using std::cout;
using std::cin;
using std::endl;


void ConsoleUI::mainMenu()
{
	int choice = 0;
    while(choice != 4)
	{
        cout << "1. Add a person to the database" << endl;
        cout << "2. Add a computer to the database" << endl;
        cout << "3. Display persons" << endl;
        cout << "4. Display computers" << endl;
        cout << "5. Connect a person to a computer" <<endl;
        cout << "6. Exit" << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			addPerson();
            break;
		case 2:
            addComputer();
            break;
        case 3:
            displayPersons();
			break;
        case 4:
            displayComputers();
			break;
        case 5:
            connect();
            break;
        case 6:
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
		cout << "Date of birth (DD/MM/YYYY): ";
		cin >> dob;
		if(dob.isValid()) break;
		else cout << "Invalid input!" << endl;
	}
	while(true)
	{
		cout << "If person is still alive enter 1/1/0" << endl;
		cout << "Date of death (DD/MM/YYYY): ";
		cin >> dod;
		if(dod == ALIVE || (dod.isValid() && dod > dob)) break;
		else cout << "Invalid input!" << endl;
	}
	cin.ignore(1, '\n');
	cout << "Description: ";
	std::getline(cin, desc);

	serv.add(Person(firstname, surname, gender, dob, dod, desc));
}

void ConsoleUI::addComputer()
{

}

void ConsoleUI::connect()
{

}

void ConsoleUI::displayPersons()
{
	char c;
	do
	{
		std::vector<Person> people = serv.getPeople();
		cout << "You are sorting by " << serv.getSortType() << " in " << serv.getSortOrder() << " order" << (serv.getQuery() != "" ? " and searching for \"" + serv.getQuery() + "\"" : "") << endl;
		for (size_t i = 0; i < people.size(); i++)
		{
			Person p = people.at(i);
			cout << std::setw(NAMEWIDTH) << p.firstname;
			cout << std::setw(NAMEWIDTH) << p.surname;
			cout << std::setw(GENDERWIDTH) << p.gender;
			cout << std::setw(DATEWIDTH) << p.dob;
			if(p.dod == ALIVE) cout << std::setw(DATEWIDTH) << "Alive";
			else cout << std::setw(DATEWIDTH) << p.dod;
			cout << std::setw(DESCWIDTH) << (p.description.length() > DESCWIDTH-5 ? p.description.substr(0,DESCWIDTH-5) + "..." : p.description) << endl;
		}

		cout << "Q to quit, O to change sort order, T to change sort type, S to change search query."<<endl;
		
		cin >> c;
		if(c == 'o' || c == 'O') serv.setSortOrder((Order)!serv.getSortOrder());
		else if (c == 't' || c == 'T') sortMenu();
		else if (c == 's' || c == 'S') searchMenu();
	} while(c != 'q' && c != 'Q');
}

void ConsoleUI::displayComputers()
{

}


void ConsoleUI::sortMenu()
{
	int choice;
	cout << "Select your desired sorting type." << endl;
	for (int i = 0; i < SORTCOUNT; i++)
	{
		cout << (i+1) << ". " << PersonRepository::sortNames[i] << endl;
	}
	do
	{
		cin >> choice;
		if(choice < 1 || choice > SORTCOUNT) cout << "Invalid input!" << endl;
		else break;
	} while(true);
	serv.setSortType((SortTypes)(choice-1));
}

void ConsoleUI::searchMenu()
{
	std::string s;
	cin.ignore(1,'\n');
	cout << "Input your search: ";
	std::getline(cin, s);
	serv.setQuery(s);
}
