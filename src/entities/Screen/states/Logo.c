#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "data/entities.h"
#include "data/managers.h"
#include "data/states.h"
#include "../components.h"
#include "../res/logos.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;
    
    COMPONENTS(entity);

    if ( joy_pressed_start ( j ) )
    {
        ecsEntityState ( entity, &screenTitle_State );
    }
}


ecsDefineState ( screenLogo_State,
    
    { /* enter */
        COMPONENTS(entity);
            
        ci->handler = inputHandler;

        SYS_disableInts();
        VDP_drawImage( VDP_BG_A, &res_logo_sega, 0,0);
        SYS_enableInts();
    },

    { /* update */
        COMPONENTS(entity);

        ecsSystemAdd ( sysInput, ci     );
        ecsSystemAdd ( sysInput, entity );
    },

    { /* exit */
        PAL_fadeOut(0,63,10,0);
        VDP_clearPlane(BG_A, 0);
        VDP_clearPlane(BG_B, 0);
    }
);