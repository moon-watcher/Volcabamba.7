#include <genesis.h>
#include "system.h"


System *system ( systemFn update, unsigned max, char *name )
{
    System *system = malloc ( sizeof ( System  ) );

    system->update = update;
    system->list = malloc ( sizeof(void*) * max );
    system->max = max;
    system->name = name;
    system->length = 0;

    return system;
}


void systemUpdate ( System *system )
{
    if ( !system->length  ||  !system->update )
    {
        return;
    }

    if ( system->length >= system->max )
    {
        // En lugar de un mensaje de error hacer algo aquí para que se redimensione system->list.
        // Luego, por ejemplo: al finalizar una fase, sería ideal que mostrara el system->max de cada sistema

        VDP_resetScreen();
        drawText ( "SYSTEM:", 0, 0 ); drawText ( system->name,   8, 0 );
        drawText ( "MAX:",    0, 1 ); drawUInt ( system->max,    8, 1, 5 );
        drawText ( "LENGTH:", 0, 2 ); drawUInt ( system->length, 8, 2, 5 );
        waitMs(10000);
        
        return;
    }

    system->update ( system->list, system->length );
    system->length = 0;
}


void systemEnd ( System *system )
{
    free ( system->list );
    system->list = NULL;

    free ( system );
    system = NULL;
}
