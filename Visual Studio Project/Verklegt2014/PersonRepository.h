#pragma once
#include <vector>
#include "Person.h"

enum SortTypes { NOTHING = 0, FIRSTNAME, SURNAME, GENDER, DOB, DOD };
enum Order { ASCENDING = 0, DESCENDING };

class PersonRepository
{
private:
	std::vector<Person> people;
public:
	PersonRepository();
	std::vector<Person> getPeople(const SortTypes st = NOTHING, const Order o = ASCENDING, std::string search = "");
	void add(Person p);
};