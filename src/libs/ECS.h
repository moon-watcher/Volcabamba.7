#pragma once

#include <genesis.h>
#include "listptr.h"

struct Entity;


typedef struct 
{
    void ( *enter  ) ( struct Entity * );
    void ( *update ) ( struct Entity * );
    void ( *exit   ) ( struct Entity * );
}
State;


typedef struct Entity
{
    bool  delete:1;

    int   compsSize:9;
    void* components;
    
    State const *state;

    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );
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
void     ecsManagerUpdate ( Manager * );
void     ecsManagerDelete ( Manager * );

Entity*  ecsEntity        ( Manager *, Entity const * );
void     ecsEntityState   ( Entity  *, State  const * );

System*  ecsSystem        ( System * );
void     ecsSystemInit    ( System * );
void     ecsSystemUpdate  ( System * );
void     ecsSystemDelete  ( System * );



#define SYSTEM1(s,a)        s->list [ s->length++ ] = a;
#define SYSTEM2(s,a,b)      SYSTEM1(s,a); SYSTEM1(s,b);
#define SYSTEM3(s,a,b,c)    SYSTEM1(s,a); SYSTEM1(s,b); SYSTEM1(s,c);
#define SYSTEM4(s,a,b,c,d)  SYSTEM1(s,a); SYSTEM1(s,b); SYSTEM1(s,c); SYSTEM1(s,d);