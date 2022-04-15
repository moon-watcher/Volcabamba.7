#include <genesis.h>
#include "modo.h"
#include "entity.h"
#include "manager.h"



static inline void _enter  ( Entity*, Manager*, listptrNode* );
static inline void _update ( Entity*, Manager*, listptrNode* );
static inline void _state  ( Entity*, Manager*, listptrNode* );
static inline void _delete ( Entity*, Manager*, listptrNode* );

static void ( *array [ ] ) ( Entity*, Manager*, listptrNode* ) = { _enter, _update, _state, _delete };


void modoManagerInit ( Manager *manager )
{
    // if ( manager->entities )
    // {
    //     listptr_destroy ( &manager->entities );
    // }

    listptr_init ( &manager->entities, NULL );
}


void modoManagerUpdate ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;

        array [ entity->action ] ( entity, manager, node );
    }
}


void modoManagerDelete ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;
        
        if ( entity->state->exit ) entity->state->exit ( entity );
        if ( entity->exit        ) entity->exit        ( entity );
        if ( entity->Delete      ) entity->Delete      ( entity );
    }

    listptr_destroy ( list );
    
    free ( list );
    list = NULL;

    free ( manager );
    manager = NULL;
}


void modoManagerAdd ( Manager *manager, Entity *entity )
{
    listptr_add ( &manager->entities, entity );
}



//////////////////////////////////////////////////////////////////////////////



static inline void _enter ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = MODO_ENTITY_UPDATE;
    
    if  ( entity->Awake        ) entity->Awake        ( entity );
    if  ( entity->enter        ) entity->enter        ( entity );
    if  ( entity->state->enter ) entity->state->enter ( entity );
}

static inline void _update ( Entity *entity, Manager *manager, listptrNode *node )
{
    if ( entity->Update        ) entity->Update        ( entity );
    if ( entity->state->update ) entity->state->update ( entity );
}

static inline void _state ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = MODO_ENTITY_UPDATE;

    if ( entity->enter         ) entity->enter         ( entity );
    if ( entity->state->enter  ) entity->state->enter  ( entity );
    if ( entity->Update        ) entity->Update        ( entity );
    if ( entity->state->update ) entity->state->update ( entity );
}

static inline void _delete ( Entity *entity, Manager *manager, listptrNode *node )
{
    if ( entity->state->exit ) entity->state->exit ( entity );
    if ( entity->exit        ) entity->exit        ( entity );
    if ( entity->Delete      ) entity->Delete      ( entity );
    
    listptr_remove ( &manager->entities, node );
}