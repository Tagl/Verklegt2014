#include <algorithm>
#include <fstream>
#include "ComputerRepository.h"
#include <Qstring>
#include <sstream>

ComputerRepository::ComputerRepository()
{

}


std::vector<Computer> ComputerRepository::getPeople(const ComputerSortTypes st, const Order o, std::string sq)
{
   /*
    std::vector<Person> peepz = std::vector<Person>();
    QSqlQuery query;
    query.exec(QString("SELECT * FROM persons WHERE name LIKE \"%") + QString::fromStdString(sq)  + QString("%\""));

    while(query.next())
    {
        Person p = Person();
        p.firstname = query.value("FirstName").toString().toStdString();
        p.surname = query.value("SurName").toString().toStdString();
        p.gender = query.value("Gender").toChar().toLatin1() == 'M' ? MALE : FEMALE;
        p.dob = Date::fromString(query.value("DoB").toDate().toString("dd/MM/yyyy"));
        p.dod = Date::fromString(query.value("DoD").toDate().toString("dd/MM/yyyy"));
        p.description = query.value("Description").toString().toStdString();
        peepz.push_back(p);
    }

    return peepz;
    */
    return std::vector<Computer>();
}

void ComputerRepository::add(Computer c)
{
    /*
    QSqlQuery query;

    std::string _gender;
    std::ostringstream convert_gender;

    convert_gender << p.gender;

    _gender = convert_gender.str();

    query.prepare("Insert into persons (FirstName, SurName, _dob, _dod, _gender, Description)"
                  "VALUES(:firstname, :surname, :dob, :dod, :gender, :description)");
    query.bindValue(":firstname", QString::fromStdString(p.firstname));
    query.bindValue(":surname", QString::fromStdString(p.surname));
    query.bindValue(":dob", p.dob.toQDate());
    query.bindValue(":dod", p.dod.toQDate());
    query.bindValue(":gender",QChar(_gender.at(0)));
    query.bindValue(":description", QString::fromStdString(p.description));

    query.exec();
    */
}
/*
const std::string ComputerRepository::sortNames[] = {"Nothing", "First name", "Surname", "Gender", "Date of birth", "Date of death"};

std::ostream& operator<<(std::ostream& out, SortTypes st)
{

    out << ComputerRepository::sortNames[(int)st];
    return out;
}

std::ostream& operator<<(std::ostream& out, Order o)
{
    out << (o == ASCENDING ? "Ascending" : "Descending");
    return out;
}
*/
