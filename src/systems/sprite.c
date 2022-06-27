#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"


void system_sprite ( System * const system ) {
    void ** const array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentSprite     * const sp = array [ i++ ];
        ComponentPosition2D * const cp = array [ i++ ];
    
        SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
    }
}