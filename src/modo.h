#pragma once

#include "../modo/entity.h"
#include "../modo/system.h"
#include "../modo/manager.h"
#include "inc/entities.h"
#include "inc/systems.h"
#include "inc/managers.h"



// My own Modo API
struct MODO {
    struct MODO_system  {
        System  const* ( *new    ) ( System const* );
        void           ( *update ) ( System *const );
        void           ( *end    ) ( System *const );
        void           ( *info   ) ( System *const );
    } *const system;

    struct MODO_manager {
        Manager const* ( *new    ) ( );
        Entity  const* ( *add    ) ( Manager *const, Entity const* );
        void           ( *update ) ( Manager *const );
        void           ( *end    ) ( Manager *const );
    } *const manager;

    struct MODO_entity  {
        Entity  const* ( *new    ) ( Entity const* );
        void           ( *state  ) ( Entity *const, State const* );
        void           ( *delete ) ( Entity *const );
    } *const entity;
};

struct MODO         *const $;
struct MODO_system  *const $s;
struct MODO_manager *const $m;
struct MODO_entity  *const $e;







// typedef struct {
//     System *( *new    ) ( System const *template );
//     void    ( *update ) ( );
//     void    ( *end    ) ( );
//     void    ( *info   ) ( );
// } 
// SYSTEM;

// typedef struct {
//     Manager *( *new     ) ( );
//     Entity  *( *add     ) ( Entity const* );
//     void     ( *update  ) ( );
//     void     ( *end     ) ( );
// }
// MANAGER;

// typedef struct {
//     Entity *( *new    ) ( Entity const* );
//     void    ( *state  ) ( State const* );
//     void    ( *delete ) ( );
// }
// ENTITY;

// typedef struct {
//     SYSTEM  *const system;
//     MANAGER *const manager;
//     ENTITY  *const entity;
    
//     SYSTEM  *( *s ) ( System  const * );
//     MANAGER *( *m ) ( Manager const * );
//     ENTITY  *( *e ) ( Entity  const * );
// }   
// MODO;

// SYSTEM  *S = &(SYSTEM ) { &system,  &systemUpdate, &systemEnd,     &systemInfo, };
// MANAGER *M = &(MANAGER) { &manager, &managerAdd,   &managerUpdate, &managerEnd, };
// ENTITY  *E = &(ENTITY ) { &entity,  &entityState,  &entityDelete,               };
// MODO    m000 = { S, M, E };
// //MODO    *Modo = &m000;


// static System  * _use_system;
// static Manager * _use_manager;
// static Entity  * _use_entity;

// static SYSTEM  * use_system  ( System  *const x ) { _use_system  = x; return S; }
// static MANAGER * use_manager ( Manager *const x ) { _use_manager = x; return M; }
// static ENTITY  * use_entity  ( Entity  *const x ) { _use_entity  = x; return E; }


// MODO *const Modo = &(MODO) {
//     &(SYSTEM ) { &system,  &systemUpdate, &systemEnd,     &systemInfo, },
//     &(MANAGER) { &manager, &managerAdd,   &managerUpdate, &managerEnd, },
//     &(ENTITY ) { &entity,  &entityState,  &entityDelete,               },

//     &use_system,
//     &use_manager,
//     &use_entity,
// };





// typedef struct {
//     System  *( *new    ) ( System const* );
//     void     ( *update ) ( System *const );
//     void     ( *end    ) ( System *const );
//     void     ( *info   ) ( System *const );
// } 
// SYSTEM;

// typedef struct {
//     Manager *( *new    ) ( );
//     Entity  *( *add    ) ( Manager *const, Entity const* );
//     void     ( *update ) ( Manager *const );
//     void     ( *end    ) ( Manager *const );
// }
// MANAGER;

// typedef struct {
//     Entity  *( *new    ) ( Entity const* );
//     void     ( *state  ) ( Entity *const, State const* );
//     void     ( *delete ) ( Entity *const );
// }
// ENTITY;

// typedef struct {
//     SYSTEM  *const system;
//     MANAGER *const manager;
//     ENTITY  *const entity;
// }
// MODO;

// MODO *const Modo = &(MODO) {
//     &(SYSTEM ) { &system,  &systemUpdate, &systemEnd,     &systemInfo, },
//     &(MANAGER) { &manager, &managerAdd,   &managerUpdate, &managerEnd, },
//     &(ENTITY ) { &entity,  &entityState,  &entityDelete,               },
// };
















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