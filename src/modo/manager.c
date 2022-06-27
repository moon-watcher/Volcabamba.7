#include <genesis.h>
#include "manager.h"



inline static void create ( Manager reff, Entity reff );
inline static void change ( Manager reff, Entity reff );
inline static void update ( Manager reff, Entity reff );
inline static void delete ( Manager reff, Entity reff );

static void ( *actions [ ] ) ( Manager reff, Entity reff ) = { create, update, change, delete };
static int const Manager_s = sizeof ( Manager );



Manager *manager ( ) {
    Manager *manager = malloc ( Manager_s );
    
    manager->entities   = ((void*)0);
    manager->prevEntity = ((void*)0);

    return manager;
}


Entity *managerAdd ( Manager reff manager, Entity const *template ) {
    Entity *e = entity ( template );
	
    e->next = manager->entities;
    manager->entities = e;

	return e;
}


void managerUpdate ( Manager reff  manager ) {
    managerForeach ( manager, entity )
        actions [ entity->action ] ( manager, entity );
}


void managerEnd ( Manager reff manager ) {
    managerForeach ( manager, entity )
        delete ( manager, entity );

    free ( manager );
}


// void managerEntityUpdate ( Manager  reff manager, Entity  reff entity ) {
//     update ( manager, entity );
// }


// void managerEntityDelete ( Manager  reff manager, Entity  reff entity ) {
//     delete ( manager, entity );
//}



#define X(F,E) if(F)F(E)

inline static void create ( Manager reff manager, Entity reff entity ) {
    X ( entity->Awake,        entity );
    X ( entity->state->enter, entity );

    entity->action = ENTITY_ACTION_UPDATE;
        
    update ( manager, entity );
}

inline static void update ( Manager reff manager, Entity reff entity ) {
    X ( entity->Update,        entity );
    X ( entity->state->update, entity );

    manager->prevEntity = entity;
}

inline static void change ( Manager reff manager, Entity reff entity ) {
    X ( entity->prevState->exit, entity );
    X ( entity->state->enter,    entity );

    entity->action = ENTITY_ACTION_UPDATE;

    update ( manager, entity );
}

inline static void delete ( Manager reff manager, Entity reff entity ) {
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