#pragma once

#include <genesis.h>

typedef struct {
	const SpriteDefinition* sd;
	unsigned                attr;
	Sprite*                 sprite;
}
ComponentSprite;


struct $ComponentSprite {
	void ( *Init        ) ( ComponentSprite*, int, int );
	void ( *Release     ) ( ComponentSprite* );
	int  ( *IsLastFrame ) ( ComponentSprite* );
	void ( *SetAnim     ) ( ComponentSprite*, int );
}
$ComponentSprite;