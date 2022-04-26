#include <genesis.h>
#include "manager.h"

#define exec(FUNCTION,ENTITY)  FUNCTION ? FUNCTION ( ENTITY ) : NULL


static inline void _enter  ( Manager*, struct ManagerNode*, Entity* );
static inline void _update ( Manager*, struct ManagerNode*, Entity* );
static inline void _state  ( Manager*, struct ManagerNode*, Entity* );
static inline void _delete ( Manager*, struct ManagerNode*, Entity* );

static void ( *actionsArray [ ] ) ( Manager*, struct ManagerNode*, Entity* ) = { _enter, _update, _state, _delete };


Manager *modoManager ( )
{
    Manager *manager = malloc ( sizeof ( Manager ) );

    manager->length   = 0;
    manager->entities = ((void*)0);

    return manager;
}


void modoManagerUpdate ( Manager *manager )
{
    struct ManagerNode *node = manager->entities;

    while ( node )
    {
        Entity *entity = node->data;

        actionsArray [ entity->action ] ( manager, node, entity );

        node = node->next;
    }
}


void modoManagerDelete ( Manager *manager )
{
	while ( manager->entities )
	{
		struct ManagerNode *node = manager->entities;
        Entity *entity = node->data;

		manager->entities = node->next;
        
        _delete ( manager, node, entity );
	}

    free ( manager );
    manager = NULL;
}


void modoManagerAdd ( Manager *manager, Entity *entity )
{
	struct ManagerNode *node = malloc ( sizeof ( struct ManagerNode ) );

	node->data = entity;
	node->prev = ((void*)0);
	node->next = manager->entities;

	manager->entities       = node;
	manager->entities->prev = node;

	++manager->length;

	return node;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static inline void _enter ( Manager *manager, struct ManagerNode *node, Entity *entity )
{
    entity->action = MODO_ENTITY_UPDATE;
    exec ( entity->Awake,        entity );
    exec ( entity->enter,        entity );
    exec ( entity->state->enter, entity );
}

static inline void _update ( Manager *manager, struct ManagerNode *node, Entity *entity )
{
    exec ( entity->Update,        entity );
    exec ( entity->state->update, entity );
}

static inline void _state ( Manager *manager, struct ManagerNode *node, Entity *entity )
{
    entity->action = MODO_ENTITY_UPDATE;
    exec ( entity->enter,         entity );
    exec ( entity->state->enter,  entity );
    exec ( entity->Update,        entity );
    exec ( entity->state->update, entity );
}

static inline void _delete ( Manager *manager, struct ManagerNode *node, Entity *entity )
{
    exec ( entity->state->exit, entity );
    exec ( entity->exit,        entity );
    exec ( entity->Delete,      entity );

    if ( !manager->length )
    {
        return;
    }

    if ( node->prev )
    {
        node->prev->next = node->next;
    }
    else
    {
        manager->entities = node->next;
    }

    if ( node->next )
    {
        node->next->prev = node->prev;
    }

    --manager->length;
    free ( node );
}