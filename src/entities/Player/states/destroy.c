#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"


defineState ( entity_Player_state_destroy,
{ },
{ },
{
    ComponentSprite_Release ( sp );
}
);