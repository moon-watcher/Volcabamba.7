#include "modo/system.h"
#include "components/Sprite.h"
#include "components/Position.h"


systemFnDefine ( system_sprite, {
    ComponentSprite     *const sp = systemFnGet;
    ComponentPosition2D *const cp = systemFnGet;

    SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
});