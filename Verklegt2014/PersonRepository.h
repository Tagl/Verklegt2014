#pragma once
#include <QtSql>
#include <vector>
#include "Person.h"
#include "Sort.h"



std::ostream& operator<<(std::ostream& out, PersonSortTypes st);
std::ostream& operator<<(std::ostream& out, Order o);

class PersonRepository
{
private:
    QSqlDatabase db;
public:
	static const std::string sortNames[];

	PersonRepository();

    std::vector<Person> getPeople(const PersonSortTypes st = NOTHING, const Order o = ASCENDING, std::string search = "");
	void add(Person p);
    void remove(int id);
};
