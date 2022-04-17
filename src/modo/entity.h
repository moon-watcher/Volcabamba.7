#pragma once


enum
{
    MODO_ENTITY_INIT, 
    MODO_ENTITY_UPDATE,
    MODO_ENTITY_NEWSTATE,
    MODO_ENTITY_DELETE
};

typedef struct Entity
{
    struct State *state;
    
    void* components;
    int compsSize;
    int action;
    
    struct EntityExecInterface *exec;

    // entity
    void ( *Awake  ) ( struct Entity* );
    void ( *Update ) ( struct Entity* );
    void ( *Delete ) ( struct Entity* );

    // state
    void ( *enter  ) ( struct Entity* ); 
    void ( *exit   ) ( struct Entity* );
}
Entity;


typedef struct EntityExecInterface
{
    #include "config/EntityExecInterface.inc"
}
EntityExecInterface;


typedef struct State
{
    void ( *enter  ) ( Entity* );
    void ( *update ) ( Entity* );
    void ( *exit   ) ( Entity* );
    void *data;
}
State;


void modoEntityInit   ( Entity*, Entity const* );
void modoEntityDelete ( Entity* );
void modoEntityState  ( Entity*, State const* );



#define modoStateDefine(STATE,ENTER,UPDATE,EXIT)                         \
    static void STATE##_enter  ( Entity *entity ) ENTER                  \
    static void STATE##_update ( Entity *entity ) UPDATE                 \
    static void STATE##_exit   ( Entity *entity ) EXIT                   \
    State const STATE = { STATE##_enter, STATE##_update, STATE##_exit };


#define modoDefineEntity(TPL,STATE,COMPS,AWAKE,UPDATE,DELETE,ENTER,EXIT) \
    static void TPL##_Awake  ( Entity *entity ) AWAKE                    \
    static void TPL##_Update ( Entity *entity ) UPDATE                   \
    static void TPL##_Delete ( Entity *entity ) DELETE                   \
    static void TPL##_enter  ( Entity *entity ) ENTER                    \
    static void TPL##_exit   ( Entity *entity ) EXIT                     \
    Entity const TPL = {                                                 \
        .state = (State*) &STATE,                                        \
        .components = &(Components) COMPS,                               \
        .compsSize = sizeof(Components),                                 \
        .action = 0,                                                     \
        .exec = NULL,                                                    \
        .Awake = TPL##_Awake,                                            \
        .Update = TPL##_Update,                                          \
        .Delete = TPL##_Delete,                                          \
        .enter = TPL##_enter,                                            \
        .exit = TPL##_exit,                                              \
    };


#define modoEntityExec(E,F,...)                                          \
    ({ E->exec->F ? E->exec->F ( E, __VA_ARGS__ ) : NULL; })

