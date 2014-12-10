#pragma once
#include <QtSql>

class Database
{
private:
    static Database* current;
    QSqlDatabase db;
public:
    Database();
    bool prepare();
    void close();
    QSqlDatabase getDB();
    static Database* getCurrent();
};
