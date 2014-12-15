#include "ComputerService.h"


ComputerService::ComputerService()
{
    repo = ComputerRepository();
    sortType = CID;
    sortOrder = ASCENDING;
    searchQuery = "";
}

void ComputerService::add(const Computer p)
{
    repo.add(p);
}

void ComputerService::remove(const int id)
{
    repo.remove(id);
}

std::vector<Computer> ComputerService::getComputers()
{
    return repo.getComputers(sortType, sortOrder, searchQuery);

}

std::string ComputerService::getQuery()
{
    return searchQuery;
}

void ComputerService::setQuery(const std::string value)
{
    searchQuery = value;
}

Order ComputerService::getSortOrder()
{
    return sortOrder;
}

void ComputerService::setSortOrder(const Order value)
{
    sortOrder = value;
}

ComputerSortTypes ComputerService::getSortType()
{
    return sortType;
}

void ComputerService::setSortType(const ComputerSortTypes value)
{
    sortType = value;
}
