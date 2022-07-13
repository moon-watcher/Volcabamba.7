#include "modo/system.h"
#include "components/Timer.h"



// systemFnDefine ( system_timer, {
//     systemFnGet ( ComponentTimer, t );
    
//     ComponentTimer_Update ( t );
// });



void system_timer ( System *const s ){
    for ( SystemNode *n = s->head; n;  ) {
        ComponentTimer *const t = n->data; n = n->next;
        ComponentTimer_Update ( t );
    }
}
