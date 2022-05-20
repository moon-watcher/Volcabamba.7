#include <genesis.h>
#include "manager.h"


Manager *modoManager ( )
{
    Manager *manager = malloc ( sizeof ( Manager ) );

    manager->entities = NULL;

    return manager;
}


void modoManagerAdd ( Manager *manager, Entity *entity )
{
    entity->next = manager->entities;
    manager->entities = entity;
}


void modoManagerUpdate ( Manager *manager )
{
    Entity *prev   = NULL;
    Entity *head   = manager->entities;
    Entity *entity = head;

    while ( entity )
    {
        Entity *next  = entity->next;
        State  *state = entity->state;

        switch ( entity->action )
        {
            case MODO_ENTITY_INIT:
                if ( entity->Awake  ) entity->Awake  ( entity );
                if ( state->enter   ) state->enter   ( entity );
                if ( entity->Update ) entity->Update ( entity );
                if ( state->update  ) state->update  ( entity );
                
                entity->action = MODO_ENTITY_UPDATE;
                prev = entity;
                
                break;

            case MODO_ENTITY_UPDATE:
                if ( state->change )
                {
                    if ( state->exit ) state->exit ( entity );
                    
                    state = state->change;
                    state->change = NULL;

                    if ( state->enter ) state->enter ( entity );
                }

                if ( entity->Update ) entity->Update ( entity );
                if ( state->update  ) state->update  ( entity );
                
                prev = entity;
                
                break;


            case MODO_ENTITY_DELETE:
                if ( state->exit    ) state->exit    ( entity );
                if ( entity->Delete ) entity->Delete ( entity );

                if ( entity == head )
                    head = next; 
                else
                    prev->next = next;

                prev = entity;
                modoEntityDelete ( entity );

                break;
        }

        entity = next;
    }
}


void modoManagerDelete ( Manager *manager )
{
    Entity *entity = manager->entities;
    
    while ( entity )
    {
        entity->action = MODO_ENTITY_DELETE;
        entity = entity->next;
    }

    modoManagerUpdate ( manager );

    free ( manager );
    manager = NULL;
}