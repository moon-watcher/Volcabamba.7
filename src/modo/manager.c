#include <genesis.h>
#include "manager.h"


static int const Manager_s     = sizeof ( Manager     );
static int const ManagerNode_s = sizeof ( ManagerNode );

static inline void init   ( Manager*, ManagerNode*, Entity*, State* );
static inline void change ( Manager*, ManagerNode*, Entity*, State* );
static inline void update ( Manager*, ManagerNode*, Entity*, State* );
static inline void delete ( Manager*, ManagerNode*, Entity*, State* );

static void ( *actionsArray [ ] ) ( Manager*, ManagerNode*, Entity*, State* ) = { init, change, update, delete };



Manager *manager ( )
{
    Manager *manager = malloc ( Manager_s );
    manager->entities = ((void*)0);
    manager->prevNode = ((void*)0);

    return manager;
}


Entity *managerAdd ( Manager *manager, Entity const *template )
{
    ManagerNode *node = malloc ( ManagerNode_s );

	node->entity = entity ( template );
	node->next   = manager->entities;
         
    manager->entities = node;

	return node->entity;
}


void managerUpdate ( Manager *manager )
{
    managerForeach ( manager, node ) {
        Entity *entity = node->entity;
        State  *state  = entity->state;

        actionsArray [ entity->action ] ( manager, node, entity, state );
    }
}


void managerEnd ( Manager *manager )
{
    managerForeach ( manager, node )
        entityDelete ( node->entity );

    managerUpdate ( manager );

    free ( manager );
    manager = NULL;
}


#define X(F,E) if(F) F(E)

static inline void init ( Manager *manager, ManagerNode *node, Entity *entity, State *state ) {
    X ( entity->Awake, entity );
    X ( state->enter, entity );

    update ( manager, node, entity, state );
}

static inline void change ( Manager *manager, ManagerNode *node, Entity *entity, State *state ) {
    X ( state->exit, entity );

    state = entity->nextState;
    entity->nextState = NULL;

    X ( state->enter, entity );

    update ( manager, node, entity, state );
}

static inline void update ( Manager *manager, ManagerNode *node, Entity *entity, State *state ) {
    X ( entity->Update, entity );
    X ( state->update, entity );

    manager->prevNode = node;
}

static inline void delete ( Manager *manager, ManagerNode *node, Entity *entity, State *state ) {
    X ( state->exit, entity );
    X ( entity->Delete, entity );
    
    entityEnd ( entity );
    
    if ( manager->entities == node ) {
        manager->entities = node->next;
        manager->prevNode = NULL; 
    }
    else
    {
        manager->prevNode->next = node->next;
        manager->prevNode = node;
    }

    free ( node );
}