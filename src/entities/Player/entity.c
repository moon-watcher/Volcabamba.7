#include <genesis.h>
#include "inc/modo.h"
#include "components.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_player.h"
#include "libs/joyreader.h"


static void awake ( Entity *const e ) {
    COMPS(e);

    ComponentPosition_Set ( cp->x, 100 );
    ComponentPosition_Set ( cp->y, 100 );

    ComponentSprite_Init ( sp, cp->x.rounded, cp->y.rounded );
    ComponentInput_Init ( ci );
}


static void update ( Entity *const e ) {
    COMPS(e);

    systemAdd2 ( sysSprite, sp, cp );
    systemAdd2 ( sysInput,  ci,  e );

    if ( joy_active_left(joy)  ) C->dirH = -1;
    if ( joy_active_right(joy) ) C->dirH = +1;
}


static void delete ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Release ( sp );
}



Entity const entity_Player_tpl = {
    .Awake  = awake,
    .Update = update,
    .Delete = delete,
    .state  = (State*) &entity_Player_state_stay,
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite = { &res_sprite_player, TILE_ATTR(PAL3,1,0,0) },
        .input  = { .joy.port = PORT_1 },
        .dirH = 1,
    },
};