#pragma once

#include <genesis.h>

typedef struct {
	fix32 x;
	fix32 y;
}
ComponentPosition;


struct $ComponentPosition {
	void ( *SetIntX ) ( ComponentPosition*, int );
	void ( *SetIntY ) ( ComponentPosition*, int );
}
$ComponentPosition;