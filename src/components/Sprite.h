#pragma once

#include <genesis.h>

typedef struct
{
	const SpriteDefinition* sd;
	unsigned                attr;
	Sprite*                 sprite;
}ComponentSprite;
