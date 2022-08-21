#include "modo.h"
#include "components/Timer.h"



systemDefineFn ( system_timer, {
    systemGetParam ( ComponentTimer, t );
    
    ComponentTimer_Update ( t );
});


System const system_Timer_tpl = { &system_timer, 40, 1, "Timer" };