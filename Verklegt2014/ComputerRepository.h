#pragma once
#include <QtSql>
#include <vector>
#include "Computer.h"


#define SORTCOUNT 6

enum SortTypes { NOTHING = 0, FIRSTNAME, SURNAME, GENDER, DOB, DOD };
enum Order { ASCENDING = 0, DESCENDING };

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

    std::vector<Computer> getPeople(const SortTypes st = NOTHING, const Order o = ASCENDING, std::string search = "");
    void add(Computer c);

    friend std::ostream& operator<<(std::ostream& out, SortTypes st);
    friend std::ostream& operator<<(std::ostream& out, Order o);
};
