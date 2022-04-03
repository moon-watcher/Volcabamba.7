#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "data/entities.h"
#include "data/managers.h"
#include "data/states.h"
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