#include <genesis.h>

#include "manager.h"
#include "entity.h"

int j= 10;

#define execute(F,V)  if(F) F(V)

static inline void _enter ( Entity *entity, Manager *manager, listptrNode *node )
{
    drawText( "enter",9,j++,3);

    entity->action = MODO_ENTITY_UPDATE;
    
    execute ( entity->Awake,         entity );
    execute ( entity->enter,         entity );
    execute ( entity->state->enter,  entity );
}

static inline void _update ( Entity *entity, Manager *manager, listptrNode *node )
{
    drawText( "update", 9, j++ );

    execute ( entity->Update,        entity );
    execute ( entity->state->update, entity );
}

static inline void _state ( Entity *entity, Manager *manager, listptrNode *node )
{
    drawText( "state", 9, j++ );

    entity->action = MODO_ENTITY_UPDATE;

    execute ( entity->enter,         entity );
    execute ( entity->state->enter,  entity );
    execute ( entity->Update,        entity );
    execute ( entity->state->update, entity );
}

static inline void _delete ( Entity *entity, Manager *manager, listptrNode *node )
{
    drawText( "delete", 9, j++ );

    execute ( entity->state->exit,   entity );
    execute ( entity->exit,          entity );
    execute ( entity->Delete,        entity );
    
    listptr_remove ( &manager->entities, node );
}

static void ( *array [ ] ) ( Entity*, Manager*, listptrNode* ) = { _enter, _update, _state, _delete };


///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void modoManagerInit ( Manager *self )
{
    // listptr *list = &self->entities;

    // if ( list )
    // {
    //     listptr_destroy ( list );
    // }

    // listptr_init ( list, NULL );
    listptr_init ( &self->entities, NULL );
}


void modoManagerUpdate ( Manager *self )
{
    listptr *list = &self->entities;
j = 0;
    drawUInt ( list->length, 0, 1, 4 );
    waitMs ( 1000 );

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;

        drawText("ACTION",9,j++);
        drawUInt( entity->action,9,j++,3);
        
        array [ entity->action ] ( entity, self, node );

        // drawText ( "exec!", 9, j++ );
        // waitMs(1100);
    }
    
    drawText("sale",1,j++); waitMs(1100);
}


void modoManagerDelete ( Manager *self )
{
    listptr *list = &self->entities;

    listptr_foreach ( list, node )
    {
        Entity *e = node->data;
        
        execute ( e->state->exit, e );
        execute ( e->exit,        e );
        execute ( e->Delete,      e );
    }

    listptr_destroy ( list );
    
    free ( list );
    list = NULL;

    free ( self );
    self = NULL;
}


void modoManagerAdd ( Manager *self, Entity *entity )
{
    listptr_add ( &self->entities, entity );

    drawUInt ( self->entities.length, 10, 21, 4 );
    waitMs ( 1000 );
}