#pragma once
#include <vector>
#include "../Repositories/PersonRepository.h"

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
    void remove(const int id);
    void update(const Person p);
	std::vector<Person> getPeople();
    std::vector<Person> getConnected(int cid);
    std::vector<Person> getDisconnected(int cid);

	std::string getQuery();
	void setQuery(const std::string value);

	Order getSortOrder();
	void setSortOrder(const Order value);

    PersonSortTypes getSortType();
    void setSortType(const PersonSortTypes value);
};
