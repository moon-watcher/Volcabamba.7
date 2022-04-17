#include "genesis.h"
#include "system.h"


void modoSystemInit ( System *self, void *update, unsigned max, char *name )
{
    if ( self->list )
    {
        free ( self->list );
        self->list = NULL;
    }
    
    self->update = update;
    self->list = malloc ( sizeof(void*) * max );
    self->length = 0;
    self->max = max;
    self->name = name;
}


void modoSystemUpdate ( System *self )
{
    if ( !self->length )
    {
        return;
    }

    if ( self->length >= self->max )
    {
        // En lugar de un mensaje de error hacer algo aquí para que se redimensione system->list.
        // Luego, por ejemplo: al finalizar una fase, sería ideal que mostrara el system->max de cada sistema

        VDP_resetScreen();
        drawText ( "SYSTEM:", 0, 0 ); drawText ( self->name,   8, 0 );
        drawText ( "MAX:",    0, 1 ); drawUInt ( self->max,    8, 1, 3 );
        drawText ( "LENGTH:", 0, 2 ); drawUInt ( self->length, 8, 2, 3 );
        waitMs(10000);
        
        return;
    }

    self->update ( self->list, self->length );
    self->length = 0;
}


void modoSystemDelete ( System *self )
{
    free ( self->list );
    self->list = NULL;
    
    free ( self );
    self = NULL;
}