#pragma once

#include "entity.h"


typedef struct
{
	Entity *entities;
	Entity *prevEntity;
}
Manager;


Manager *manager       ( );
Entity  *managerAdd    ( Manager*, Entity const* );
void     managerUpdate ( Manager* );
void     managerEnd    ( Manager* );


#define managerForeach( M, E ) \
    M->prevEntity = NULL; \
    for ( Entity *E = M->entities; E; E = E->next )


void managerEntityUpdate ( Manager*, Entity* );
void managerEntityDelete ( Manager*, Entity* );