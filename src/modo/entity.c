#include <genesis.h>
#include "entity.h"

#define exec(FUNCTION,ENTITY) ({ FUNCTION ? FUNCTION ( ENTITY ) : NULL; })
// #define exec(FUNCTION,ENTITY) ({ FUNCTION ( ENTITY ); })


static int const Entity_s = sizeof ( Entity  );


Entity *modoEntity ( Entity const *tpl )
{   
    Entity *entity;    
    int const Comps_s = tpl->compsSize;

    entity             = malloc ( Entity_s );
    entity->components = malloc ( Comps_s  );

    memcpy ( entity,             tpl,             Entity_s );
    memcpy ( entity->components, tpl->components, Comps_s  );

    entity->action = MODO_ENTITY_INIT;

    return entity;
}


void modoEntityDelete ( Entity *entity )
{
    entity->action = MODO_ENTITY_DELETE;
}


void modoEntityState ( Entity *entity, State const *state )
{
    exec ( entity->state->exit, entity );
    exec ( entity->exit,        entity );

    if ( entity->state->data )
    {
        free ( entity->state->data );
        entity->state->data = NULL;
    }

    entity->state = (State*) state;
    entity->action = MODO_ENTITY_NEWSTATE;
}

