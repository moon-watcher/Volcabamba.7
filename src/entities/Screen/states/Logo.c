#include <genesis.h>

#include "modo/modo.h"
#include "inc/systems.h"
#include "inc/entities.h"
#include "inc/managers.h"
#include "inc/states.h"
#include "../components.h"
#include "../res/logos.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;
    
    COMPONENTS(entity);

    if ( joy_pressed_start ( j ) )
    {
        modoEntityState ( entity, &screenTitle_State );
    }
}


modoStateDefine ( screenLogo_State,
    
    { /* enter */
        COMPONENTS(entity);
            
        ci->handler = inputHandler;

        SYS_disableInts();
        VDP_drawImage( VDP_BG_A, &res_logo_sega, 0,0);
        SYS_enableInts();
    },

    { /* update */
        COMPONENTS(entity);

        modoSystemAdd ( sysInput, ci     );
        modoSystemAdd ( sysInput, entity );
    },

    { /* exit */
        PAL_fadeOut(0,63,10,0);
        VDP_clearPlane(BG_A, 0);
        VDP_clearPlane(BG_B, 0);
    }
);