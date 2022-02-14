#include <genesis.h>

#include "data/components.h"


void system_sprite ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentSprite   *sp = array[i++];
        ComponentPosition *cp = array[i++];

        SPR_setPosition ( sp->sprite, fix32ToRoundedInt(cp->x), fix32ToRoundedInt(cp->y) );

    }
}


void system_sprite_init ( ComponentSprite *sp, ComponentPosition *cp )
{
    sp->sprite = SPR_addSprite ( sp->sd, fix32ToRoundedInt(cp->x), fix32ToRoundedInt(cp->y), sp->attr );
}
    