#include <genesis.h>

#include "../inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_input ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentInput * const ci     = array [ i++ ];
        Entity         * const entity = array [ i++ ];
        
        $ComponentInput.Update ( ci );

        if ( ci->handler )
        {
            ci->handler ( &ci->joy, entity, NULL );
        }
    }
}