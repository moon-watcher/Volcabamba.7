static void move_enter ( Entity *entity )
{
    //
}

static void move_update ( Entity *entity )
{
    COMPONENTS ( entity );
    
    SYSTEM2 ( sysMovement, cp, cv     );
    SYSTEM2 ( sysSprite,   sp, cp     );
    SYSTEM2 ( sysInput,    ci, entity );
}

static State const moveState = (State)
{
    "Move State", &move_enter, &move_update, NULL,
};


// struct MoveState const moveState = (struct MoveState)
// {
//     { "Move State", &enter, &update, NULL },
//     12
// };

    // struct MoveState 
    // {
    //     State state;

    //     // other fields
    //     u16 timer;
    // };

    // struct MoveState const moveState;

//State const moveState;
