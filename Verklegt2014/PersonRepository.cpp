#include <algorithm>
#include <fstream>
#include "PersonRepository.h"
#include <Qstring>
#include <sstream>

PersonRepository::PersonRepository()
{
	people = std::vector<Person>();
}

bool PersonRepository::load()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.sqlite");
    bool o = db.open();
    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS Computers (ID INT PRIMARY KEY  NOT NULL, Name VARCHAR, BuildingYear INT, WasItBuild VARCHAR, Description TEXT);");
        query.exec("CREATE TABLE IF NOT EXISTS Persons (ID INT PRIMARY KEY NOT NULL, FirstName VARCHAR, SurName VARCHAR, DoB DATE, DoD DATE, Gender CHAR);");
        query.exec("CREATE TABLE IF NOT EXISTS Connections(P_ID INT NOT NULL, C_ID INT NOT NULL, PRIMARY KEY (P_ID,C_ID), FOREIGN KEY (C_ID) REFERENCES Computers(ID), FOREIGN KEY (P_ID) REFERENCES Persons(ID));");
    }

    return o;
}

bool PersonRepository::save(const std::string file)
{
	std::ofstream out;
	out.open(file, std::ios_base::out);
	if(out.is_open())
	{
		for (size_t i = 0; i < people.size(); i++)
		{
			if(i!=0) out << std::endl;
			out << people.at(i);
		}
		out.close();
		return true;
	}
	else return false;
}

std::vector<Person> PersonRepository::getPeople(const SortTypes st, const Order o, std::string sq)
{
    std::vector<Person> peepz = std::vector<Person>();
    QSqlQuery query;
    query.exec(QString("SELECT * FROM persons WHERE name LIKE \"%") + QString::fromStdString(sq)  + QString("%\""));

    while(query.next())
    {
        Person p = Person();
        p.firstname = query.value("FirstName").toString().toStdString();
        p.surname = query.value("Surname").toString().toStdString();
        p.gender = query.value("Gender").toChar().toLatin1() == 'M' ? MALE : FEMALE;
        p.dob = Date::fromString(query.value("dob").toDate().toString("dd/MM/yyyy"));
        p.dod = Date::fromString(query.value("dod").toDate().toString("dd/MM/yyyy"));
        p.description = query.value("Description").toString().toStdString();
        peepz.push_back(p);
    }

    return peepz;
}

void PersonRepository::add(Person p)
{
    QSqlQuery query;

    std::string _gender;
    std::ostringstream convert_gender;

    convert_gender << p.gender;


    _gender = convert_gender.str();

    query.prepare("Insert into persons (FirstName, SurName, _dob, _dod, _gender, Description)"
                  "VALUES(:firstname, :surname, :dob, :dod, :gender, :description)");
    query.bindValue(":firstname", QString::fromStdString(p.firstname));
    query.bindValue(":surname", QString::fromStdString(p.surname));
    query.bindValue(":dob", p.dob.toQDate());
    query.bindValue(":dod", p.dod.toQDate());
    query.bindValue(":gender",QChar(_gender.at(0)));
    query.bindValue(":description", QString::fromStdString(p.description));
}

const std::string PersonRepository::sortNames[] = {"Nothing", "First name", "Surname", "Gender", "Date of birth", "Date of death"};

std::ostream& operator<<(std::ostream& out, SortTypes st)
{
	out << PersonRepository::sortNames[(int)st];
	return out;
}

std::ostream& operator<<(std::ostream& out, Order o)
{
	out << (o == ASCENDING ? "Ascending" : "Descending");
	return out;
}
