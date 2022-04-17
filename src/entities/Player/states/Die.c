#include <genesis.h>

#include "modo/modo.h"
#include "inc/systems.h"
#include "inc/entities.h"
#include "inc/managers.h"
#include "inc/states.h"
#include "../components.h"



static void enter ( Entity *entity )
{
    COMPONENTS(entity);

    ci->handler = NULL;
    SPR_setAnim ( sp->sprite, 3 );
}


static void update ( Entity *entity )
{
    //
}


static void exit ( Entity *entity )
{
    //
}


State const Player_dieState = { enter, update, exit };