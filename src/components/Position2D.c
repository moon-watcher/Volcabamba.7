#include "Position2D.h"


inline void ComponentPosition2D_SetIntX ( ComponentPosition2D *this, int x ) {
	this->x = intToFix32 ( x );
}

inline void ComponentPosition2D_SetIntY ( ComponentPosition2D *this, int y ) {
	this->y = intToFix32 ( y );
}