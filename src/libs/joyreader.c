#include <genesis.h>
#include "joyreader.h"


void joyreader_init ( Joyreader *joy, int port )
{
    joy->port = port;
    joyreader_reset ( joy );
}

void joyreader_update ( Joyreader *joy )
{
    unsigned active = JOY_readJoypad ( joy->port );

    joy->changed = active ^ joy->active;
    joy->active  = active;
}

void joyreader_reset ( Joyreader *joy )
{
    joy->active  = 0;
    joy->changed = 0;
}