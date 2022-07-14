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

    struct sysvars *a = malloc ( sizeof(struct sysvars) );
    
    a->input[0]  = systemAdd ( sysInput,  ci );
    a->input[1]  = systemAdd ( sysInput,  e  );
    a->sprite[0] = systemAdd ( sysSprite, sp );
    a->sprite[1] = systemAdd ( sysSprite, cp );

    e->sysvars = a;
}


static void update ( Entity *const e ) {
    COMPS(e);

    if ( joy_active_left(joy)  ) C->dirH = -1;
    if ( joy_active_right(joy) ) C->dirH = +1;
}


static void delete ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Release ( sp );

    struct sysvars *const a = e->sysvars;

    systemDelete ( sysInput,  a->input[0]  );
    systemDelete ( sysInput,  a->input[1]  );
    systemDelete ( sysSprite, a->sprite[0] );
    systemDelete ( sysSprite, a->sprite[1] );
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