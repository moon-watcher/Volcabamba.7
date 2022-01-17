#include <genesis.h>

#include "data/components.h"
#include "../libs/joyreader.h"


void system_input_update ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentInput *ci = array[i++];

        if ( ci->active )
        {
            joyreader_update ( ci->joy );
        }
    }
}


void system_input_init ( ComponentInput *input )
{
    if ( input->active )
    {
        input->joy = joyreader_init ( input->id );
    }
}