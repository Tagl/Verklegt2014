#include "RelationService.h"

RelationService::RelationService()
{
    repo = RelationRepository();
}

void RelationService::add(int pid, int cid)
{
    repo.add(pid, cid);
}

void RelationService::remove(int pid, int cid)
{
    repo.remove(pid, cid);
}
