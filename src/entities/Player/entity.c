#include <genesis.h>
#include "inc/modo.h"
#include "components.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_player.h"
#include "libs/joyreader.h"


static void awake ( Entity *e ) {
    COMPS(e);

    sp->sprite = SPR_addSprite ( sp->sd, fix32ToRoundedInt(cp->x), fix32ToRoundedInt(cp->y), sp->attr );
    VDP_setPalette ( sp->attr >> 14,  sp->sprite->definition->palette->data );

    joyreader_init ( joy, joy->port );
}


static void update ( Entity *e ) {
    COMPS(e);

    systemAdd ( sysSprite, sp ); systemAdd ( sysSprite, cp );
    systemAdd ( sysInput,  ci ); systemAdd ( sysInput,   e );
}


static void delete ( Entity *e ) {
    COMPS(e);

    SPR_releaseSprite ( sp->sprite );
}



Entity const entity_Player_tpl = {
    .Awake  = awake,
    .Update = update,
    .Delete = delete,
    .state  = (State*) &entity_Player_state_stay,
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite   = { &res_sprite_player, TILE_ATTR(PAL3,1,0,0) },
        .position = { FIX32(123), FIX32(11) },
        .input    = { .joy.port = PORT_1 },
    },
};