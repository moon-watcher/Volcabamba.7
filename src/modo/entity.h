#pragma once

#include <genesis.h>

typedef enum
{
    ENTITY_INIT, 
    ENTITY_CHANGE, 
    ENTITY_UPDATE,
    ENTITY_DELETE,
}
EntityAction;


typedef struct Entity
{
    struct State *state;
    struct State *nextState;
    
    void* components;
    int compsSize;
    EntityAction action;
    
    struct EntityExecInterface *exec;

    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );

    void *whatever;
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


Entity *entity       ( Entity const * );
void    entityDelete ( Entity * );
void    entityState  ( Entity *, State const * );
void    entityEnd    ( Entity * );




// #define modoEntityExec(FUNCTION,ENTITY,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })



// #define DEFINE_STATE(STATE,ENTER,UPDATE,EXIT)                                 \
//     static void STATE##_enter  ( Entity *entity ) ENTER                       \
//     static void STATE##_update ( Entity *entity ) UPDATE                      \
//     static void STATE##_exit   ( Entity *entity ) EXIT                        \
//     State const STATE = {                                                     \
//         .enter  = STATE##_enter,                                              \
//         .update = STATE##_update,                                             \
//         .exit   = STATE##_exit,                                               \
//     };



// #define DEFINE_ENTITY(TPL,STATE,COMPS,AWAKE,UPDATE,DELETE)                    \
//     static void TPL##_Awake  ( Entity *entity ) AWAKE                         \
//     static void TPL##_Update ( Entity *entity ) UPDATE                        \
//     static void TPL##_Delete ( Entity *entity ) DELETE                        \
//     Entity const TPL = {                                                      \
//         .state      = (State*) &STATE,                                        \
//         .nextState  = NULL                                                    \
//         .components = &(Components) COMPS,                                    \
//         .compsSize  = sizeof(Components),                                     \
//         .action     = ENTITY_INIT,                                            \
//         .exec       = NULL,                                                   \
//         .Awake      = TPL##_Awake,                                            \
//         .Update     = TPL##_Update,                                           \
//         .Delete     = TPL##_Delete,                                           \
//         .whatever   = NULL,                                                   \
//     };
