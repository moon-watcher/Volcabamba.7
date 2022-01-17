#include <genesis.h>
#include "joyreader.h"


Joyreader *joyreader_init ( unsigned port )
{
    Joyreader *joy = malloc ( sizeof ( Joyreader ) );

    joy->port = port;
    joyreader_reset ( joy );

    return joy;
}

void joyreader_update ( Joyreader *joy )
{
    if ( joy->paused )
    {
        return;
    }

    unsigned active = JOY_readJoypad ( joy->port );

    joy->changed = active ^ joy->active;
    joy->active  = active;
}

void joyreader_pause ( Joyreader *joy )
{
    joy->paused = TRUE;
}

void joyreader_reset ( Joyreader *joy )
{
    joy->active  = 0;
    joy->changed = 0;
    joy->paused  = FALSE;
}

void joyreader_end ( Joyreader *joy )
{
    free ( joy );
    joy = NULL;
}
