#include <genesis.h>
#include "manager.h"



#define X(F,E) if(F) F(E)

static inline void update ( Manager *manager, Entity *entity, State *state ) {
    X ( entity->Update, entity );
    X ( state->update, entity );

    manager->prevEntity = entity;
}

static inline void init ( Manager *manager, Entity *entity, State *state ) {
    X ( entity->Awake, entity );
    X ( state->enter, entity );

    update ( manager, entity, state );
}

static inline void change ( Manager *manager, Entity *entity, State *state ) {
    X ( state->exit, entity );

    state = entity->nextState;
    entity->nextState = NULL;

    X ( state->enter, entity );

    update ( manager, entity, state );
}

static inline void delete ( Manager *manager, Entity *entity, State *state ) {
    X ( state->exit, entity );
    X ( entity->Delete, entity );
    
    if ( manager->entities == entity ) {
        manager->entities = entity->next;
        manager->prevEntity = NULL; 
    }
    else
    {
        manager->prevEntity->next = entity->next;
        manager->prevEntity = entity;
    }

    entityEnd ( entity );
}


static void ( *actionsArray [ ] ) ( Manager*, Entity*, State* ) = { init, change, update, delete };
static int const Manager_s = sizeof ( Manager );



Manager *manager ( )
{
    Manager *manager = malloc ( Manager_s );
    
    manager->entities   = ((void*)0);
    manager->prevEntity = ((void*)0);

    return manager;
}


Entity *managerAdd ( Manager *manager, Entity const *template )
{
    Entity *e = entity ( template );
	
    e->next = manager->entities;
    manager->entities = e;

	return e;
}


void managerUpdate ( Manager *manager )
{
    managerForeach ( manager, entity ) {
        State *state = entity->state;

        actionsArray [ entity->action ] ( manager, entity, state );
    }
}


void managerEnd ( Manager *manager )
{
    managerForeach ( manager, entity )
        entityDelete ( entity );

    managerUpdate ( manager );

    free ( manager );
    manager = NULL;
}