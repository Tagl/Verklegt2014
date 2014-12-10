#pragma once
#include <QtSql>

class RelationRepository
{
public:
    RelationRepository();
    void add(int pid, int cid);
};
