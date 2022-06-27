#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"


void system_sprite ( System ref system ) {
    void *ref array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentSprite     ref sp = array [ i++ ];
        ComponentPosition2D ref cp = array [ i++ ];
    
        SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
    }
}