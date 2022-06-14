#include "BoxCollider2D.h"


inline static void init ( ComponentBoxCollider2D *this, ComponentBoxCollider2D * const tpl ) {
    memcpy ( this, tpl, sizeof(ComponentBoxCollider2D) );
}


struct $ComponentBoxCollider2D $ComponentBoxCollider2D = { init };