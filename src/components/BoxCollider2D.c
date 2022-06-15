#include "BoxCollider2D.h"


inline void ComponentBoxCollider2D_Init ( ComponentBoxCollider2D *this, ComponentBoxCollider2D * const tpl ) {
    memcpy ( this, tpl, sizeof(ComponentBoxCollider2D) );
}