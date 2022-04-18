#pragma once

enum
{
    MODO_ENTITY_INIT, 
    MODO_ENTITY_UPDATE,
    MODO_ENTITY_NEWSTATE,
    MODO_ENTITY_DELETE
};


#define execPtrfn(FUNCTION,ENTITY) ({ FUNCTION ? FUNCTION ( ENTITY ) : NULL; })
// #define execPtrfn(FUNCTION,ENTITY) ({ FUNCTION ( ENTITY ); })

#include "system.h"
#include "entity.h"
#include "manager.h"

