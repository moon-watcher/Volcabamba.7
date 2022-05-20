#include <genesis.h>

#include "../inc/modo.h"
#include "inc/components.h"


void system_timer ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentTimer *timer = array [ i++ ];
        
        $ComponentTimer.Update ( timer );
    }
}