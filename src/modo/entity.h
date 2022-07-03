#pragma once

#include <genesis.h>


enum EntityAction {
    ENTITY_ACTION_CREATE,
    ENTITY_ACTION_UPDATE,
    ENTITY_ACTION_CHANGE,
    ENTITY_ACTION_DELETE,
};


// typedef struct ExecInterface
// {
//     #include "config/ExecInterface.inc"
// }
// ExecInterface;


typedef struct Entity {
    struct State *state;
    struct State *prevState;
    void* components;
    int compsSize:8;
    enum EntityAction action;

    void ( *Awake  ) ( );
    void ( *Update ) ( );
    void ( *Delete ) ( );
    
    // struct ExecInterface *exec;
    // void *whatever;

    void *next;
}
Entity;


typedef struct State {
    void ( *enter  ) ( );
    void ( *update ) ( );
    void ( *exit   ) ( );
    char *name;
}
State;


Entity *entity       ( Entity const* );
void    entityState  ( Entity *const, State const* );
void    entityDelete ( Entity *const );