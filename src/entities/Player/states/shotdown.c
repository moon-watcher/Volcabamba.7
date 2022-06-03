#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void enter ( Entity *e ) {
    COMPS(e);
    SPR_setAnim ( sp->sprite, 5 );
}


static void update ( Entity *e ) {
    COMPS(e);

    Sprite *s = sp->sprite;
    if ( s->timer == 1  &&  s->frameInd == s->animation->numFrame-1)
        entityState ( e, &entity_Player_state_jump );
}



State const entity_Player_state_shotdown = { enter, update };