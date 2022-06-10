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
	void ( *SetX ) ( ComponentPosition*, int );
	void ( *SetY ) ( ComponentPosition*, int );
}
$ComponentPosition;