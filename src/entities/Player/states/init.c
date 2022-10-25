#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"


defineState ( entity_Player_state_init,
{
    $e->state ( e, &entity_Player_state_stay );
},
{ },
{ }
);