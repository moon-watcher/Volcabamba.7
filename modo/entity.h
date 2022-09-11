#pragma once

#include "state.h"


enum {
    ENTITY_ACTION_CREATE,
    ENTITY_ACTION_UPDATE,
    ENTITY_ACTION_CHANGE,
    ENTITY_ACTION_DELETE,
};


typedef struct {
    char  *name;
    State *state;     // debería tenerlo el manager? igual 
    State *prevState; // debería tenerlo el manager? igual sí
    void  *components;
    unsigned compsSize:10; // 1024 bytes
    unsigned action:3; // debería tenerlo el manager?

    void ( *Awake  ) ( );
    void ( *Update ) ( );
    void ( *Delete ) ( );
    
    void *exec;
    void *next;  // debería tenerlo el manager!
    // void *COMPS[];
}
Entity;


#define entityExec( INTERFACE, FUNCTION, ENTITY, ... )                \
    if ( ((INTERFACE*) ENTITY->exec)->FUNCTION )                      \
        ((INTERFACE*) ENTITY->exec)->FUNCTION ( ENTITY, __VA_ARGS__ )


Entity *entity        ( Entity const* );
void    entityState   ( Entity *const, State const* );
void    entityDelete  ( Entity *const );


#define entityDefineEx( ENTITY, NAME, TPL, STATE, COMPS, AWAKE, UPDATE, DELETE, EXEC ) \
    static void TPL##_Awake  ( Entity *const ENTITY ) AWAKE           \
    static void TPL##_Update ( Entity *const ENTITY ) UPDATE          \
    static void TPL##_Delete ( Entity *const ENTITY ) DELETE          \
    Entity const TPL = {                                              \
        .state      = (State*) &STATE,                                \
        .components = &(Components) COMPS,                            \
        .compsSize  = sizeof(Components),                             \
        .action     = ENTITY_ACTION_CREATE,                           \
        .Awake      = TPL##_Awake,                                    \
        .Update     = TPL##_Update,                                   \
        .Delete     = TPL##_Delete,                                   \
        .exec       = EXEC,                                           \
        .name       = NAME,                                           \
        .next       = NULL,                                           \
        .prevState  = NULL                                            \
    };

#define entityDefine( TPL, STATE, COMPS, AWAKE, UPDATE, DELETE )      \
    entityDefineEx ( e, NULL, TPL, STATE, COMPS, AWAKE, UPDATE, DELETE, NULL )
