
#include "inc/modo.h"
// #include "libs/draw.h"
// #include "inc/entities.h"
// #include "inc/systems.h"
// #include "inc/managers.h"
#include "inc/components.h"


#define COMPONENTS(entity)                      \
    Components     *comps = entity->components; \
    ComponentTimer *ct    = &comps->timer;      \
    ComponentInput *ci    = &comps->input;      \
    Joyreader      *joy   = &ci->joy;           


typedef struct
{
    ComponentInput input;
    ComponentTimer timer;
}
Components;


////////////////////////////////////////////////////////////////////////////////////////


static void enemy5_stand_State_enter ( Entity *const entity )
{
    COMPONENTS(entity);

    // ct->max = 100;
}



static void enemy5_Entity_update ( Entity *const entity )
{
    COMPONENTS(entity);

    //drawUInt ( ct->max++, 3, 22, 3 );
}


////////////////////////////////////////////////////////////////////////////////////////


int getIntFromEntity ( Entity *const entity )
{
    COMPONENTS(entity);

    return ct->max;
}

void setIntFromEntity ( Entity *const entity, int v )
{
    COMPONENTS(entity);

    ct->max = v;
}

////////////////////////////////////////////////////////////////////////////////////////


State const enemy5_stand_State_tpl =
{
    enemy5_stand_State_enter, 
};

Entity const enemy5_Entity_tpl =
{
    .Update = enemy5_Entity_update,
    .state = (State*) &enemy5_stand_State_tpl,
    .compsSize = sizeof(Components),
    .components = &(Components) {
        .timer = { 0, 8888 },
        .input = { .joy.port = PORT_1, NULL }
    },
    // .exec = &(EntityExecInterface) {
    //     .setIntFromEntity = setIntFromEntity,
    //     .getIntFromEntity = getIntFromEntity,
    // }
};