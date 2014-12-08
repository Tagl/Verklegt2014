#include <algorithm>
#include <fstream>
#include "PersonRepository.h"

PersonRepository::PersonRepository()
{
	people = std::vector<Person>();
}

bool PersonRepository::load()
{
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("data.sqlite");
    //return db.open();
    return false;
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

std::vector<Person> PersonRepository::search(const std::string sq)
{
	std::vector<Person> peepz = std::vector<Person>();
	for (size_t i = 0; i < people.size(); i++)
	{
		Person p = people.at(i);
		if(p.firstname.find(sq) != -1 || p.surname.find(sq) != -1 || p.description.find(sq) != -1)
		{
			peepz.push_back(p);
		}
	}

	return peepz;
}

std::vector<Person> PersonRepository::getPeople(const SortTypes st, const Order o, std::string sq)
{
    std::vector<Person> peepz;
    //QSqlQuery query;
    //query.exec("SELECT * FROM persons");

    /*while(query.next())
    {
        Person p = Person();
        p.firstname = query.value("FirstName").toString().toStdString();
        p.surname = query.value("Surname").toString().toStdString();
        p.gender = query.value("Gender").toChar().toLatin1() == 'M' ? MALE : FEMALE;
        //p.dob = query.value("dob").toDate();
        //p.dod = query.value("dod").toDate();
        p.description = query.value("Description").toString().toStdString();
        peepz.push_back(p);
    }*/

    return peepz;
}

void PersonRepository::add(Person p)
{
	people.push_back(p);
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
