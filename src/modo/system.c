#include <genesis.h>
#include "system.h"
#include "current.h"


static void init ( void *updatefn, int max, char *name )
{
    System *self = current;

    if ( self->list )
    {
        free ( self->list );
        self->list = NULL;
    }
    
    self->updatefn = updatefn;
    self->list = malloc ( sizeof(void*) * max );
    self->length = 0;
    //
    self->max = max;
    self->name = name;
}


static void update ( )
{
    System *self = current;

    if ( !self->length )
    {
        return;
    }

    if ( self->length >= self->max )
    {
        // En lugar de un mensaje de error hacer algo aquí para que se redimensione system->list.
        // Luego, por ejemplo: al finalizar una fase, sería ideal que mostrara el system->max de cada sistema

        VDP_resetScreen();
        drawText ( "LENGTH:", 0, 2 ); drawInt  ( self->length, 8, 2, 3 );
        drawText ( "SYSTEM:", 0, 0 ); drawText ( self->name,   8, 0 );
        drawText ( "MAX:",    0, 1 ); drawInt  ( self->max,    8, 1, 3 );
        waitMs(10000);
        
        return;
    }

    self->updatefn ( self->list, self->length );
    self->length = 0;
}


static void delete ( )
{
    System *self = current;

    free ( self->list );
    self->list = NULL;
    
    free ( self );
    self = NULL;
}


inline static void add ( void *data )
{
    System *self = current;

    self->list [ self->length++ ] = data;
}



static void constructor ( System *self )
{
    self->init   = init;
    self->delete = delete;
    self->update = update;
    self->add    = add;
}

static void destructor ( System *self )
{
    //
}

#include "BaseClass.h"

const BaseClass SystemClass = { constructor, destructor };