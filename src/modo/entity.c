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


void modoEntitySetDelete ( Entity *entity )
{
    entity->action = MODO_ENTITY_DELETE;
}


void modoEntitySetState ( Entity *entity, State const *state )
{
    entity->state->change = (State*) state;
}


void modoEntityDelete ( Entity *entity )
{
    entity->prev->next = entity->next;
    free ( entity->whatever );
    free ( entity->components );
    free ( entity );

    entity->components = NULL;
    entity = NULL;
}
