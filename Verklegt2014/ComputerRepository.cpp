#include <algorithm>
#include <fstream>
#include "ComputerRepository.h"
#include <Qstring>
#include <sstream>

ComputerRepository::ComputerRepository()
{

}



std::vector<Computer> ComputerRepository::getComputers(const ComputerSortTypes st, const Order o, std::string sq)
{

    std::vector<Computer> comp = std::vector<Computer>();
    QSqlQuery query;
    query.exec(QString("SELECT * FROM Computer WHERE name LIKE \"%") + QString::fromStdString(sq)  + QString("%\""));

    while(query.next())
    {
        Computer c = Computer();
        c.name = query.value("Name").toString().toStdString();
        c.computerType = query.value("ComputerType").toString().toStdString();
        c.wasMade = query.value("WasMade").toChar().toLatin1() == 'Y' ? YES : NO;
        c.yearBuilt = query.value("YearBuilt").toInt();
        c.description = query.value("Description").toString().toStdString();
        comp.push_back(c);
    }

    return comp;
}

void ComputerRepository::add(Computer c)
{

    QSqlQuery query;

    std::string wasMade_;
    std::ostringstream convertWasMade_;

    convertWasMade_ << c.wasMade;

    wasMade_ = convertWasMade_.str();

    query.prepare("Insert into persons (Name, ComputerType, YearBuilt, wasMade, Description)"
                  "VALUES(:name, :computertype, :yearbuilt, :wasmade, :description)");
    query.bindValue(":name", QString::fromStdString(c.name));
    query.bindValue(":computertype", QString::fromStdString(c.computerType));
    query.bindValue(":yearbuilt", c.yearBuilt);
    query.bindValue(":wasmade",QChar(wasMade_.at(0)));
    query.bindValue(":description", QString::fromStdString(c.description));

    query.exec();

}

const std::string ComputerRepository::sortNames[] = {"id", "Name", "ComputerType", "WasMade", "YearBuilt"};

std::ostream& operator<<(std::ostream& out, ComputerSortTypes st)
{

    out << ComputerRepository::sortNames[(int)st];
    return out;
}

