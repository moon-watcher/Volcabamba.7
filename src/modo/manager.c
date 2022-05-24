#include <genesis.h>
#include "manager.h"


static int const Entity_s  = sizeof ( Entity  );
static int const Manager_s = sizeof ( Manager );


static inline void init   ( Manager*, listptrNode*, Entity*, State* );
static inline void change ( Manager*, listptrNode*, Entity*, State* );
static inline void update ( Manager*, listptrNode*, Entity*, State* );
static inline void delete ( Manager*, listptrNode*, Entity*, State* );

static void ( *actionsArray [ ] ) ( Manager*, listptrNode*, Entity*, State* ) = { init, change, update, delete };



Manager *manager ( )
{
    Manager *manager = malloc ( Manager_s );
    listptr_init ( manager, NULL );

    return manager;
}


Entity *managerAdd ( Manager *manager, Entity const *template )
{
    Entity *e = malloc ( Entity_s );
    listptrNode *node = listptr_add ( manager, e );
    node->data = entity ( template );

	return (Entity*) node->data;
}

int y2 = 0;
void managerUpdate ( Manager *manager )
{
    y2++;
    int y = 0;
    listptr_foreach ( manager, node ) {
        Entity *entity = node->data;
        State  *state  = entity->state;

        actionsArray [ entity->action ] ( manager, node, entity, state );
        ++y;
    }
    drawInt(y, 34, y2, 3);
}



void managerEnd ( Manager *manager )
{
    listptr_foreach ( manager, node ) {
        entityDelete ( node->data );
    }

    managerUpdate ( manager );

    free ( manager );
    manager = NULL;
}




#define EXECUTE(F,E) if(F) F(E)

static inline void init ( Manager *manager, listptrNode *node, Entity *entity, State *state ) {
    EXECUTE ( entity->Awake, entity );
    EXECUTE ( state->enter, entity );

    update ( manager, node, entity, state );
}

static inline void change ( Manager *manager, listptrNode *node, Entity *entity, State *state ) {
    EXECUTE ( state->exit, entity );

    state = entity->nextState;
    entity->nextState = NULL;

    EXECUTE ( state->enter, entity );

    update ( manager, node, entity, state );
}

static inline void update ( Manager *manager, listptrNode *node, Entity *entity, State *state ) {
    EXECUTE ( entity->Update, entity );
    EXECUTE ( state->update, entity );
}

static inline void delete ( Manager *manager, listptrNode *node, Entity *entity, State *state ) {
    EXECUTE ( state->exit, entity );
    EXECUTE ( entity->Delete, entity );
    
    //entityEnd ( entity );
    listptr_remove ( manager, node );
}