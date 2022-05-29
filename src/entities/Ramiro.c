#include <genesis.h>
#include "inc/modo.h"
#include "inc/components.h"
#include "inc/systems.h"
#include "../res/spr_player.h"
#include "../libs/joyreader.h"

static void null ( ) { };


#define COMPS(E)                            \
    Components        *C   = E->components; \
    ComponentSprite   *sp  = &C->sprite;    \
    ComponentPosition *cp  = &C->position;  \
    ComponentInput    *ci  = &C->input;     \
    Joyreader         *joy = &ci->joy;


typedef struct
{
    ComponentInput    input;
    ComponentSprite   sprite;
    ComponentPosition position;
}
Components;


// stay
static void state0_enter  ( Entity* );
static void state0_update ( Entity* );
static void state0_exit   ( Entity* );

// walk
static void state1_enter  ( Entity* );
static void state1_update ( Entity* );
// static void state1_exit   ( Entity* );

State const player_State_tpl [ ] = {
    { state0_enter, state0_update, state0_exit, }, // stand
    { state1_enter, state1_update, null         }, // walk
};



//////////////////////////////////////////////////////////////////////////////////////////////////////


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



// stand //////////////////

static void state0_inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    if ( joy_pressed_left ( j ) )
    {
        entityState ( ((Entity*) ptr1), &player_State_tpl[1] );
    }
}

static void state0_enter ( Entity *e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 0 );
    ci->handler = state0_inputHandler;
}

static void state0_update ( Entity *e ) {
    COMPS(e);
}

static void state0_exit ( Entity *e ) {
    COMPS(e);
}



// walk //////////////////

static void state1_enter ( Entity *e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 1 );
}

static void state1_update ( Entity *e ) {
    COMPS(e);
}





Entity const player_Entity_tpl = {
    .Awake  = awake,
    .Update = update,
    .Delete = delete,
    .state  = (State*) &player_State_tpl[0],
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite   = { &res_sprite_player, 0, TILE_ATTR(PAL3,1,0,0) },
        .position = { FIX32(123), FIX32(11) },
        .input    = { .joy.port = PORT_1 },
    },
};