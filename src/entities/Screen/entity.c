#include <genesis.h>

#include "modo/modo.h"
#include "data/systems.h"
#include "data/systems.h"
#include "data/states.h"
#include "components.h"
#include "../res/sprites.h"


static void _Awake  ( Entity *entity )
{
    COMPONENTS(entity);
    
    system_input_init ( ci, ci->joy.port );
}


Entity const screen_Entity_tpl = {
    .state = (State*) &screenLogo_State,
    .components = &(Components) {
        .input = { .joy.port = PORT_1 }
    },
    .compsSize = sizeof(Components),
    .Awake = _Awake,
};