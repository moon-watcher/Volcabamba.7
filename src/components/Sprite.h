#pragma once

#include <genesis.h>

typedef struct
{
	const SpriteDefinition* sd;
	int                     index;
	unsigned                attr;
	Sprite*                 sprite;
}
ComponentSprite;
