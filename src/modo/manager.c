#include <genesis.h>
#include "manager.h"




#define X(F,E) if(F)F(E)

inline static void create ( Manager * const manager, Entity *entity ) {
    X ( entity->Awake,        entity );
    X ( entity->state->enter, entity );

    entity->action = ENTITY_ACTION_UPDATE;
}

inline static void update ( Manager * const manager, Entity *entity ) {
    X ( entity->Update,        entity );
    X ( entity->state->update, entity );

    manager->prevEntity = entity;
}

inline static void change ( Manager * const manager, Entity *entity ) {
    X ( entity->prevState->exit, entity );
    X ( entity->state->enter,    entity );

    entity->action = ENTITY_ACTION_UPDATE;
}

inline static void delete ( Manager * const manager, Entity *entity ) {
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
    entity->components = NULL;

    free ( entity );
    entity = NULL;
}


static void ( *actions [ ] ) ( Manager * const, Entity* ) = { create, update, change, delete };


static int const Manager_s = sizeof ( Manager );



Manager *manager ( ) {
    Manager *manager = malloc ( Manager_s );
    
    manager->entities   = ((void*)0);
    manager->prevEntity = ((void*)0);

    return manager;
}


Entity *managerAdd ( Manager *manager, Entity const *template ) {
    Entity *e = entity ( template );
	
    e->next = manager->entities;
    manager->entities = e;

	return e;
}


void managerUpdate ( Manager *manager ) {
    managerForeach ( manager, entity )
        actions [ entity->action ] ( manager, entity );
}


void managerEnd ( Manager *manager ) {
    managerForeach ( manager, entity )
        entityDelete ( entity ); //delete ( manager, entity );

    managerUpdate ( manager );

    free ( manager );
    // manager = NULL;
}


// void managerEntityUpdate ( Manager *manager, Entity *entity ) {
//     update ( manager, entity );
// }


// void managerEntityDelete ( Manager *manager, Entity *entity ) {
//     delete ( manager, entity );
//}