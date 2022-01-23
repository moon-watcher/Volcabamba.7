#include <genesis.h>
#include "ECS.h"


static int const Manager_s = sizeof ( Manager );
static int const Entity_s  = sizeof ( Entity  );
static int const System_s  = sizeof ( System  );


Manager* ecsManager ( )
{
    return malloc ( Manager_s );
}


void ecsManagerUpdate ( Manager *manager )
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


void ecsManagerDelete ( Manager *manager )
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



Entity *ecsEntity ( Manager *manager, Entity const *tpl )
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


void ecsEntityState ( Entity *entity, State *state )
{
    if ( state->enter )
    {
        state->enter ( entity );
    }

    entity->state = state;
}



System *ecsSystem ( System const *tpl )
{
    System *system = malloc ( System_s );

    memcpy ( system, tpl, System_s );

    return system;
}


void ecsSystemInit ( System *system )
{
    system->length = 0;
}


void ecsSystemUpdate ( System *system )
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


void ecsSystemDelete ( System *system )
{
    free ( system );
    system = NULL;
}