#include <genesis.h>
#include "ECS.h"


static int const Entity_s  = sizeof ( Entity  );
static int const System_s  = sizeof ( System  );


void ecsManagerUpdate ( Manager *manager )
{
    listptr_foreach ( manager, node )
    {
        Entity *entity = node->data;

        if ( entity->delete )
	    {
            ecsExecPtrfn ( entity->Delete, entity );
            listptr_remove ( manager, node );
	    }
	    else
        {
            ecsExecPtrfn ( entity->Update,        entity );
            ecsExecPtrfn ( entity->state->update, entity );
        }
    }
}


void ecsManagerDelete ( Manager *manager )
{
    listptr_foreach ( manager, node )
    {
        Entity *entity = node->data;
        
        ecsExecPtrfn ( entity->state->exit, entity );
        ecsExecPtrfn ( entity->Delete, entity );
    }

    listptr_destroy ( manager );
    
    free ( manager );
    manager = NULL;
}



Entity *ecsEntity ( Manager *manager, Entity const *tpl )
{   
    Entity *entity;    
    int const Comps_s = tpl->compsSize;

    entity             = malloc ( Entity_s );
    entity->components = malloc ( Comps_s  );

    memcpy ( entity,             tpl,             Entity_s );
    memcpy ( entity->components, tpl->components, Comps_s  );

    listptr_add ( manager, entity );

    ecsExecPtrfn ( entity->Awake,        entity );
    ecsExecPtrfn ( entity->state->enter, entity );

    return entity;
}


void ecsEntityState ( Entity *entity, State const *state )
{
    State *s = entity->state;

    ecsExecPtrfn ( s->exit, entity );
    s = (State*) state;
    ecsExecPtrfn ( s->enter, entity );
}



System *ecsSystem ( System const *tpl )
{
    System *system = malloc ( System_s );

    memcpy ( system, tpl, System_s );

    system->list   = malloc ( sizeof(void*) * tpl->max );
    system->length = 0;

    return system;
}


void ecsSystemUpdate ( System *system )
{
    if ( system->length >= system->max )
    {
        // En lugar de un mensaje de error
        // hacer algo aquí para que se 
        // redimensione system->list.
        // Luego, por ejemplo: al finalizar
        // una fase, sería ideal que mostrara
        // el system->max de cada sistema

        VDP_resetScreen();
        drawText ( "SYSTEM:",      0, 0 );
        drawText ( system->name,   8, 0 );
        drawText ( "MAX:",         0, 1 );
        drawText ( system->max,    8, 1 );
        drawText ( "LENGTH:",      0, 2 );
        drawText ( system->length, 8, 2 );
        waitMs(10000);
        
        return;
    }

    system->updateFn ( system->list, system->length );
    system->length = 0;
}


void ecsSystemDelete ( System *system )
{
    free ( system->list );
    system->list = NULL;
 
    free ( system );
    system = NULL;
}