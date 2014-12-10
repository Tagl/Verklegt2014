#include <iomanip>
#include <sstream>
#include "ConsoleUI.h"
using std::cout;
using std::cin;
using std::endl;


void ConsoleUI::mainMenu()
{
    std::string choice = "";
    int ch = 0;
    while(ch != 8)
	{
        cout << "1. Add a person to the database" << endl;
        cout << "2. Add a computer to the database" << endl;
        cout << "3. Display persons" << endl;
        cout << "4. Display computers" << endl;
        cout << "5. Connect a person to a computer" << endl;
        cout << "6. Remove a person from the database" << endl;
        cout << "7. Remove a computer from the database" << endl;
        cout << "8. Exit" << endl;
        std::getline(cin,choice);
        ch = QString::fromStdString(choice).toInt();
        switch(ch)
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
            removePerson();
            break;
        case 7:
            removeComputer();
            break;
        case 8:
            break;
		default:
			cout << "Invalid input! Please try again." << endl;
			break;
		}
	}
}

void ConsoleUI::addPerson()
{
    std::stringstream genstream;
    std::string firstname, surname, genders, dobs, dods, desc;
	Gender gender;
	Date dob, dod;
	cout << "First Name: ";
    std::getline(cin,firstname);
	cout << "Surname: ";
    std::getline(cin,surname);
	while(true)
    {
        genstream.clear();
		cout << "Gender (M/F): ";
        std::getline(cin, genders);
        genstream << genders;
        genstream >> gender;
		if(gender == UNSPECIFIED) cout << "Invalid input!" << endl;
		else break;
	}
	while(true)
	{
		cout << "Date of birth (DD/MM/YYYY): ";
        std::getline(cin,dobs);
        dob = Date::fromString(QString::fromStdString(dobs));
		if(dob.isValid()) break;
		else cout << "Invalid input!" << endl;
	}
	while(true)
	{
        cout << "Leave empty if person is alive" << endl;
		cout << "Date of death (DD/MM/YYYY): ";
        std::getline(cin,dods);
        dod = Date::fromString(QString::fromStdString(dods));
		if(dod == ALIVE || (dod.isValid() && dod > dob)) break;
		else cout << "Invalid input!" << endl;
    }
	cout << "Description: ";
	std::getline(cin, desc);

    pserv.add(Person(firstname, surname, gender, dob, dod, desc));
}

void ConsoleUI::addComputer()
{
    std::stringstream strstream;
    std::string name, computerType, desc, made, year;
    WasMade wasMade = MAYBE;
    int yearBuilt = 0;
    cout << "Name: ";
    std::getline(cin,name);
    cout << "Computer type: ";
    std::getline(cin,computerType);
    while(true)
    {
        strstream.clear();
        cout << "Was the computer made?: ";
        std::getline(cin,made);
        strstream << made;
        strstream >> wasMade;
        if(wasMade == MAYBE) cout << "Invalid input!" << std::endl;
        else break;
    }
    if(wasMade==YES) // Only read building year if it was built
    {
        strstream.clear();
        cout << "Year built: ";
        std::getline(cin,year);
        strstream << year;
        strstream >> yearBuilt;
    }
    cout << "Description: ";
    std::getline(cin, desc);

    cserv.add(Computer(name, computerType, wasMade, yearBuilt, desc));
}

void ConsoleUI::connect()
{
    std::string id;
    std::stringstream str;
    int pid, cid;
    cout << "Enter the person ID: ";
    std::getline(cin,id);
    str << id;
    str >> pid;
    cout << "Enter the computer ID: ";
    std::getline(cin,id);
    str << id;
    str >> cid;

    rserv.add(pid,cid);
}

void ConsoleUI::displayPersons()
{
    char c;
    std::string line;
	do
	{
        std::vector<Person> people = pserv.getPeople();
        cout << "You are sorting by " << pserv.getSortType() << " in " << pserv.getSortOrder() << " order" << (pserv.getQuery() != "" ? " and searching for \"" + pserv.getQuery() + "\"" : "") << endl;
        cout << std::setw(IDWIDTH) << PID;
        cout << std::setw(NAMEWIDTH) << FIRSTNAME;
        cout << std::setw(NAMEWIDTH) << SURNAME;
        cout << std::setw(GENDERWIDTH) << GENDER;
        cout << std::setw(DATEWIDTH) << DOB;
        cout << std::setw(DATEWIDTH) << DOD;
        cout << std::setw(DESCWIDTH) << "Description" << endl;
		for (size_t i = 0; i < people.size(); i++)
		{
			Person p = people.at(i);
            cout << std::setw(IDWIDTH) << p.id;
			cout << std::setw(NAMEWIDTH) << p.firstname;
			cout << std::setw(NAMEWIDTH) << p.surname;
			cout << std::setw(GENDERWIDTH) << p.gender;
			cout << std::setw(DATEWIDTH) << p.dob;
			if(p.dod == ALIVE) cout << std::setw(DATEWIDTH) << "Alive";
			else cout << std::setw(DATEWIDTH) << p.dod;
            cout << std::setw(DESCWIDTH) << (p.description.length() > DESCWIDTH-5 ? p.description.substr(0,DESCWIDTH-5) + "..." : p.description) << endl; // Description may be too long
		}

		cout << "Q to quit, O to change sort order, T to change sort type, S to change search query."<<endl;

        std::getline(cin,line);
        c = line.length() > 0 ? line.at(0) : '\0';
        if(c == 'o' || c == 'O') pserv.setSortOrder((Order)!pserv.getSortOrder());
        else if (c == 't' || c == 'T') personSortMenu();
        else if (c == 's' || c == 'S') personSearchMenu();
	} while(c != 'q' && c != 'Q');
}

