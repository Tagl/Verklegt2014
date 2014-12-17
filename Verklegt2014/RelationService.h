#pragma once
#include "RelationRepository.h"

class RelationService
{
private:
    RelationRepository repo;
public:
    RelationService();
    void add(int pid, int cid);
    void remove(int pid, int cid);
};
