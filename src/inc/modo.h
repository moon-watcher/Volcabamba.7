#pragma once

#include "genesis.h"
#include "../modo/system.h"
#include "../modo/entity.h"
#include "../modo/manager.h"


/* 

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
//         .newState  = NULL                                                    \
//         .components = &(Components) COMPS,                                    \
//         .compsSize  = sizeof(Components),                                     \
//         .action     = ENTITY_ACTION_INIT,                                     \
//         .exec       = NULL,                                                   \
//         .Awake      = TPL##_Awake,                                            \
//         .Update     = TPL##_Update,                                           \
//         .Delete     = TPL##_Delete,                                           \
//         .whatever   = NULL,                                                   \
//     };





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