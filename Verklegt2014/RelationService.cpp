#include "RelationService.h"

RelationService::RelationService()
{
    repo = RelationRepository();
}

void RelationService::add(int pid, int cid)
{
    repo.add(pid, cid);
}
