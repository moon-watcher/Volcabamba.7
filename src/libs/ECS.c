#include <genesis.h>
#include "ECS.h"


enum
{
    ECS_ENTITY_INIT, 
    ECS_ENTITY_UPDATE,
    ECS_ENTITY_NEWSTATE,
    ECS_ENTITY_DELETE
};


static int const Entity_s = sizeof ( Entity  );
static int const System_s = sizeof ( System  );

#define execPtrfn(FUNCTION,ENTITY) ({ FUNCTION ? FUNCTION ( ENTITY ) : NULL; })
// #define execPtrfn(FUNCTION,ENTITY) ({ FUNCTION ( ENTITY ); })



static inline void _enterAction  ( Entity*, Manager*, listptrNode* );
static inline void _updateAction ( Entity*, Manager*, listptrNode* );
static inline void _stateAction  ( Entity*, Manager*, listptrNode* );
static inline void _deleteAction ( Entity*, Manager*, listptrNode* );

static void ( *actionsArray [ ] ) ( Entity*, Manager*, listptrNode* ) = { _enterAction, _updateAction, _stateAction, _deleteAction };



void ecsManagerUpdate ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;

        actionsArray [ entity->action ] ( entity, manager, node );
    }
}


void ecsManagerDelete ( Manager *manager )
{
    listptr *list = &manager->entities;

    listptr_foreach ( list, node )
    {
        Entity *entity = node->data;
        
        execPtrfn ( entity->state->exit, entity );
        execPtrfn ( entity->exit,        entity );
        execPtrfn ( entity->Delete,      entity );
    }

    listptr_destroy ( list );
    
    free ( list );
    list = NULL;

    free ( manager );
    manager = NULL;
}


void ecsManagerAdd ( Manager *manager, Entity *entity )
{
    listptr_add ( &manager->entities, entity );
}


Entity *ecsManagerNewEntity ( Manager *manager, Entity const *tpl )
{
    Entity *entity = ecsEntity ( tpl );

    ecsManagerAdd ( manager, entity );

    return entity;
}


Entity *ecsEntity ( Entity const *tpl )
{   
    Entity *entity;    
    int const Comps_s = tpl->compsSize;

    entity             = malloc ( Entity_s );
    entity->components = malloc ( Comps_s  );

    memcpy ( entity,             tpl,             Entity_s );
    memcpy ( entity->components, tpl->components, Comps_s  );

    entity->action = ECS_ENTITY_INIT;

    return entity;
}


void ecsEntityDelete ( Entity *entity )
{
    entity->action = ECS_ENTITY_DELETE;
}


void ecsEntityState ( Entity *entity, State const *state )
{
    execPtrfn ( entity->state->exit, entity );
    execPtrfn ( entity->exit,        entity );

    if ( entity->state->data )
    {
        free ( entity->state->data );
        entity->state->data = NULL;
    }

    entity->state = (State*) state;
    entity->action = ECS_ENTITY_NEWSTATE;
}



//System *ecsSystem ( System const *tpl )
System *ecsSystem ( ecsSystemUpdateFn update, int max, char *name )
{
    System *system;

    system = malloc ( System_s );
    system->update = update;
    system->list = malloc ( sizeof(void*) * max );
    system->max = max;
    system->name = name;
    system->length = 0;

    return syste;
}


void ecsSystemUpdate ( System *system )
{
    if ( system->length >= system->max )
    {
        // En lugar de un mensaje de error hacer algo aquí para que se redimensione system->list.
        // Luego, por ejemplo: al finalizar una fase, sería ideal que mostrara el system->max de cada sistema

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

    system->update ( system->list, system->length );
    system->length = 0;
}


void ecsSystemDelete ( System *system )
{
    free ( system->list );
    system->list = NULL;
    free ( system );
    system = NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static inline void _enterAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = ECS_ENTITY_UPDATE;
    execPtrfn ( entity->Awake,        entity );
    execPtrfn ( entity->enter,        entity );
    execPtrfn ( entity->state->enter, entity );
}

static inline void _updateAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    execPtrfn ( entity->Update,        entity );
    execPtrfn ( entity->state->update, entity );
}

static inline void _stateAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    entity->action = ECS_ENTITY_UPDATE;
    execPtrfn ( entity->enter,         entity );
    execPtrfn ( entity->state->enter,  entity );
    execPtrfn ( entity->Update,        entity );
    execPtrfn ( entity->state->update, entity );
}

static inline void _deleteAction ( Entity *entity, Manager *manager, listptrNode *node )
{
    execPtrfn ( entity->state->exit, entity );
    execPtrfn ( entity->exit,        entity );
    execPtrfn ( entity->Delete,      entity );
    listptr_remove ( &manager->entities, node );
}