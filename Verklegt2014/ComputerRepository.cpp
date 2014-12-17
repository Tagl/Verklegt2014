#include <algorithm>
#include <fstream>
#include "ComputerRepository.h"
#include <Qstring>
#include <sstream>
#include "Database.h"

ComputerRepository::ComputerRepository()
{

}

std::vector<Computer> ComputerRepository::getAllConnected(int pid)
{
    std::vector<Computer> comp = std::vector<Computer>();
    if(!Database::getCurrent()->prepare()) return comp;
    QSqlQuery query;

    query.prepare("SELECT * FROM Connections a INNER JOIN Computers b ON a.c_id = b.id WHERE a.p_id = :pid");
    query.bindValue(":pid", pid);

    query.exec();

    while(query.next())
    {
        Computer c = Computer();
        c.id = query.value("ID").toInt();
        c.name = query.value("Name").toString().toStdString();
        c.computerType = query.value("ComputerType").toString().toStdString();
        c.wasMade = query.value("WasMade").toString() == "Y" ? YES : NO;
        c.yearBuilt = query.value("YearBuilt").toInt();
        c.description = query.value("Description").toString().toStdString();
        comp.push_back(c);
    }
    return comp;
}

std::vector<Computer> ComputerRepository::getAllDisconnected(int pid)
{
    std::vector<Computer> comp = std::vector<Computer>();
    if(!Database::getCurrent()->prepare()) return comp;
    QSqlQuery query;

    query.prepare("SELECT * FROM Computers WHERE NOT EXISTS (SELECT * FROM Connections WHERE c_id = id AND p_id = :pid)");
    query.bindValue(":pid", pid);

    query.exec();

    while(query.next())
    {
        Computer c = Computer();
        c.id = query.value("ID").toInt();
        c.name = query.value("Name").toString().toStdString();
        c.computerType = query.value("ComputerType").toString().toStdString();
        c.wasMade = query.value("WasMade").toString() == "Y" ? YES : NO;
        c.yearBuilt = query.value("YearBuilt").toInt();
        c.description = query.value("Description").toString().toStdString();
        comp.push_back(c);
    }
    return comp;
}

std::vector<Computer> ComputerRepository::getComputers(const ComputerSortTypes st, const Order o, std::string sq)
{    
    std::vector<Computer> comp = std::vector<Computer>();
    if(!Database::getCurrent()->prepare()) return comp;
    QString search = QString("%") + QString::fromStdString(sq) + QString("%");
    QSqlQuery query;

    std::ostringstream str;
    str << st;
    QString sts = QString::fromStdString(str.str());

    query.prepare("SELECT * FROM Computers WHERE Name LIKE :search"
               " OR ComputerType LIKE :search OR Description LIKE :search"
               " ORDER BY "+ sts + " " + QString(o==ASCENDING?"ASC":"DESC"));
    query.bindValue(":search", search);
    query.bindValue(":type", sts);

    query.exec();

    while(query.next())
    {
        Computer c = Computer();
        c.id = query.value("ID").toInt();
        c.name = query.value("Name").toString().toStdString();
        c.computerType = query.value("ComputerType").toString().toStdString();
        c.wasMade = query.value("WasMade").toString() == "Y" ? YES : NO;
        c.yearBuilt = query.value("YearBuilt").toInt();
        c.description = query.value("Description").toString().toStdString();
        comp.push_back(c);
    }
    return comp;
}

void ComputerRepository::add(Computer c)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    std::string wasMade;
    std::ostringstream convert;

    convert << c.wasMade;

    wasMade = convert.str();


    query.prepare("Insert into Computers (Name, ComputerType, WasMade, YearBuilt, Description) VALUES(:name, :computertype, :wasmade, :yearbuilt, :description)");
    query.bindValue(":name", QString::fromStdString(c.name));
    query.bindValue(":computertype", QString::fromStdString(c.computerType));
    query.bindValue(":wasmade", QChar(wasMade.at(0)));
    query.bindValue(":yearbuilt", c.yearBuilt);
    query.bindValue(":description", QString::fromStdString(c.description));

    query.exec();
}

void ComputerRepository::remove(int id)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    query.prepare("DELETE FROM Computers WHERE id=:id;");
    query.bindValue(":id", id);

    query.exec();
}

void ComputerRepository::update(Computer c)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    std::string wasMade;
    std::ostringstream convert;

    convert << c.wasMade;

    wasMade = convert.str();


    query.prepare("UPDATE Computers SET Name = :name, ComputerType = :computertype, WasMade = :wasmade, YearBuilt = :yearbuilt, Description = :description WHERE ID = :id");
    query.bindValue(":id", c.id);
    query.bindValue(":name", QString::fromStdString(c.name));
    query.bindValue(":computertype", QString::fromStdString(c.computerType));
    query.bindValue(":wasmade", QChar(wasMade.at(0)));
    query.bindValue(":yearbuilt", c.yearBuilt);
    query.bindValue(":description", QString::fromStdString(c.description));

    query.exec();
}

const std::string ComputerRepository::sortNames[] = {"ID", "Name", "ComputerType", "WasMade", "YearBuilt"};

std::ostream& operator<<(std::ostream& out, ComputerSortTypes st)
{
    out << ComputerRepository::sortNames[(int)st];
    return out;
}

