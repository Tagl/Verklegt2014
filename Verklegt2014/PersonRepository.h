#pragma once
#include <QtSql>
#include <vector>
#include "Person.h"

#define SORTCOUNT 6

enum SortTypes { NOTHING = 0, FIRSTNAME, SURNAME, GENDER, DOB, DOD };
enum Order { ASCENDING = 0, DESCENDING };


std::ostream& operator<<(std::ostream& out, SortTypes st);
std::ostream& operator<<(std::ostream& out, Order o);

class PersonRepository
{
private:
    QSqlDatabase db;
public:
	static const std::string sortNames[];

	PersonRepository();

    bool load();
	bool save(const std::string file);

	std::vector<Person> getPeople(const SortTypes st = NOTHING, const Order o = ASCENDING, std::string search = "");
	void add(Person p);
};
