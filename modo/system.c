#include <genesis.h>
#include "system.h"


static int const System_s  = sizeof ( System );
static int const voidptr_s = sizeof ( void* );


System *system ( void (*update) (), int max, int params ) {
    System *s = malloc ( System_s );

    s->update = update;
    s->max = max * params;
    s->list = malloc ( voidptr_s * s->max );
    s->length = 0;
    s->params = params;

    return s;
}


void systemUpdate ( System *const s ) {
    if ( !s->length || !s->update || !s )
        return;

    s->update ( s );
    s->length = 0;
}


void systemEnd ( System *const s ) {
    free ( s->list );
    free ( s );
}


void systemInfo ( System *const s ) {
    VDP_resetScreen();

    drawText ( "=SYSTEM=", 0, 0 );
    drawText ( "MAX:",     0, 1 ); drawUInt ( s->max,    10, 1, 9 );
    drawText ( "LENGTH:",  0, 2 ); drawUInt ( s->length, 10, 2, 9 );
    
    waitMs(20000);
}