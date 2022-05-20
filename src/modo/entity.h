#pragma once


enum
{
    MODO_ENTITY_INIT, 
    MODO_ENTITY_UPDATE,
    MODO_ENTITY_DELETE
};


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
    struct State *change;
}
State;

Entity* modoEntity           ( Entity const * );
void    modoEntitySetState   ( Entity *, State const * );
void    modoEntitySetDelete  ( Entity * );
void    modoEntityDelete     ( Entity * );


#define modoEntityExec(FUNCTION,ENTITY,...) ({                                \
    ENTITY->exec->FUNCTION ?                                                  \
        ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) :                      \
        NULL;                                                                 \
    })


#define modoDefineState(STATE,ENTER,UPDATE,EXIT)                              \
    static void STATE##_enter  ( Entity *entity ) ENTER                       \
    static void STATE##_update ( Entity *entity ) UPDATE                      \
    static void STATE##_exit   ( Entity *entity ) EXIT                        \
    State const STATE = {                                                     \
        .enter  = STATE##_enter,                                              \
        .update = STATE##_update,                                             \
        .exit   = STATE##_exit,                                               \
        .change = NULL                                                        \
    };


#define modoDefineEntity(TPL,STATE,COMPS,AWAKE,UPDATE,DELETE)                 \
    static void TPL##_Awake  ( Entity *entity ) AWAKE                         \
    static void TPL##_Update ( Entity *entity ) UPDATE                        \
    static void TPL##_Delete ( Entity *entity ) DELETE                        \
    Entity const TPL = {                                                      \
        .state      = (State*) &STATE,                                        \
        .newState   = NULL                                                    \
        .components = &(Components) COMPS,                                    \
        .compsSize  = sizeof(Components),                                     \
        .action     = 0,                                                      \
        .exec       = NULL,                                                   \
        .Awake      = TPL##_Awake,                                            \
        .Update     = TPL##_Update,                                           \
        .Delete     = TPL##_Delete,                                           \
    };
