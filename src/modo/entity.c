#include <genesis.h>
#include "entity.h"


#define X(F,E) if(F)F(E)
static int const Entity_s = sizeof ( Entity );


Entity *entity ( Entity const *template ) {
    Entity *entity;    
    int const Comps_s = template->compsSize;

    entity = malloc ( Entity_s );
    memcpy ( entity, template, Entity_s );

    entity->components = malloc ( Comps_s );
    memcpy ( entity->components, template->components, Comps_s  );

    X ( entity->Awake,        entity );
    X ( entity->state->enter, entity );

    return entity;
}


void entityState ( Entity *entity, State const *newState ) {
    X ( entity->state->exit,  entity );
    entity->state = (State*) newState;
    X ( entity->state->enter, entity );
}


void entityDelete ( Entity *entity ) {
    entity->delete = TRUE;
}