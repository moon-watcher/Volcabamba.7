#include "Velocity.h"


static inline fix32 _update ( ComponentVelocity_Inner * const x ) {
    fix32 vel     = x->vel;
    char  dir     = x->dir;
    fix32 maximum = x->maximum;

    if ( dir )
        vel = fix32Add ( vel, ( dir > 0 ) ? +x->acceleration : -x->acceleration );
    else if ( vel )
        vel = fix32Add ( vel, ( vel > 0 ) ? -x->deceleration : +x->deceleration );

    return clamp ( vel, -maximum, +maximum );
}


inline void ComponentVelocity_Update ( ComponentVelocity *this ) {
    ComponentVelocity_Inner * const x = &this->x;
    ComponentVelocity_Inner * const y = &this->y;

    x->vel = _update ( x );
    y->vel = _update ( y );
}
