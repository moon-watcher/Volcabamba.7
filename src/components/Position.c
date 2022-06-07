#include "Position.h"


static void setX ( ComponentPosition *this, int x ) {
	this->x = intToFix32 ( x );
}

static void setY ( ComponentPosition *this, int y ) {
	this->y = intToFix32 ( y );
}


struct $ComponentPosition $ComponentPosition = { setX, setY };