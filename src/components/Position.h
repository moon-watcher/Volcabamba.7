#pragma once

#include <genesis.h>


typedef struct {
	int   rounded;
	fix32 pos;
}
ComponentPosition;


typedef struct {
	ComponentPosition x;
	ComponentPosition y;
}
ComponentPosition2D;




#define ComponentPosition_Set( this, v ) \
	this.pos = intToFix32 ( this.rounded = v );

#define ComponentPosition2D_SetX( this, v ) \
	this->x.pos = intToFix32 ( this->x.rounded = v );

#define ComponentPosition2D_SetY( this, v ) \
	this->y.pos = intToFix32 ( this->y.rounded = v );
