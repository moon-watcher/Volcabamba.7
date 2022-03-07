#pragma once

#include <genesis.h>
#include "listptr.h"


typedef struct Entity
{
    int action:3; // 0: init; 1: update; 2: delete

    int   compsSize:9;
    void* components;
    
    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );

    struct Entity const *template;

    struct EntityExecInterface *exec;
    struct State *state;
}
Entity;


typedef struct EntityExecInterface
{
    #include "config/EntityExecInterface.inc"
}
EntityExecInterface;


typedef struct State
{
    void ( *enter  ) ( Entity * );
    void ( *update ) ( Entity * );
    void ( *exit   ) ( Entity * );
    void *data;
}
State;


typedef listptr Manager;


typedef struct System
{
    void ( *updateFn ) ( void *, int );
    void **list;
    int max;
    char *name;
    int length;
}
System;


void    ecsManagerUpdate    ( Manager * );
void    ecsManagerDelete    ( Manager * );
void    ecsManagerAdd       ( Manager *, Entity * );
Entity* ecsManagerNewEntity ( Manager *, Entity const * );

Entity* ecsEntity           ( Entity const * );
void    ecsEntityState      ( Entity  *, State  const * );
void    ecsEntityDelete     ( Entity  * );

System* ecsSystem           ( System const * );
void    ecsSystemUpdate     ( System * );
void    ecsSystemDelete     ( System * );



#define ecsSystemAdd(SYSTEM,VALUE)            SYSTEM->list [ SYSTEM->length++ ] = VALUE
#define ecsEntityExec(FUNCTION,ENTITY,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })