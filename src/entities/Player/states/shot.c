#include <genesis.h>
#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"
#include "../inc/entities.h"
#include "../inc/managers.h"


static void enter ( Entity *e ) {
    COMPS(e);
    SPR_setAnim ( sp->sprite, 4 );


    managerAdd( manPlayersBullets, &entity_PlayerBullet_tpl);
}


static void update ( Entity *e ) {
    COMPS(e);

    Sprite *s = sp->sprite;
    if ( s->timer == 1  &&  s->frameInd == s->animation->numFrame-1)
        entityState ( e, e->prevState );
}


State const entity_Player_state_shot = { enter, update, .name="shot" };