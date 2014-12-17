#pragma once
#include <vector>
#include "../Repositories/ComputerRepository.h"

class ComputerService
{
private:
    ComputerRepository repo;
    Order sortOrder;
    ComputerSortTypes sortType;
    std::string searchQuery;
public:
    ComputerService();

    void add(const Computer c);
    void remove(const int id);
    void update(const Computer c);
    std::vector<Computer> getComputers();
    std::vector<Computer> getConnected(int pid);
    std::vector<Computer> getDisconnected(int pid);

    std::string getQuery();
    void setQuery(const std::string value);

    Order getSortOrder();
    void setSortOrder(const Order value);

    ComputerSortTypes getSortType();
    void setSortType(const ComputerSortTypes value);
};
