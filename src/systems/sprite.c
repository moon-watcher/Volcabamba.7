#include "modo.h"
#include "components/Sprite.h"
#include "components/Position.h"


systemDefineFn ( system_sprite, {
    systemGetParam ( ComponentSprite,     sp );
    systemGetParam ( ComponentPosition2D, cp );

    SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
});