#pragma once

#include <genesis.h>


typedef struct Entity {
    struct State *state;
    struct State *prevState;
    void* components;
    int compsSize:10; // 1kB
    bool delete:1;

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