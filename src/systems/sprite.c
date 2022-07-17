#include "modo/system.h"
#include "components/Sprite.h"
#include "components/Position.h"


systemFnDefine ( system_sprite, {
    systemFnGet ( ComponentSprite,     sp );
    systemFnGet ( ComponentPosition2D, cp );

    SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
});