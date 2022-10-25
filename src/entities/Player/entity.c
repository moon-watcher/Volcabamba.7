#include <genesis.h>
#include "mm.h"
#include "inc.h"
#include "inc/states.h"
#include "../res/spr_player.h"
#include "interfaces/common.h"
// #include "libs/joyreader.h"
// #include "inc/systems.h"



static void setX ( Entity *const e, int pos ) {
    Components          *const C  = e->components;
    ComponentPosition2D *const cp = &C->position;

    ComponentPosition_Set ( cp->x, pos );
}

static void setY ( Entity *const e, int pos ) {
    Components          *const C  = e->components;
    ComponentPosition2D *const cp = &C->position;

    ComponentPosition_Set ( cp->y, pos );
}

static void enableInput ( Entity *const e, bool enable ) {
    Components     *const C   = e->components;
    ComponentInput *const ci  = &C->input;

    ci->joy.port = enable ?: -1;
}




Entity const entity_Player_tpl = {
    .state      = (State*) &entity_Player_state_init,
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite = { &res_sprite_player, TILE_ATTR(PAL3,1,0,0) },
        .input  = { .joy.port = PORT_1 },
        .dirH = 1,
    },
    .exec = &(InterfaceCommon) {
        .setX = &setX,
        .setY = &setY,
        .enableInput = enableInput,
    }
};