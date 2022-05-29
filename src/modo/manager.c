#include <genesis.h>
#include "manager.h"


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
        entity->function ( manager, entity );
}


void managerEnd ( Manager *manager ) {
    managerForeach ( manager, entity )
        entityDelete ( entity );

    managerUpdate ( manager );

    free ( manager );
    manager = NULL;
}