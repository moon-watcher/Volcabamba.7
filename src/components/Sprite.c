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


struct $ComponentSprite $ComponentSprite = { init, release };