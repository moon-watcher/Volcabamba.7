#include "mm.h" 
#include "components/Timer.h"



defineSystemFn ( system_timer, {
    systemGetParam ( ComponentTimer, t );
    
    ComponentTimer_Update ( t );
});


System const system_Timer_tpl = { &system_timer, 40, 1, "Timer" };