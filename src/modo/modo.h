#pragma once

enum
{
    MODO_ENTITY_INIT, 
    MODO_ENTITY_UPDATE,
    MODO_ENTITY_NEWSTATE,
    MODO_ENTITY_DELETE
};


#include "system.h"
#include "entity.h"
#include "manager.h"


typedef struct EntityExecInterface
{
    #include "config/EntityExecInterface.inc"
}
EntityExecInterface;


#define modoDefineState(STATE,ENTER,UPDATE,EXIT)                         \
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


#define modoSystemAdd(S,V) \
    S->list [ S->length++ ] = V


#define modoEntityExec(F,E,...) \
    ({ E->exec->F ? E->exec->F ( E, __VA_ARGS__ ) : NULL; })


#define modoManagerNewEntity(M,T) \
    ({ Entity *e = modoEntity ( T );  modoManagerAdd ( M, e );  e; })



#include "BaseClass.h"

extern const BaseClass SystemClass;

#define modo(T) \
    ({ T *p = malloc(sizeof(T)); T##Class.constructor(p); p; })


#define $(T) \
    ({ current=T; T; })






