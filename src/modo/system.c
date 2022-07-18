#include <genesis.h>
#include "system.h"


static int const System_s  = sizeof ( System );
static int const voidptr_s = sizeof ( void* );


System *system ( systemFn update ) {
    System *s = malloc ( System_s );

    s->update = update;
    s->max = 15;
    s->list = malloc ( voidptr_s * s->max );
    s->length = 0;

    return s;
}


void systemUpdate ( System *const s ) {
    if ( !s->length || !s->update || !s )
        return;

    s->update ( s );
    s->length = 0;
}


void systemResize ( System *const s ) {
    int old = s->max;    
    s->max += 15;
    
    void *list = malloc ( voidptr_s * s->max );
    memcpy ( list, s->list, voidptr_s * old );
    
    free ( s->list );

    s->list = list;
}


void systemEnd ( System *const s ) {
    free ( s->list );
    free ( s );
}


void systemInfo ( System *const s ) {
    VDP_resetScreen();
    drawText ( "MAX:",    0, 1 ); drawUInt ( s->max,    10, 1, 9 );
    drawText ( "LENGTH:", 0, 2 ); drawUInt ( s->length, 10, 2, 9 );
    
    waitMs(2000);
}