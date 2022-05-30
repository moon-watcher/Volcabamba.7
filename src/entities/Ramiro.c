#include <genesis.h>
#include "inc/modo.h"
#include "inc/components.h"
#include "inc/systems.h"
#include "../res/spr_player.h"
#include "../libs/joyreader.h"


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

// jump
static void state2_enter  ( Entity* );
static void state2_update ( Entity* );
// static void state2_exit   ( Entity* );

State const player_State_tpl [ ] = {
    { state0_enter, state0_update, state0_exit, }, // stand
    { state1_enter, state1_update,              }, // walk
    { state2_enter, state2_update,              }, // jump
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



// stay //////////////////

static void state0_inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;

    COMPS(e);

    // run
    if ( joy_pressed_horizontal ( j ) )
    {
        entityState ( e, &player_State_tpl[1] );
        return;
    }

    // jump
    if ( joy_pressed_c(j) )
    {
        entityState ( e, &player_State_tpl[2] );
        return;
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
static void state1_inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;

    COMPS(e);

    // stay
    if ( joy_released_horizontal ( j ) ) {
        entityState ( e, &player_State_tpl[0] );
        return;
    }

    if ( joy_active_left(j) )  {
        SPR_setHFlip(sp->sprite,1);
    }
    else if ( joy_active_right(j) ) 
    {
        SPR_setHFlip(sp->sprite,0);
    }
}

static void state1_enter ( Entity *e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 1 );
    ci->handler = state1_inputHandler;
}

static void state1_update ( Entity *e ) {
    COMPS(e);
}



// jump //////////////////
static void state2_inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
//     Entity *e = ptr1;

//     COMPS(e);

//     if ( joy_released_horizontal ( j ) ) {
//         entityState ( e, &player_State_tpl[0] );
//         return;
//     }

//     if ( joy_active_left(j) )  {
//         SPR_setHFlip(sp->sprite,1);
//     }
//     else if ( joy_active_right(j) ) 
//     {
//         SPR_setHFlip(sp->sprite,0);
//     }
}
int counter1=100;

static void state2_enter ( Entity *e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 2 );
    ci->handler = state2_inputHandler;
}

static void state2_update ( Entity *e ) {
    COMPS(e);

Text("1àsdfa", 3,3);
    --counter1;
    Int(counter1, 0,0,4);
    if ( !counter1 ) 
        entityState ( e, &player_State_tpl[0] ); // down
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