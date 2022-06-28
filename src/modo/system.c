#include <genesis.h>
#include "system.h"
#include "config/ref.inc"


static int const System_s  = sizeof ( System );
static int const voidptr_s = sizeof ( void* );


System *system ( systemFn update, unsigned max, char *name ) {
    System *system = malloc ( System_s );

    system->update = update;
    system->list = malloc ( voidptr_s * max );
    system->max = max;
    system->name = name;
    system->length = 0;
    system->max_length = 0;

    return system;
}


void systemUpdate ( System ref system ) {
    if ( !system->length  ||  !system->update )
        return;

    if ( system->length > system->max_length )
        system->max_length = system->length;

    // En lugar de un mensaje de error hacer algo aquí para que se redimensione system->list.
    // Luego, por ejemplo: al finalizar una fase, sería ideal que mostrara el system->max de cada sistema
    if ( system->length >= system->max ) {
        VDP_resetScreen();
        drawText ( "SYSTEM:",   0, 0 ); drawText ( system->name,       10, 0 );
        drawText ( "MAX:",      0, 1 ); drawUInt ( system->max,        10, 1, 9 );
        drawText ( "LENGTH:",   0, 2 ); drawUInt ( system->length,     10, 2, 9 );
        drawText ( "M-LENGTH:", 0, 3 ); drawUInt ( system->max_length, 10, 3, 9 );
        
        while(1);
    }

    system->update ( system );
    system->length = 0;
}


void systemEnd ( System ref system ) {
    free ( system->list );
    free ( system );
}
