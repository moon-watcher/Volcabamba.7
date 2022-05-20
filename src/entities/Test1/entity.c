#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "components.h"
#include "../res/sprites.h"




static void setWidth  ( ComponentBox *cb, unsigned v )
{
    cb->w = v;
}

static void setHeight ( ComponentBox *cb, unsigned v )
{
    cb->h = v;
}



typedef struct
{
    void (*setWidth)  ( Entity*, unsigned );
    void (*setHeight) ( Entity*, unsigned );
}
MyInterface;





static void Awake ( Entity *entity )
{
    // Se ejecuta una vez cuando se crea la entidad.
    // Aquí se inicializan cosas como:
    //
    // sprites
    // paleta
    // musica/sfx
    // controles
    // ...
    
    COMPONENTS(entity);

    // sp->sd = &res_hero1_sprite;
    // sp->index = 0;
    
    // system_sprite_init ( sp, cp );
    // system_input_init ( ci, ci->joy.port );
}


static void Update ( Entity *entity )
{
    COMPONENTS(entity);

    MyInterface *mi = entity->whatever;

    mi->setHeight ( cb, 12 );
    ((MyInterface*) entity->whatever)->setWidth  ( cb, cb->w+1 );

    drawUInt( cb->w, 0,0,3);
    drawUInt( cb->h, 0,1,3);
    
    unsigned area = cb->area ( cb );
    drawUInt( area, 0,2,3);

    

    // modoSystemAdd ( sysMovement, cp     );
    // modoSystemAdd ( sysMovement, cv     );
    // modoSystemAdd ( sysSprite,   sp     );
    // modoSystemAdd ( sysSprite,   cp     );
    // modoSystemAdd ( sysInput,    ci     );
    // modoSystemAdd ( sysInput,    entity );
}


static void Delete ( Entity *entity )
{
    // Se destruye todo lo inicializado en el Awake
}




//static const MyInterface myinterfacedata = ;

int calc_area ( ComponentBox *b )
{
    return b->h * b->w;
}

Entity const test1_entity_tpl = // ( Entity )
{
    .Awake = Awake,
    .Update = Update,
    .Delete = Delete,
    .state = (State*) &Player_idleState,
    .compsSize = sizeof(Components),
    .components = &(Components) {
        .box = { 3, 4, &calc_area },
    },
    .whatever = &(MyInterface)  { &setWidth, &setHeight },
    // .exec = &(EntityExecInterface) {
    //     .setPosition = setPosition,
    // }



};