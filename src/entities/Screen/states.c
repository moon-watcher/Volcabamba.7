#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/entities.h"
#include "inc/managers.h"
#include "inc/states.h"
#include "components.h"
#include "../res/logos.h"

static void enter ( Entity *entity, const Image *image, int x, int y, void *handler )
{
    COMPONENTS(entity);

    ci->handler = handler;

    SYS_disableInts();
    VDP_drawImage ( VDP_BG_A, image, x, y );
    SYS_enableInts();
}

static void update ( Entity *entity )
{
    COMPONENTS(entity);

    modoSystemAdd ( sysInput, ci     );
    modoSystemAdd ( sysInput, entity );
}

static void exitFade()
{
    PAL_fadeOut(0,63,10,0);
    VDP_clearPlane(BG_A, 0);
    VDP_clearPlane(BG_B, 0);
}
 

static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;
    
    COMPONENTS(entity);

    if ( joy_pressed_start ( j ) )
    {
        modoEntityState ( entity, &screenTitle_State );
    }
}

static void inputHandler2 ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;

    COMPONENTS(entity);

    if ( joy_pressed_start ( j ) )
    {
        modoEntityState ( entity, &screenGameloop_State );
    }
}






modoDefineState ( screenLogo_State,
    
    { /* enter */

        enter ( entity, &res_logo_sega, 0, 0, inputHandler );
    },

    { /* update */
        update(entity);
    },

    { /* exit */
        exitFade();
    }
);


modoDefineState ( screenTitle_State,

    { /* enter */
        enter ( entity, &res_logo_sega, 4, 5, inputHandler2 );
    },

    { /* update */
        update(entity);
    },

    { /* exit */
        exitFade();
    }
);