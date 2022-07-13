#include "modo/system.h"
#include "components/Sprite.h"
#include "components/Position.h"


// systemFnDefine ( system_sprite, {
//     systemFnGet ( ComponentSprite,     sp );
//     systemFnGet ( ComponentPosition2D, cp );

//     SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
// });


void system_sprite ( System *const s ){
    for ( SystemNode *n = s->head; n;  ){
        ComponentSprite     *const sp = n->data; n = n->next;
        ComponentPosition2D *const cp = n->data; n = n->next;

        SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
    }
}