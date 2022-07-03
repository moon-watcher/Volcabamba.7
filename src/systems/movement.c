#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"


inline static void _update ( ComponentMovement *const cm ) {
    fix32 v            = cm->vel;
    fix32 acceleration = cm->acceleration;
    fix32 deceleration = cm->deceleration;
    fix32 maximum      = cm->maximum;
    int   dir          = cm->dir;

         if ( dir > 0 ) v += acceleration;
    else if ( dir < 0 ) v -= acceleration;
    else if ( v > 0 && (v -= deceleration) < 0 ) v = 0;
    else if ( v < 0 && (v += deceleration) > 0 ) v = 0;

    cm->vel = clamp ( v, -maximum, +maximum );
}


systemFnDefine ( system_movement, {
    ComponentPosition2D *p = systemFnGet;
    ComponentMovement2D *v = systemFnGet;
    
    _update ( &v->x );
    _update ( &v->y );

    p->x.rounded = fix32ToInt ( p->x.pos += v->x.vel );
    p->y.rounded = fix32ToInt ( p->y.pos += v->y.vel );
});



// void system_movement ( System *const system ) {
//     void *ref array = system->list;
//     int length = system->length; 

//     for ( int i = 0; i < length; ) {
//         ComponentPosition2D *p = array [ i++ ];
//         ComponentMovement2D *v = array [ i++ ];
        
//         _update ( &v->x );
//         _update ( &v->y );

//         p->x.rounded = fix32ToInt ( p->x.pos += v->x.vel );
//         p->y.rounded = fix32ToInt ( p->y.pos += v->y.vel );
//     }
// }