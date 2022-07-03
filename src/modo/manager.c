#include <genesis.h>
#include "manager.h"



inline static void create ( );
inline static void change ( );
inline static void update ( );
inline static void delete ( );

static void ( *actions [ ] ) ( ) = { create, update, change, delete };
static int const Manager_s = sizeof ( Manager );



Manager *manager ( ) {
    Manager *manager = malloc ( Manager_s );
    
    manager->entities   = ((void*)0);
    manager->prevEntity = ((void*)0);

    return manager;
}


Entity *managerAdd ( Manager *const manager, Entity const* template ) {
    Entity *e = entity ( template );
	
    e->next = manager->entities;
    manager->entities = e;

	return e;
}


void managerUpdate ( Manager *const  manager ) {
    managerForeach ( manager, entity )
        actions [ entity->action ] ( manager, entity );
}


void managerEnd ( Manager *const manager ) {
    managerForeach ( manager, entity )
        delete ( manager, entity );

    free ( manager );
}


void managerEntityUpdate ( Manager  *const manager, Entity  *const entity ) {
    update ( manager, entity );
}


void managerEntityDelete ( Manager  *const manager, Entity  *const entity ) {
    delete ( manager, entity );
}



#define X(F,E) if(F)F(E)

inline static void create ( Manager *const manager, Entity *const entity ) {
    X ( entity->Awake,        entity );
    X ( entity->state->enter, entity );

    entity->action = ENTITY_ACTION_UPDATE;
        
    update ( manager, entity );
}

inline static void update ( Manager *const manager, Entity *const entity ) {
    X ( entity->Update,        entity );
    X ( entity->state->update, entity );

    manager->prevEntity = entity;
}

inline static void change ( Manager *const manager, Entity *const entity ) {
    X ( entity->prevState->exit, entity );
    X ( entity->state->enter,    entity );

    entity->action = ENTITY_ACTION_UPDATE;

    update ( manager, entity );
}

inline static void delete ( Manager *const manager, Entity *const entity ) {
    X ( entity->state->exit, entity );
    X ( entity->Delete,      entity );

    if ( manager->entities == entity ) {
        manager->entities = entity->next;
        manager->prevEntity = NULL; 
    }
    else {
        manager->prevEntity->next = entity->next;
        manager->prevEntity       = entity;
    }

    free ( entity->components );
    free ( entity );
}