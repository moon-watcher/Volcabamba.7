#pragma once

#include "entity.h"


typedef struct ManagerNode
{
	Entity             *entity;
	struct ManagerNode *next;
}
ManagerNode;

typedef struct
{
	ManagerNode *entities;
	ManagerNode *prevNode;
}
Manager;


#define managerForeach( MANAGER, NODE ) \
    MANAGER->prevNode = NULL; \
    for ( ManagerNode *NODE = MANAGER->entities; NODE; NODE = NODE->next )



Manager *manager       ( );
Entity  *managerAdd    ( Manager*, Entity const* );
void     managerUpdate ( Manager* );
void     managerEnd    ( Manager* );