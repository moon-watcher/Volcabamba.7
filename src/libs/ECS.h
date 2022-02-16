#pragma once

#include <genesis.h>
#include "listptr.h"


typedef struct Entity
{
    bool  delete:1;

    int   compsSize:9;
    void* components;
    
    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );

    struct EntityExecInterface *exec;
    struct State *state;
    void *data;

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


void     ecsManagerUpdate ( Manager * );
void     ecsManagerDelete ( Manager * );

Entity*  ecsEntity        ( Manager *, Entity const * );
void     ecsEntityState   ( Entity  *, State  const * );

System*  ecsSystem        ( System const * );
void     ecsSystemUpdate  ( System * );
void     ecsSystemDelete  ( System * );



#define ecsSystemAdd(SYSTEM,VALUE)            SYSTEM->list [ SYSTEM->length++ ] = VALUE
#define ecsEntityExec(ENTITY,FUNCTION,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })