#include <genesis.h>
#include "system.h"


System *system ( void (*update) (), int max, int params, char* name ) {
    System *s = malloc ( sizeof ( System ) );

    s->update = update;
    s->max = max * params;
    s->list = malloc ( sizeof ( void* ) * s->max );
    s->length = 0;
    s->name = name;
    s->params = params;

    return s;
}


void systemUpdate ( System *const s ) {
    if ( !s->length /* || !s->update || !s */ )
        return;

    if ( s->length > s->max )
        systemInfo ( s );

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
    drawText ( "NAME:   ", 0, 1 ); drawText ( s->name,   9, 1 );
    drawText ( "MAX:    ", 0, 2 ); drawUInt ( s->max,    9, 2, 4 );
    drawText ( "LENGTH: ", 0, 3 ); drawUInt ( s->length, 9, 3, 4 );
    
    waitMs(20000);
}