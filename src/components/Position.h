#pragma once

#include <genesis.h>

typedef struct
{
	fix32 x;
	fix32 y;
    //fix32 z;
}
ComponentPosition;


struct $ComponentPosition {
	void ( *setX ) ( ComponentPosition*, int );
	void ( *setY ) ( ComponentPosition*, int );
}
$ComponentPosition;