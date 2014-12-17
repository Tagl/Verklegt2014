#pragma once
#include <QtSql>
#include <vector>
#include "Sort.h"
#include "Computer.h"
#include "Person.h"

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
    std::vector<Computer> getAllConnected(int pid);
    std::vector<Computer> getAllDisconnected(int pid);


    void add(Computer c);
    void remove(int id);
    void update(Computer c);

    friend std::ostream& operator<<(std::ostream& out, ComputerSortTypes st);

};
