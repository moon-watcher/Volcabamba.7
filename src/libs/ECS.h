#pragma once

#include <genesis.h>
#include "listptr.h"


struct Entity;

typedef struct
{
    #include "config/EntityInterface.inc"
}
EntityInterface;


typedef struct Entity
{
    bool  delete:1;

    int   compsSize:9;
    void* components;
    
    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );

    struct State *state;
    void *data;

    EntityInterface *exec;
}
Entity;


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



#define ecsEntityExec(ENTITY,FUNCTION,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })
#define ecsSystemAdd(SYSTEM,VALUE)            SYSTEM->list [ SYSTEM->length++ ] = VALUE
#define ecsExecPtrfn(FUNCTION,VALUE)          if ( FUNCTION ) { FUNCTION ( VALUE ); }