#pragma once

#include "entity.h"
#include "config/ref.inc"


typedef struct
{
	Entity *entities;
	Entity *prevEntity;
}
Manager;


Manager *manager       ( );
Entity  *managerAdd    ( Manager ref, Entity const* );
void     managerUpdate ( Manager ref );
void     managerEnd    ( Manager ref );


#define managerForeach( M, E ) \
    M->prevEntity = NULL; \
    for ( Entity *E = M->entities; E; E = E->next )


// void managerEntityUpdate ( Manager  ref, Entity  ref );
// void managerEntityDelete ( Manager  ref, Entity  ref );