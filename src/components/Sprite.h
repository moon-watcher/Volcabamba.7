#pragma once

#include <genesis.h>

typedef struct
{
	const SpriteDefinition* sd;
	//int                     index;
	unsigned                attr;
	Sprite*                 sprite;
}
ComponentSprite;




struct $ComponentSprite
{
	void ( *Init    ) ( ComponentSprite*, int, int );
	void ( *Release ) ( ComponentSprite* );
	
}
$ComponentSprite;

