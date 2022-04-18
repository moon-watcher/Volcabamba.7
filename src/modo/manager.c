#include <genesis.h>
#include "modo.h"



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
        
        execPtrfn ( entity->state->exit, entity );
        execPtrfn ( entity->exit,        entity );
        execPtrfn ( entity->Delete,      entity );
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
    execPtrfn ( entity->Awake,        entity );
    execPtrfn ( entity->enter,        entity );
    execPtrfn ( entity->state->enter, entity );
}

static inline void _updateAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    execPtrfn ( entity->Update,        entity );
    execPtrfn ( entity->state->update, entity );
}

static inline void _stateAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = MODO_ENTITY_UPDATE;
    execPtrfn ( entity->enter,         entity );
    execPtrfn ( entity->state->enter,  entity );
    execPtrfn ( entity->Update,        entity );
    execPtrfn ( entity->state->update, entity );
}

static inline void _deleteAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    execPtrfn ( entity->state->exit, entity );
    execPtrfn ( entity->exit,        entity );
    execPtrfn ( entity->Delete,      entity );
    listptr_remove ( &manager->entities, node );
}