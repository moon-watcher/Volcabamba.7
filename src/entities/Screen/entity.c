#include <genesis.h>

#include "mm.h" 
#include "inc.h"
#include "inc/states.h"


defineEntity ( 
    entity_screen,
    entity_screen_state_logo,

    { // comps
        .input = { .joy.port = PORT_1 }
    },

    { }, // awake 
    { }, // update
    { }  // delete
);