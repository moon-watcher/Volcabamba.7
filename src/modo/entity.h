#pragma once

#include <genesis.h>
#include "system.h"


enum {
    ENTITY_ACTION_CREATE,
    ENTITY_ACTION_UPDATE,
    ENTITY_ACTION_CHANGE,
    ENTITY_ACTION_DELETE,
};


typedef struct {
    void ( *enter  ) ( );
    void ( *update ) ( );
    void ( *exit   ) ( );
    char *name;
}
State;


typedef struct {
    char  *name;
    State *state;
    State *prevState;
    void  *components;
    int   compsSize:13;
    int   action:3;

    void ( *Awake  ) ( );
    void ( *Update ) ( );
    void ( *Delete ) ( );
    
    void *exec;
    void *next;
    void *sysnodes;
}
Entity;


#define entityExec( INTERFACE, FUNCTION, ENTITY, ... )                \
    if ( ((INTERFACE*) ENTITY->exec)->FUNCTION )                      \
        ((INTERFACE*) ENTITY->exec)->FUNCTION ( ENTITY, __VA_ARGS__ )


Entity *entity        ( Entity const* );
void    entityState   ( Entity *const, State const* );
void    entityDelete  ( Entity *const );