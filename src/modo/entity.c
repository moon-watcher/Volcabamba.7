#include <genesis.h>
#include "entity.h"
#include "manager.h"


static inline void _updateEntity      ( Manager *, Entity* );
static inline void _removeFromManager ( Manager *, Entity* );

static int const Entity_s = sizeof ( Entity );
static void nullf ( ) { }


Entity *entity ( Entity const *template ) {
    Entity *entity;    
    int const Comps_s = template->compsSize;

    entity = malloc ( Entity_s );
    memcpy ( entity, template, Entity_s );

    entity->components = malloc ( Comps_s );
    memcpy ( entity->components, template->components, Comps_s  );

    if ( !entity->Awake        ) entity->Awake        = nullf;
    if ( !entity->Update       ) entity->Update       = nullf;
    if ( !entity->Delete       ) entity->Delete       = nullf;
    if ( !entity->state->enter ) entity->state->enter = nullf;

    State *state = entity->state;

    if ( !state->enter  ) state->enter  = nullf;
    if ( !state->update ) state->update = nullf;
    if ( !state->exit   ) state->exit   = nullf;

    entity->Awake ( entity );
    state->enter ( entity );
    entity->function = _updateEntity;

    entity->next = NULL;

    return entity;
}


void entityState ( Entity *entity, State const *newState ) {
    State *state = entity->state;

    state->exit ( entity );
    state = (State*) newState;

    if ( !state->enter  ) state->enter  = nullf;
    if ( !state->update ) state->update = nullf;
    if ( !state->exit   ) state->exit   = nullf;

    state->enter ( entity );
}


void entityDelete ( Entity *entity ) {
    entity->state->exit ( entity );
    entity->Delete ( entity );
    entity->function = _removeFromManager;
}


static inline void _updateEntity ( Manager *manager, Entity *entity ) {
    entity->Update ( entity );

    entity->state->update ( entity );

    manager->prevEntity = entity;    
}


static inline void _removeFromManager ( Manager *manager, Entity *entity ) {
    if ( manager->entities == entity ) {
        manager->entities = entity->next;
        manager->prevEntity = NULL; 
    }
    else {
        manager->prevEntity->next = entity->next;
        manager->prevEntity = entity;
    }

    free ( entity->components );
    entity->components = NULL;

    free ( entity );
    entity = NULL;
}