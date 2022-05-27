#pragma once

#include <genesis.h>


enum EntityAction
{
    ENTITY_ACTION_INIT, 
    ENTITY_ACTION_CHANGE, 
    ENTITY_ACTION_UPDATE,
    ENTITY_ACTION_DELETE,
};


typedef struct Entity
{
    struct State *state;
    void* components;
    int compsSize;
    enum EntityAction action;

    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );
    
    struct Entity *next;
    
    // struct EntityExecInterface *exec;
    // void *whatever;   
}
Entity;


typedef struct State
{
    void ( *enter  ) ( Entity * );
    void ( *update ) ( Entity * );
    void ( *exit   ) ( Entity * );
    struct State *next;
}
State;


Entity *entity       ( Entity const * );
void    entityDelete ( Entity * );
void    entityState  ( Entity *, State const * );
void    entityEnd    ( Entity * );


// typedef struct EntityExecInterface
// {
//     #include "config/EntityExecInterface.inc"
// }
// EntityExecInterface;