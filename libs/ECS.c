#include <genesis.h>
#include "ECS.h"


static int const Manager_s = sizeof ( Manager );
static int const Entity_s  = sizeof ( Entity  );
static int const System_s  = sizeof ( System  );


static Manager* manager_new ( )
{
    return malloc ( Manager_s );
}


static void manager_update ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;

        if ( entity->delete )
	    {
            entity->Delete ( entity );
            listptr_remove ( list, node );
	    }
	    else
        {
            entity->Update ( entity );
        }
    }
}


static void manager_delete ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;
        
        entity->Delete ( entity );
    }

    listptr_destroy ( list );
    
    free ( manager );
    manager = NULL;
}



static Entity *entity_new ( Manager *manager, Entity const *tpl )
{
    Entity *entity;
    
    int const compsSize = tpl->compsSize;

    entity             = malloc ( Entity_s  );
    entity->components = malloc ( compsSize );

    memcpy ( entity,             tpl,             Entity_s  );
    memcpy ( entity->components, tpl->components, compsSize );

    listptr_add ( &manager->entities, entity );

    entity->Awake ( entity );

    return entity;
}



//static System *system_new ( void (*updateFn), void *list, int max )

static System *system_new ( System const *tpl )
{
    System *system = malloc ( System_s );

    memcpy ( system, tpl, System_s );

    return system;
}


static void system_init ( System *system )
{
    system->length = 0;
}


static void system_update ( System *system )
{
    if ( !system )
    {
        return;
    }

    if ( system->length > system->max )
    {
        drawText ( "FALLO:",     1, 0 );
        drawText ( system->name, 8, 0 );
        waitMs(10000);
        
        return;
    }

    system->updateFn ( system->list, system->length );
}


static void system_delete ( System *system )
{
    free ( system );
    system = NULL;
}


ECS ecs =
{
    { manager_new, manager_update, manager_delete, },
    { entity_new, },
    { system_new, system_init, system_update, system_delete },
};