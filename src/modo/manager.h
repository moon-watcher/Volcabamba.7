#pragma once

#include "entity.h"
#include "config/reff.inc"


typedef struct
{
	Entity *entities;
	Entity *prevEntity;
}
Manager;


Manager *manager       ( );
Entity  *managerAdd    ( Manager reff, Entity const* );
void     managerUpdate ( Manager reff );
void     managerEnd    ( Manager reff );


#define managerForeach( M, E ) \
    M->prevEntity = NULL; \
    for ( Entity *E = M->entities; E; E = E->next )


// void managerEntityUpdate ( Manager  reff, Entity  reff );
// void managerEntityDelete ( Manager  reff, Entity  reff );