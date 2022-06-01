#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


int counter2;


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    //
}


static void enter ( Entity *e ) {
    COMPS(e);

    counter2 = 40;
    SPR_setAnim ( sp->sprite, 3 );
    ci->handler = inputHandler;
}


static void update ( Entity *e ) {
    COMPS(e);

    --counter2;
    Int(counter2, 0,1,4);

    if ( !counter2 ) 
        entityState ( e, &entity_Player_state_stay );
}



State const entity_Player_state_drop = { enter, update, };