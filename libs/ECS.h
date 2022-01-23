#pragma once

#include <genesis.h>
#include "listptr.h"

struct Entity;


typedef struct 
{
    char *name;
    void ( *enter  ) ( struct Entity * );
    void ( *update ) ( struct Entity * );
    void *data;
}
State;


typedef struct Entity
{
    bool  delete:1;

    int   compsSize:9;
    void* components;

    State *state;

    void ( *Awake  ) ( struct Entity* );
    void ( *Update ) ( struct Entity* );
    void ( *Delete ) ( struct Entity* );
}
Entity;


typedef struct
{
    listptr entities;
}
Manager;


typedef struct
{
    void ( *updateFn ) ( void *, int );
    void **list;
    int max;
    char *name;
    int length;
}
System;


Manager* ecsManager       ( );
void     ecsManagerUpdate ( Manager *manager );
void     ecsManagerDelete ( Manager *manager );

Entity*  ecsEntity        ( Manager *manager, Entity const *template );
void     ecsEntityState   ( Entity *entity, State *state );

System*  ecsSystem        ( System const *template );
void     ecsSystemInit    ( System *system );
void     ecsSystemUpdate  ( System *system );
void     ecsSystemDelete  ( System *system );