void ConsoleUI::displayComputers()
{
    char c;
    std::string line;
    do
    {
        std::vector<Computer> comp = cserv.getComputers();
        cout << "You are sorting by " << cserv.getSortType() << " in " << cserv.getSortOrder() << " order" << (cserv.getQuery() != "" ? " and searching for \"" + cserv.getQuery() + "\"" : "") << endl;
        cout << std::setw(IDWIDTH) << CID;
        cout << std::setw(NAMEWIDTH) << NAME;
        cout << std::setw(TYPEWIDTH) << TYPE;
        cout << std::setw(DATEWIDTH) << WASMADE;
        cout << std::setw(DATEWIDTH) << YEARBUILT;
        cout << std::setw(DESCWIDTH) << "Description" << endl;
        for (size_t i = 0; i < comp.size(); i++)
        {
            Computer c = comp.at(i);
            cout << std::setw(IDWIDTH) << c.id;
            cout << std::setw(NAMEWIDTH) << c.name;
            cout << std::setw(TYPEWIDTH) << c.computerType;
            cout << std::setw(DATEWIDTH) << c.wasMade;
            cout << std::setw(DATEWIDTH);
            if(c.wasMade==YES) cout << c.yearBuilt;
            else cout << "Never";
            cout << std::setw(DESCWIDTH) << (c.description.length() > DESCWIDTH-5 ? c.description.substr(0,DESCWIDTH-5) + "..." : c.description) << endl; // Description may be too long
        }

        cout << "Q to quit, O to change sort order, T to change sort type, S to change search query."<<endl;

        std::getline(cin,line);
        c = line.length() > 0 ? line.at(0) : '\0';
        if(c == 'o' || c == 'O') cserv.setSortOrder((Order)!cserv.getSortOrder());
        else if (c == 't' || c == 'T') computerSortMenu();
        else if (c == 's' || c == 'S') computerSearchMenu();
    } while(c != 'q' && c != 'Q');
}

void ConsoleUI::removePerson()
{
    std::string ids;
    int id = 0;
    cout << "Enter the ID of the person you wish to remove" << endl << "ID: ";
    std::getline(cin, ids);
    id = QString::fromStdString(ids).toInt();
    pserv.remove(id);
}

void ConsoleUI::removeComputer()
{
    std::string ids;
    int id = 0;
    cout << "Enter the ID of the computer you wish to remove" << endl << "ID: ";
    std::getline(cin, ids);
    id = QString::fromStdString(ids).toInt();
    cserv.remove(id);
}

void ConsoleUI::personSortMenu()
{
    std::string choice;
    int ch;
	cout << "Select your desired sorting type." << endl;
    for (int i = 0; i < PERSONSORTCOUNT; i++)
	{
		cout << (i+1) << ". " << PersonRepository::sortNames[i] << endl;
	}
	do
	{
        std::getline(cin,choice);
        ch = QString::fromStdString(choice).toInt();
        if(ch < 1 || ch > PERSONSORTCOUNT) cout << "Invalid input!" << endl;
		else break;
	} while(true);
    pserv.setSortType((PersonSortTypes)(ch-1));
}

void ConsoleUI::personSearchMenu()
{
    std::string s;
	cout << "Input your search: ";
	std::getline(cin, s);
    pserv.setQuery(s);
}

void ConsoleUI::computerSortMenu()
{
    std::string choice;
    int ch;
    cout << "Select your desired sorting type." << endl;
    for (int i = 0; i < COMPUTERSORTCOUNT; i++)
    {
        cout << (i+1) << ". " << ComputerRepository::sortNames[i] << endl;
    }
    do
    {
        std::getline(cin,choice);
        ch = QString::fromStdString(choice).toInt();
        if(ch < 1 || ch > COMPUTERSORTCOUNT) cout << "Invalid input!" << endl;
        else break;
    } while(true);
    cserv.setSortType((ComputerSortTypes)(ch-1));
}

void ConsoleUI::computerSearchMenu()
{
    std::string s;
    cout << "Input your search: ";
    std::getline(cin, s);
    cserv.setQuery(s);
}
