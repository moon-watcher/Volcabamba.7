#include <genesis.h>

#include "../libs/ECS.h"
#include "data/components.h"
#include "../libs/joyreader.h"


void system_input_update ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentInput *ci     = array[i++];
        Entity         *entity = array[i++];
        
        joyreader_update ( &ci->joy );

        ci->handler ( &ci->joy, entity, NULL );
    }
}


void system_input_init ( ComponentInput *ci, int port )
{
    joyreader_init ( &ci->joy, port );
}