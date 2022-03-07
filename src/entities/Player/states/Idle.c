#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "data/entities.h"
#include "data/managers.h"
#include "../components.h"
#include "../states.h"


static void inputHandler ( Joyreader *joy, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;

    if ( joy_pressed_dir ( joy ) )
    {
        ecsEntityState ( entity, &Player_moveState );
    }

    if ( joy_pressed_abc ( joy ) )
    {
        int x = 44;
        int y = 66;
        
        entity_PlayerBullet_create ( x, y );
    }
}


////////////////////////////////////////////////////////////////////////


static void enter ( Entity *entity )
{
    COMPONENTS(entity);

    ci->handler = inputHandler;
    cv->x.dir = 0;
    cv->y.dir = 0;
    SPR_setAnim ( sp->sprite, 0 );
}


static void update ( Entity *entity )
{
    //
}


static void exit ( Entity *entity )
{
    //
}


State const Player_idleState = { enter, update, exit };


/*
#define lambda(l_ret_type, l_arguments, l_body)        \
  ({                                                   \
   l_ret_type l_anonymous_functions_name l_arguments   \
   l_body                                              \
   &l_anonymous_functions_name;                        \
   })

#define lambda2(return_type, function_body) \ { \
      return_type __fn__ function_body \
 }
*/