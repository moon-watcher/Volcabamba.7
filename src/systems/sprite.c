#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"


void system_sprite ( System reff system ) {
    void *reff array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentSprite     reff sp = array [ i++ ];
        ComponentPosition2D reff cp = array [ i++ ];
    
        SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
    }
}