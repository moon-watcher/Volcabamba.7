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

    struct State *state;
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


Manager* ecsManager       ( );
void     ecsManagerUpdate ( Manager * );
void     ecsManagerDelete ( Manager * );

Entity*  ecsEntity        ( Manager *, Entity const * );
void     ecsEntityState   ( Entity  *, State  const * );

System*  ecsSystem        ( System * );
void     ecsSystemUpdate  ( System * );
void     ecsSystemDelete  ( System * );



#define ecsSystemAdd(s,a)  s->list [ s->length++ ] = a
#define ecsExecPtrfn(f,v)  if(f) { f(v); }