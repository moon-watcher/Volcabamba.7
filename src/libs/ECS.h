#pragma once

#include <genesis.h>
#include "listptr.h"



typedef struct Entity
{
    struct State *state;
    
    void* components;
    int compsSize;
    int action;
    
    struct EntityExecInterface *exec;

    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );
    void ( *enter  ) ( struct Entity * ); // state
    void ( *exit   ) ( struct Entity * ); // state
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


typedef struct Manager
{
    listptr entities;
}
Manager;


typedef struct System
{
    void ( *update ) ( void *, int );
    void **list;
    int max;
    char *name;
    int length;
}
System;


typedef void (*ecsSystemUpdateFn) (void*,int);


void    ecsManagerUpdate    ( Manager * );
void    ecsManagerDelete    ( Manager * );
void    ecsManagerAdd       ( Manager *, Entity * );
Entity* ecsManagerNewEntity ( Manager *, Entity const * );

Entity* ecsEntity           ( Entity const * );
void    ecsEntityState      ( Entity *, State const * );
void    ecsEntityDelete     ( Entity * );

System* ecsSystem           ( ecsSystemUpdateFn, int, char* );
void    ecsSystemUpdate     ( System * );
void    ecsSystemDelete     ( System * );



#define ecsSystemAdd(SYSTEM,VALUE)            SYSTEM->list [ SYSTEM->length++ ] = VALUE
#define ecsEntityExec(FUNCTION,ENTITY,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })



#define ecsDefineState(STATE,ENTER,UPDATE,EXIT)                               \
    static void STATE##_enter  ( Entity *entity ) ENTER                       \
    static void STATE##_update ( Entity *entity ) UPDATE                      \
    static void STATE##_exit   ( Entity *entity ) EXIT                        \
    State const STATE = { STATE##_enter, STATE##_update, STATE##_exit };



#define ecsDefineEntity(TPL,STATE,COMPS,AWAKE,UPDATE,DELETE,ENTER,EXIT)       \
    static void TPL##_Awake  ( Entity *entity ) AWAKE                         \
    static void TPL##_Update ( Entity *entity ) UPDATE                        \
    static void TPL##_Delete ( Entity *entity ) DELETE                        \
    static void TPL##_enter  ( Entity *entity ) ENTER                         \
    static void TPL##_exit   ( Entity *entity ) EXIT                          \
    Entity const TPL = {                                                      \
        .state = (State*) &STATE,                                             \
        .components = &(Components) COMPS,                                    \
        .compsSize = sizeof(Components),                                      \
        .action = 0,                                                          \
        .exec = NULL,                                                         \
        .Awake = TPL##_Awake,                                                 \
        .Update = TPL##_Update,                                               \
        .Delete = TPL##_Delete,                                               \
        .enter = TPL##_enter,                                                 \
        .exit = TPL##_exit,                                                   \
    };
