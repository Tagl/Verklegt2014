#pragma once
#include <vector>
#include "PersonRepository.h"

class PersonService
{
private:
	PersonRepository repo;
	Order sortOrder;
    PersonSortTypes sortType;
	std::string searchQuery;
public:
	PersonService();
	

	void add(const Person p);
	std::vector<Person> getPeople();

	std::string getQuery();
	void setQuery(const std::string value);

	Order getSortOrder();
	void setSortOrder(const Order value);

    PersonSortTypes getSortType();
    void setSortType(const PersonSortTypes value);
};
