#include "PersonService.h"


PersonService::PersonService()
{
	repo = PersonRepository();
	sortType = NOTHING;
	sortOrder = ASCENDING;
	searchQuery = "";
}
	


void PersonService::add(const Person p)
{
	repo.add(p);
}
std::vector<Person> PersonService::getPeople()
{
	return repo.getPeople(sortType, sortOrder, searchQuery);
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
