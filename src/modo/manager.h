#pragma once

#include "entity.h"


typedef struct
{
	Entity *entities;
	Entity *prevEntity;
}
Manager;


#define managerForeach( M, E ) \
    M->prevEntity = NULL; \
    for ( Entity *E = M->entities; E; E = E->next )



Manager *manager       ( );
Entity  *managerAdd    ( Manager*, Entity const* );
void     managerUpdate ( Manager* );
void     managerEnd    ( Manager* );