#include <genesis.h>

#include "../inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_input ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentInput *ci     = array [ i++ ];
        Entity         *entity = array [ i++ ];
        
        joyreader_update ( &ci->joy );

        if ( ci->handler )
        {
            ci->handler ( &ci->joy, entity, NULL );
        }
    }
}


void system_input_init ( ComponentInput *ci, int port )
{
    joyreader_init ( &ci->joy, port );
}