#include "Database.h"

Database* Database::current = NULL;

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.sqlite");
    db.open();
    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS Computers(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,Name VARCHAR,ComputerType VARCHAR, YearBuilt INT, WasMade VARCHAR, Description TEXT);");
        query.exec("CREATE TABLE IF NOT EXISTS Persons(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,FirstName VARCHAR,SurName VARCHAR,DoB DATE,DoD DATE,Gender CHAR, Description TEXT);");
        query.exec("CREATE TABLE IF NOT EXISTS Connections(P_ID INT NOT NULL, C_ID INT NOT NULL, PRIMARY KEY (P_ID,C_ID), FOREIGN KEY (C_ID) REFERENCES Computers(ID), FOREIGN KEY (P_ID) REFERENCES Persons(ID));");
    }
    current = this;
}

bool Database::prepare()
{
    if(!db.isOpen()) db.open();
    return db.isOpen();
}

void Database::close()
{
    if(db.isOpen()) db.close();
}

QSqlDatabase Database::getDB()
{
    return db;
}

Database* Database::getCurrent()
{
    if(current == NULL) Database();
    return current;
}
