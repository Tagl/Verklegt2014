#include "ComputerService.h"


ComputerService::ComputerService()
{
    repo = ComputerRepository();
    sortType = CID;
    sortOrder = ASCENDING;
    searchQuery = "";
}

void ComputerService::add(const Computer c)
{
    repo.add(c);
}

void ComputerService::remove(const int id)
{
    repo.remove(id);
}

void ComputerService::update(const Computer c)
{
    repo.update(c);
}


std::vector<Computer> ComputerService::getComputers()
{
    return repo.getComputers(sortType, sortOrder, searchQuery);
}

std::vector<Computer> ComputerService::getConnected(int pid)
{
    return repo.getAllConnected(pid);
}

std::vector<Computer> ComputerService::getDisconnected(int pid)
{
    return repo.getAllDisconnected(pid);
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
