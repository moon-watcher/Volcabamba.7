#pragma once

#include <genesis.h>

typedef struct {
	fix32 x;
	fix32 y;
}
ComponentPosition;



#define ComponentPosition_SetIntX( this, v ) ({ \
	this->x = intToFix32 ( x );                 \
})

#define ComponentPosition_SetIntY( this, v ) ({ \
	this->y = intToFix32 ( v );                 \
})
