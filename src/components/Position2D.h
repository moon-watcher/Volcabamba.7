#pragma once

#include <genesis.h>

typedef struct {
	fix32 x;
	fix32 y;
}
ComponentPosition2D;


void ComponentPosition2D_SetIntX ( ComponentPosition2D*, int );
void ComponentPosition2D_SetIntY ( ComponentPosition2D*, int );