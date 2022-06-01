#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


int counter1;


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    //
}


static void enter ( Entity *e ) {
    COMPS(e);

    counter1 = 40;
    SPR_setAnim ( sp->sprite, 2 );
    ci->handler = inputHandler;
}


static void update ( Entity *e ) {
    COMPS(e);

    --counter1;
    Int(counter1, 0,0,4);

    if ( !counter1 ) 
        entityState ( e, &entity_Player_state_drop );
}



State const entity_Player_state_jump = { enter, update };