#include <genesis.h>
#include "inc/modo.h"
#include "inc.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_player.h"
#include "libs/joyreader.h"
#include "interfaces/common.h"





static void awake ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Init ( sp, cp->x.rounded, cp->y.rounded );
    ComponentInput_Init ( ci );

    struct sysnodes *a = malloc ( sizeof(struct sysnodes) );
    
    a->input_ci  = systemAdd ( sysInput,  ci );
    a->input_e   = systemAdd ( sysInput,  e  );
    a->sprite_sp = systemAdd ( sysSprite, sp );
    a->sprite_cp = systemAdd ( sysSprite, cp );

    e->sysnodes = a;
}


static void update ( Entity *const e ) {
    COMPS(e);

    if ( joy_active_left(joy)  ) C->dirH = -1;
    if ( joy_active_right(joy) ) C->dirH = +1;
}


static void delete ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Release ( sp );

    struct sysnodes *const a = e->sysnodes;

    systemDelete ( sysInput,  a->input_ci  );
    systemDelete ( sysInput,  a->input_e   );
    systemDelete ( sysSprite, a->sprite_sp );
    systemDelete ( sysSprite, a->sprite_cp );
}




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
    .exec = &(InterfaceCommon) {
        .setX = &setX,
        .setY = &setY,
        .enableInput = enableInput,
    }
};