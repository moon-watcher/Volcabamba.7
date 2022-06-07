#pragma once

#include <genesis.h>


enum EntityAction {
    ENTITY_ACTION_CREATE,
    ENTITY_ACTION_UPDATE,
    ENTITY_ACTION_CHANGE,
    ENTITY_ACTION_DELETE,
};


typedef struct Entity {
    struct State *state;
    struct State *prevState;
    void* components;
    int compsSize:10; // 1kB
    enum EntityAction action;

    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );
    
    void *next;
}
Entity;


typedef struct State {
    void ( *enter  ) ( Entity * );
    void ( *update ) ( Entity * );
    void ( *exit   ) ( Entity * );
    char *name;
}
State;


Entity *entity       ( Entity const * );
void    entityState  ( Entity *, State const * );
void    entityDelete ( Entity * );



// typedef struct Entity {
//     struct State *state;
//     void* components;
//     int compsSize;
//     bool delete;

//     void ( *Awake  ) ( struct Entity * );
//     void ( *Update ) ( struct Entity * );
//     void ( *Delete ) ( struct Entity * );
    
//     struct Entity *next;
    
//     struct EntityExecInterface *exec;
//     void *whatever;   
// }
// Entity;

// typedef struct EntityExecInterface
// {
//     #include "config/EntityExecInterface.inc"
// }
// EntityExecInterface;