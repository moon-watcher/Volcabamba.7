#include <genesis.h>
#include "manager.h"

#define exec(FUNCTION,ENTITY) ({ FUNCTION ? FUNCTION ( ENTITY ) : NULL; })
// #define exec(FUNCTION,ENTITY) ({ FUNCTION ( ENTITY ); })



static inline void _enterAction  ( Entity*, Manager*, listptrNode* );
static inline void _updateAction ( Entity*, Manager*, listptrNode* );
static inline void _stateAction  ( Entity*, Manager*, listptrNode* );
static inline void _deleteAction ( Entity*, Manager*, listptrNode* );

static void ( *actionsArray [ ] ) ( Entity*, Manager*, listptrNode* ) = { _enterAction, _updateAction, _stateAction, _deleteAction };



Manager *modoManager ( )
{
    Manager *manager = malloc ( sizeof ( Manager ) );

    listptr_init ( &manager->entities, NULL );

    return manager;
}

void modoManagerUpdate ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;

        actionsArray [ entity->action ] ( entity, manager, node );
    }
}


void modoManagerDelete ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;
        
        exec ( entity->state->exit, entity );
        exec ( entity->exit,        entity );
        exec ( entity->Delete,      entity );
    }

    listptr_destroy ( list );
    
    free ( list );
    list = NULL;

    free ( manager );
    manager = NULL;
}


void modoManagerAdd ( Manager *manager, Entity *entity )
{
    listptr *list = &manager->entities;

    listptr_add ( list, entity );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static inline void _enterAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = MODO_ENTITY_UPDATE;
    exec ( entity->Awake,        entity );
    exec ( entity->enter,        entity );
    exec ( entity->state->enter, entity );
}

static inline void _updateAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    exec ( entity->Update,        entity );
    exec ( entity->state->update, entity );
}

static inline void _stateAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = MODO_ENTITY_UPDATE;
    exec ( entity->enter,         entity );
    exec ( entity->state->enter,  entity );
    exec ( entity->Update,        entity );
    exec ( entity->state->update, entity );
}

static inline void _deleteAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    exec ( entity->state->exit, entity );
    exec ( entity->exit,        entity );
    exec ( entity->Delete,      entity );
    listptr_remove ( &manager->entities, node );
}