#include <genesis.h>
#include "manager.h"


#define X(F,E) if(F)F(E)
inline static void _delete ( Manager*, Entity* );
inline static void _update ( Manager*, Entity* );
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
        if ( entity->delete )
            _delete ( manager, entity );
        else
            _update ( manager, entity );
}


void managerEnd ( Manager *manager ) {
    managerForeach ( manager, entity )
        _delete ( manager, entity );

    free ( manager );
    manager = NULL;
}


void managerEntityUpdate ( Manager *manager, Entity *entity ) {
    _update ( manager, entity );
}


void managerEntityDelete ( Manager *manager, Entity *entity ) {
    _delete ( manager, entity );
}



inline static void _update ( Manager *manager, Entity *entity ) {
    X ( entity->Update,        entity );
    X ( entity->state->update, entity );

    manager->prevEntity = entity;
}


inline static void _delete ( Manager *manager, Entity *entity ) {
    X ( entity->state->exit, entity );
    X ( entity->Delete,      entity );

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
