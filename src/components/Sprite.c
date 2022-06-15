#include "Sprite.h"


inline void ComponentSprite_Init ( ComponentSprite *this, int x, int y ) {
    this->sprite = SPR_addSprite ( this->sd, x, y, this->attr );
    VDP_setPalette ( this->attr >> 14,  this->sprite->definition->palette->data );
}


inline void ComponentSprite_Release ( ComponentSprite *this ) {
	SPR_releaseSprite ( this->sprite );
}


inline int ComponentSprite_IsLastFrame ( ComponentSprite *this ) {
    Sprite * const s = this->sprite;
    return ( s->timer == 2  &&  s->frameInd == s->animation->numFrame-1 );
}


inline void ComponentSprite_SetAnim ( ComponentSprite *this, int index ) {
	SPR_setAnim ( this->sprite, index );
}