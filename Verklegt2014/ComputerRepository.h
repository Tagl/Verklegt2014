#pragma once
#include <QtSql>
#include <vector>
#include "Sort.h"
#include "Computer.h"

class ComputerRepository
{
private:
    QSqlDatabase db;
    std::vector<Computer> computer;
    std::vector<Computer> search(const std::string sq);
public:
    static const std::string sortNames[];

    ComputerRepository();
    std::vector<Computer> getComputers(const ComputerSortTypes st = CID, const Order o = ASCENDING, std::string search = "");

    void add(Computer c);
    void remove(int id);

    friend std::ostream& operator<<(std::ostream& out, ComputerSortTypes st);

};
