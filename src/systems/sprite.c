#include "mymodo/mm.h" 
#include "components/Sprite.h"
#include "components/Position.h"


defineSystemFn ( system_sprite, {
    systemGetParam ( ComponentSprite,     sp );
    systemGetParam ( ComponentPosition2D, cp );

    SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
});


System const system_Sprite_tpl = { &system_sprite, 70, 2, "Sprite" };