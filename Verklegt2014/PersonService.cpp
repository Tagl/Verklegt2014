#include "PersonService.h"
#include <iostream>


PersonService::PersonService()
{
	repo = PersonRepository();
    sortType = PID;
	sortOrder = ASCENDING;
	searchQuery = "";
}
	


void PersonService::add(const Person p)
{
	repo.add(p);
}

void PersonService::remove(const int id)
{
    repo.remove(id);
}

std::vector<Person> PersonService::getPeople()
{
	return repo.getPeople(sortType, sortOrder, searchQuery);
}

std::vector<Person> PersonService::getConnected(int cid)
{
    return repo.getAllConnected(cid);
}

std::vector<Person> PersonService::getDisconnected(int cid)
{
    return repo.getAllDisconnected(cid);
}

std::string PersonService::getQuery()
{
	return searchQuery;
}
void PersonService::setQuery(const std::string value)
{
	searchQuery = value;
}

Order PersonService::getSortOrder()
{
	return sortOrder;
}
void PersonService::setSortOrder(const Order value)
{
	sortOrder = value;
}

PersonSortTypes PersonService::getSortType()
{
	return sortType;
}
void PersonService::setSortType(const PersonSortTypes value)
{
	sortType = value;
}
