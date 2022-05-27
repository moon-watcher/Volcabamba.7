#include <genesis.h>
#include "entity.h"

// #define exec(FUNCTION,ENTITY) ({ FUNCTION ? FUNCTION ( ENTITY ) : NULL; })
// // #define exec(FUNCTION,ENTITY) ({ FUNCTION ( ENTITY ); })


static int const Entity_s = sizeof ( Entity );


Entity *entity ( Entity const *template )
{   
    Entity *entity;    
    int const Comps_s = template->compsSize;

    entity = malloc ( Entity_s );
    memcpy ( entity, template, Entity_s );

    entity->components = malloc ( Comps_s );
    memcpy ( entity->components, template->components, Comps_s  );

    entity->action = ENTITY_ACTION_INIT;
    entity->next   = NULL;

    return entity;
}


void entityDelete ( Entity *entity )
{
    entity->action = ENTITY_ACTION_DELETE;
}


void entityState ( Entity *entity, State const *nextState )
{
    entity->action = ENTITY_ACTION_CHANGE;
    entity->state->next = (State*) nextState;
}


void entityEnd ( Entity *entity )
{
    free(entity->components);
    entity->components = NULL;

    free(entity);
    entity = NULL;
}