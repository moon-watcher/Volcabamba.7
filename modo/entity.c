#include <genesis.h>
#include "entity.h"


static int const Entity_s = sizeof ( Entity );

static void nullf ( Entity *e ) { }


Entity *entity ( Entity const* template ) {
    Entity *entity;    
    int const Comps_s = template->compsSize;

    entity = malloc ( Entity_s );
    memcpy ( entity, template, Entity_s );

    entity->components = malloc ( Comps_s );
    memcpy ( entity->components, template->components, Comps_s  );

    entity->action = ENTITY_ACTION_CREATE;

    if ( !entity->Awake  ) entity->Awake  = nullf;
    if ( !entity->Update ) entity->Update = nullf;
    if ( !entity->Delete ) entity->Delete = nullf;

    return entity;
}


void entityState ( Entity *const entity, State const* newState ) {
    if ( newState == entity->state )
        return;

    entity->prevState = entity->state;
    entity->state     = (State*) newState;
    entity->action    = ENTITY_ACTION_CHANGE;

    // use when copy state just like the entity
    // if ( !entity->state->enter  ) entity->state->enter  = nullf;
    // if ( !entity->state->update ) entity->state->update = nullf;
    // if ( !entity->state->exit   ) entity->state->exit   = nullf;
}


void entityDelete ( Entity *const entity ) {
    entity->action = ENTITY_ACTION_DELETE;
}