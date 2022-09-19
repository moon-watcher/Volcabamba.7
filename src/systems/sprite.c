#include "mymodo.h" 
#include "components/Sprite.h"
#include "components/Position.h"


mm_systemDefineFn ( system_sprite, {
    mm_systemGetParam ( ComponentSprite,     sp );
    mm_systemGetParam ( ComponentPosition2D, cp );

    SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
});


System const system_Sprite_tpl = { &system_sprite, 70, 2, "Sprite" };