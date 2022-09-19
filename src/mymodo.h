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
    System const* ( *new    ) ( System const* );
    void          ( *update ) ( System *const );
    void          ( *end    ) ( System *const );
    void          ( *info   ) ( System *const );
}
MODO_SYSTEM_t;

typedef struct {
    Manager const* ( *new    ) ( );
    Entity  const* ( *add    ) ( Manager *const, Entity const* );
    void           ( *update ) ( Manager *const );
    void           ( *end    ) ( Manager *const );
}
MODO_MANAGER_t;

typedef struct {
    Entity const* ( *new    )       ( Entity const* );
    void          ( *state  )       ( Entity *const, State const* );
    void          ( *delete )       ( Entity *const );
    unsigned      ( *stateChanged ) ( Entity *const );
}
MODO_ENTITY_t;

typedef struct {
    MODO_SYSTEM_t  *const system;
    MODO_MANAGER_t *const manager;
    MODO_ENTITY_t  *const entity;

    void ( *init ) ( Entity const* );
} MODO_t;


MODO_t         *const $;
MODO_SYSTEM_t  *const $s;
MODO_MANAGER_t *const $m;
MODO_ENTITY_t  *const $e;




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