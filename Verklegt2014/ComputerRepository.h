#pragma once
#include <QtSql>
#include <vector>
#include "Sort.h"
#include "computer.h"

class ComputerRepository
{
private:
    QSqlDatabase db;
    std::vector<Computer> computer;
    std::vector<Computer> search(const std::string sq);
public:
    static const std::string sortNames[];

    ComputerRepository();
    std::vector<Computer> getComputer(const ComputerSortTypes st = CID, const Order o = ASCENDING, std::string search = "");


    std::vector<Computer> getPeople(const ComputerSortTypes st = CID, const Order o = ASCENDING, std::string search = "");

    void add(Computer c);

    friend std::ostream& operator<<(std::ostream& out, ComputerSortTypes st);
    friend std::ostream& operator<<(std::ostream& out, Order o);
};
