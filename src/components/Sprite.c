#include "Sprite.h"


static void init ( ComponentSprite *this, int x, int y )
{
    this->sprite = SPR_addSprite ( this->sd, x, y, this->attr );
    VDP_setPalette ( this->attr >> 14,  this->sprite->definition->palette->data );
}


static void release ( ComponentSprite *this )
{
	SPR_releaseSprite ( this->sprite );
}


static int isLastFrame ( ComponentSprite *this ) {
    Sprite *s = this->sprite;
    return ( s->timer == 2  &&  s->frameInd == s->animation->numFrame-1 );
}


struct $ComponentSprite $ComponentSprite = { init, release, isLastFrame };