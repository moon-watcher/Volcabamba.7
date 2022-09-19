#include <genesis.h>

#include "mymodo.h" 
#include "inc.h"
#include "inc/states.h"


mm_entityDefine ( 
    entity_screen,
    entity_screen_state_logo,

    { // comps
        .input = { .joy.port = PORT_1 }
    },

    { }, // awake 
    { }, // update
    { }  // delete
);