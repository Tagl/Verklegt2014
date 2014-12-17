#include <algorithm>
#include <fstream>
#include "PersonRepository.h"
#include <Qstring>
#include <sstream>
#include <iostream>
#include "Database.h"
#include <QDebug>
#include "Computer.h"
PersonRepository::PersonRepository()
{

}

std::vector<Person> PersonRepository::getAllDisconnected(int cid)
{
    std::vector<Person> peepz = std::vector<Person>();
    if(!Database::getCurrent()->prepare()) return peepz;
    QSqlQuery query;


    query.prepare("SELECT * FROM Persons WHERE NOT EXISTS (SELECT * FROM Connections WHERE p_id = id AND c_id = :cid)");
    query.bindValue(":cid", cid);
    query.exec();

    while(query.next())
    {
        Person p = Person();
        p.id = query.value("ID").toInt();
        p.firstname = query.value("FirstName").toString().toStdString();
        p.surname = query.value("SurName").toString().toStdString();
        p.gender = query.value("Gender").toString() == "M" ? MALE : FEMALE;
        p.dob = Date::fromString(query.value("DoB").toDate().toString("dd/MM/yyyy"));
        bool temp = query.value("DoD").isNull();
        p.dod = temp ? Date() : Date::fromString(query.value("DoD").toDate().toString("dd/MM/yyyy"));
        p.description = query.value("Description").toString().toStdString();
        peepz.push_back(p);
    }

    return peepz;
}

std::vector<Person> PersonRepository::getAllConnected(int cid)
{
    std::vector<Person> peepz = std::vector<Person>();
    if(!Database::getCurrent()->prepare()) return peepz;
    QSqlQuery query;


    query.prepare("SELECT * FROM Connections c INNER JOIN Persons p ON p.id = c.p_id WHERE c.c_id = :id;");
    query.bindValue(":id", cid);
    query.exec();

    while(query.next())
    {
        Person p = Person();
        p.id = query.value("ID").toInt();
        p.firstname = query.value("FirstName").toString().toStdString();
        p.surname = query.value("SurName").toString().toStdString();
        p.gender = query.value("Gender").toString() == "M" ? MALE : FEMALE;
        p.dob = Date::fromString(query.value("DoB").toDate().toString("dd/MM/yyyy"));
        bool temp = query.value("DoD").isNull();
        p.dod = temp ? Date() : Date::fromString(query.value("DoD").toDate().toString("dd/MM/yyyy"));
        p.description = query.value("Description").toString().toStdString();
        peepz.push_back(p);
    }

    return peepz;
}

std::vector<Person> PersonRepository::getPeople(const PersonSortTypes st, const Order o, std::string sq)
{
    std::vector<Person> peepz = std::vector<Person>();
    if(!Database::getCurrent()->prepare()) return peepz;
    QString search = QString("%") + QString::fromStdString(sq) + QString("%");
    QSqlQuery query;

    std::ostringstream str;
    str << st;
    QString sts = QString::fromStdString(str.str());

    query.prepare("SELECT * FROM persons WHERE FirstName LIKE :search"
               " OR SurName LIKE :search OR Description LIKE :search"
               " ORDER BY " + sts + " " + (o==ASCENDING?"ASC":"DESC"));
    query.bindValue(":search", search);
    query.exec();

    while(query.next())
    {
        Person p = Person();
        p.id = query.value("ID").toInt();
        p.firstname = query.value("FirstName").toString().toStdString();
        p.surname = query.value("SurName").toString().toStdString();
        p.gender = query.value("Gender").toString() == "M" ? MALE : FEMALE;
        p.dob = Date::fromString(query.value("DoB").toDate().toString("dd/MM/yyyy"));
        bool temp = query.value("DoD").isNull();
        p.dod = temp ? Date() : Date::fromString(query.value("DoD").toDate().toString("dd/MM/yyyy"));
        p.description = query.value("Description").toString().toStdString();
        peepz.push_back(p);
    }

    return peepz;
}

void PersonRepository::add(Person p)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    std::string gender;
    std::ostringstream convert;

    convert << p.gender;

    gender = convert.str();

    query.prepare("Insert into persons (FirstName, SurName, DoB, DoD, Gender, Description) VALUES(:firstname, :surname, :dob, :dod, :gender, :description)");
    query.bindValue(":firstname", QString::fromStdString(p.firstname));
    query.bindValue(":surname", QString::fromStdString(p.surname));
    query.bindValue(":dob", p.dob.toQDate());
    query.bindValue(":dod", p.dod.toQDate());
    query.bindValue(":gender",QChar(gender.at(0)));
    query.bindValue(":description", QString::fromStdString(p.description));

    query.exec();

}

void PersonRepository::remove(int id)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    query.prepare(QString("DELETE FROM persons WHERE id=:id;"));
    query.bindValue(":id", id);
    query.exec();
}

const std::string PersonRepository::sortNames[] = {"ID", "Firstname", "Surname", "Gender", "DoB", "DoD"};

std::ostream& operator<<(std::ostream& out, PersonSortTypes st)
{
	out << PersonRepository::sortNames[(int)st];
	return out;
}

std::ostream& operator<<(std::ostream& out, Order o)
{
	out << (o == ASCENDING ? "Ascending" : "Descending");
	return out;
}
