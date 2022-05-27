#pragma once

#include "genesis.h"
#include "../modo/system.h"
#include "../modo/entity.h"
#include "../modo/manager.h"



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
//         .action     = ENTITY_ACTION_INIT,                                     \
//         .exec       = NULL,                                                   \
//         .Awake      = TPL##_Awake,                                            \
//         .Update     = TPL##_Update,                                           \
//         .Delete     = TPL##_Delete,                                           \
//         .whatever   = NULL,                                                   \
//     };
