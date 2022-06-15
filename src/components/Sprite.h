#pragma once

#include <genesis.h>

typedef struct {
	const SpriteDefinition* sd;
	unsigned                attr;
	Sprite*                 sprite;
}
ComponentSprite;


void ComponentSprite_Init        ( ComponentSprite*, int, int );
void ComponentSprite_Release     ( ComponentSprite* );
int  ComponentSprite_IsLastFrame ( ComponentSprite* );
void ComponentSprite_SetAnim     ( ComponentSprite*, int );