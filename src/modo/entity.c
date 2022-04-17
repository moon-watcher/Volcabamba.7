#include <genesis.h>
#include "entity.h"


void modoEntityInit ( Entity *self, Entity const *tpl )
{   
    unsigned const size = tpl->compsSize;

    self->components = malloc ( size );

    memcpy ( self, tpl, sizeof ( Entity ) );
    memcpy ( self->components, tpl->components, size );

    self->action = MODO_ENTITY_INIT;
}


void modoEntityDelete ( Entity *self )
{
    self->action = MODO_ENTITY_DELETE;
}


void modoEntityState ( Entity *self, State const *state )
{
    if ( self->state->exit ) self->state->exit ( self );
    if ( self->exit        ) self->exit        ( self );

    if ( self->state->data )
    {
        free ( self->state->data );
        self->state->data = NULL;
    }

    self->state  = (State*) state;
    self->action = MODO_ENTITY_NEWSTATE;
}