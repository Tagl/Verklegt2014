#include "Database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.sqlite");
    db.open();
    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS Computers (ID INT PRIMARY KEY  NOT NULL AUTOINCREMENT, Name VARCHAR,ComputerType VARCHAR, YearBuilt INT, WasMade VARCHAR, Description TEXT);");
        query.exec("CREATE TABLE IF NOT EXISTS Persons (ID INT PRIMARY KEY NOT NULL AUTOINCREMENT, FirstName VARCHAR, SurName VARCHAR, DoB DATE, DoD DATE, Gender CHAR);");
        query.exec("CREATE TABLE IF NOT EXISTS Connections(P_ID INT NOT NULL, C_ID INT NOT NULL, PRIMARY KEY (P_ID,C_ID), FOREIGN KEY (C_ID) REFERENCES Computers(ID), FOREIGN KEY (P_ID) REFERENCES Persons(ID));");
    }
}

bool Database::prepare()
{
    if(!db.isOpen()) db.open();
    return db.isOpen();
}

QSqlDatabase Database::getDB()
{
    return db;
}
