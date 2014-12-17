#include "RelationRepository.h"
#include "Database.h"

RelationRepository::RelationRepository()
{

}

void RelationRepository::add(int pid, int cid)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    query.prepare("Insert into Connections (P_ID, C_ID) VALUES(:pid, :cid)");
    query.bindValue(":pid", pid);
    query.bindValue(":cid", cid);

    query.exec();
}

void RelationRepository::remove(int pid, int cid)
{
    if(!Database::getCurrent()->prepare()) return;
    QSqlQuery query;

    query.prepare("DELETE FROM Connections WHERE P_ID = :pid AND C_ID = :cid;");
    query.bindValue(":pid", pid);
    query.bindValue(":cid", cid);

    query.exec();
}
