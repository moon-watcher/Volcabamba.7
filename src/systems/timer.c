#include "mymodo/mm.h" 
#include "components/Timer.h"



mm_systemDefineFn ( system_timer, {
    mm_systemGetParam ( ComponentTimer, t );
    
    ComponentTimer_Update ( t );
});


System const system_Timer_tpl = { &system_timer, 40, 1, "Timer" };