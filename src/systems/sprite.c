#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"



systemFnDefine ( system_sprite, {
    ComponentSprite     *const sp = systemFnGet;
    ComponentPosition2D *const cp = systemFnGet;

    SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
});



// void system_sprite ( System *const system ) {
//     void *ref array = system->list;
//     int length = system->length; 

//     for ( int i = 0; i < length; ) {
//         ComponentSprite     *const sp = array [ i++ ];
//         ComponentPosition2D *const cp = array [ i++ ];
    
//         SPR_setPosition ( sp->sprite, cp->x.rounded, cp->y.rounded );
//     }
// }