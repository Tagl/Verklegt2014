#pragma once
#include <vector>
#include "Person.h"

#define SORTCOUNT 6

enum SortTypes { NOTHING = 0, FIRSTNAME, SURNAME, GENDER, DOB, DOD };
enum Order { ASCENDING = 0, DESCENDING };

class PersonRepository
{
private:

	std::vector<Person> people;
	std::vector<Person> search(const std::string sq);
public:
	static const std::string sortNames[];

	PersonRepository();

	bool load(const std::string file);
	bool save(const std::string file);

	std::vector<Person> getPeople(const SortTypes st = NOTHING, const Order o = ASCENDING, std::string search = "");
	void add(Person p);

	friend std::ostream& operator<<(std::ostream& out, SortTypes st);
	friend std::ostream& operator<<(std::ostream& out, Order o);
};