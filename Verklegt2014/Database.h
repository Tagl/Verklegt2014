#pragma once
#include <QtSql>

class Database
{
private:
    QSqlDatabase db;
public:
    Database();
    bool prepare();
    QSqlDatabase getDB();
};
