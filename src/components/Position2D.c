#include "Position2D.h"


static inline void setIntX ( ComponentPosition *this, int x ) {
	this->x = intToFix32 ( x );
}

static inline void setIntY ( ComponentPosition *this, int y ) {
	this->y = intToFix32 ( y );
}


struct $ComponentPosition $ComponentPosition = { setIntX, setIntY };