#include <genesis.h>
#include "modo.h"
#include "components/Movement.h"
#include "components/Position.h"


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


systemDefineFn ( system_movement, {
    systemGetParam ( ComponentPosition2D, p );
    systemGetParam ( ComponentMovement2D, v );
    
    _update ( &v->x );
    _update ( &v->y );

    p->x.rounded = fix32ToInt ( p->x.pos += v->x.vel );
    p->y.rounded = fix32ToInt ( p->y.pos += v->y.vel );
});


System const system_Movement_tpl = { &system_movement, 70, 2, "Movement" };