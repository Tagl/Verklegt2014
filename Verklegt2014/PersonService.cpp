#include "PersonService.h"


PersonService::PersonService()
{
	repo = PersonRepository();
	sortType = NOTHING;
	sortOrder = ASCENDING;
	searchQuery = "";
}
	
bool PersonService::load()
{
    return repo.load();
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

SortTypes PersonService::getSortType()
{
	return sortType;
}
void PersonService::setSortType(const SortTypes value)
{
	sortType = value;
}
