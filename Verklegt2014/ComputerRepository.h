#pragma once
#include <QtSql>
#include <vector>
#include "Computer.h"
#include "Sort.h"

class ComputerRepository
{
private:
    QSqlDatabase db;
    std::vector<Computer> computer;
    std::vector<Computer> search(const std::string sq);
public:
    static const std::string sortNames[];

    ComputerRepository();

    bool load();
    bool save(const std::string file);

    std::vector<Computer> getPeople(const ComputerSortTypes st = CID, const Order o = ASCENDING, std::string search = "");
    void add(Computer c);

    friend std::ostream& operator<<(std::ostream& out, ComputerSortTypes st);
    friend std::ostream& operator<<(std::ostream& out, Order o);
};
