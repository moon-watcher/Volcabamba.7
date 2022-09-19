#pragma once

// My own Modo API

#include "../modo/entity.h"
#include "../modo/system.h"
#include "../modo/manager.h"
#include "../modo/modo.h"
#include "inc/entities.h"
#include "inc/systems.h"
#include "inc/managers.h"



typedef struct {
    System *( *new    ) ( System const* );
    void    ( *update ) ( System *const );
    void    ( *end    ) ( System *const );
    void    ( *info   ) ( System *const );
}
MYMODO_SYSTEM;

typedef struct {
    Manager *( *new    ) ( );
    Entity  *( *add    ) ( Manager *const, Entity const* );
    void     ( *update ) ( Manager *const );
    void     ( *end    ) ( Manager *const );
}
MYMODO_MANAGER;

typedef struct {
    Entity   *( *new    )       ( Entity const* );
    void      ( *state  )       ( Entity *const, State const* );
    void      ( *delete )       ( Entity *const );
    unsigned  ( *stateChanged ) ( Entity *const );
}
MYMODO_ENTITY;

typedef struct {
    MYMODO_SYSTEM  *const system;
    MYMODO_MANAGER *const manager;
    MYMODO_ENTITY  *const entity;

    void ( *init ) ( Entity const* );
} MYMODO;


MYMODO         *const $;
MYMODO_SYSTEM  *const $s;
MYMODO_MANAGER *const $m;
MYMODO_ENTITY  *const $e;





#define mm_stateDefineEx( ENTITY, NAME, STATE, ENTER, UPDATE, EXIT, COMPS ) \
    static void STATE##_enter  ( Entity *const ENTITY ) { COMPS(ENTITY); ENTER  }   \
    static void STATE##_update ( Entity *const ENTITY ) { COMPS(ENTITY); UPDATE }   \
    static void STATE##_exit   ( Entity *const ENTITY ) { COMPS(ENTITY); EXIT   }   \
    State const STATE = {                                         \
        .enter  = STATE##_enter,                                  \
        .update = STATE##_update,                                 \
        .exit   = STATE##_exit,                                   \
        .name   = NAME,                                           \
    };

#define mm_stateDefine( STATE, ENTER, UPDATE, EXIT )                 \
    mm_stateDefineEx ( e, "", STATE, ENTER, UPDATE, EXIT, COMPS )






#define mm_systemDefineFn( FUNCTION, CODE )      \
    void FUNCTION ( System *const s ) {       \
        void *const *array = (void*) s->list; \
        int length = s->length;               \
        for ( int i = 0; i < length; )        \
            CODE                              \
    }
	
#define mm_systemGetParam( T, V )         \
    T *const V = array [ i++ ]

#define mm_systemAdd1( S, A )             \
    S->list [ S->length++ ] = A;

#define mm_systemAdd2( S, A, B )          \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;

#define mm_systemAdd3( S, A, B, C )       \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;       \
    S->list [ S->length++ ] = C;

#define mm_systemAdd4( S, A, B, C, D )    \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;       \
    S->list [ S->length++ ] = C;       \
    S->list [ S->length++ ] = D;

#define mm_systemAdd5( S, A, B, C, D, E ) \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;       \
    S->list [ S->length++ ] = C;       \
    S->list [ S->length++ ] = D;       \
    S->list [ S->length++ ] = E;







#define mm_entityExec( INTERFACE, FUNCTION, ENTITY, ... )                \
    if ( ((INTERFACE*) ENTITY->exec)->FUNCTION )                      \
        ((INTERFACE*) ENTITY->exec)->FUNCTION ( ENTITY, __VA_ARGS__ )

#define mm_entityDefineEx( ENTITY, NAME, TPL, STATE, COMPS, AWAKE, UPDATE, DELETE, EXEC ) \
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

#define mm_entityDefine( TPL, STATE, COMPS, AWAKE, UPDATE, DELETE )      \
    mm_entityDefineEx ( e, NULL, TPL, STATE, COMPS, AWAKE, UPDATE, DELETE, NULL )



//modo->s(aaa)->update();

/* 
// #define modoEntityExec(FUNCTION,ENTITY,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })

// #define JOY_DIR_NONE    0
// #define JOY_DIR_UP      1
// #define JOY_DIR_DOWN    2
// #define JOY_DIR_LEFT    3
// #define JOY_DIR_RIGHT   4

// #define joy_get_vertical(J,X)          ( joy_##X##_up   ( J ) ? JOY_DIR_UP   : ( joy_##X##_down  ( J ) ? JOY_DIR_DOWN  : JOY_DIR_NONE ) )
// #define joy_get_horizontal(J,X)        ( joy_##X##_left ( J ) ? JOY_DIR_LEFT : ( joy_##X##_right ( J ) ? JOY_DIR_RIGHT : JOY_DIR_NONE ) )

// // #define joy_exec_vertical(J,X,A,B,C)   ( joy_##X##_up   ( J ) ? A            : ( joy_##X##_down  ( J ) ? B             : C            ) )
// // #define joy_exec_horizontal(J,X,A,B,C) ( joy_##X##_left ( J ) ? A            : ( joy_##X##_right ( J ) ? B             : C            ) )

//  #define joy_exec_vertical(J,X,A,B,C) ({   \
//     int ret = JOY_DIR_NONE;                \
//     if ( joy_##X##_up ( J ) ) {            \
//         ret = JOY_DIR_UP;                  \
//         A                                  \
//     } else if ( joy_##X##_down ( J ) ) {   \
//         ret = JOY_DIR_DOWN;                \
//         B                                  \
//     } else {                               \
//         C                                  \
//     }                                      \
//     ret; })

// #define joy_exec_horizontal(J,X,A,B,C) ({  \
//     int ret = JOY_DIR_NONE;                \
//     if ( joy_##X##_left ( J ) ) {          \
//         ret = JOY_DIR_LEFT;                \
//         A                                  \
//     } else if ( joy_##X##_right ( J ) ) {  \
//         ret = JOY_DIR_RIGHT;               \
//         B                                  \
//     } else {                               \
//         C                                  \
//     }                                      \
//     ret; })

*/