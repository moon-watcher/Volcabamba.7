#pragma once

#include <genesis.h>


#define ComponentSprite_Init( A, B, C ) \
    A->sprite = SPR_addSprite ( A->sd, B, C, A->attr ); \
	VDP_setPalette ( A->attr >> 14,  A->sprite->definition->palette->data )

#define ComponentSprite_InitEx( A, B, C ) \
	A->sprite = SPR_addSpriteEx ( A->sd, B, C, A->attr, 0, A->flags); \
	VDP_setPalette ( A->attr >> 14,  A->sprite->definition->palette->data )
	
#define ComponentSprite_Release( A ) \
	SPR_releaseSprite ( A->sprite )


#define ComponentSprite_IsLastFrame( A ) \
	( A->sprite->timer == 2  &&  A->sprite->frameInd == A->sprite->animation->numFrame-1 )


#define ComponentSprite_SetAnim( A, B ) \
	SPR_setAnim ( A->sprite, B )



typedef struct {
	const SpriteDefinition *sd;
	unsigned                attr;
	unsigned                flags;
	Sprite*                 sprite;
}
ComponentSprite;