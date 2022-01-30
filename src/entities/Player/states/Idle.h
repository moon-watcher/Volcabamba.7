static void idle_enter ( Entity *entity )
{
    //
}

static void idle_update ( Entity *entity )
{
    COMPONENTS ( entity );

    SYSTEM2 ( sysSprite, sp, cp     );
    SYSTEM2 ( sysInput,  ci, entity );
}

static State const idleState = (State)
{
    "Idle State", &idle_enter, &idle_update, NULL
};



// struct IdleState const idleState = (struct IdleState)
// {
//     { "Idle State", &enter, &update, NULL }
// };

    // struct IdleState
    // {
    //     State state;

    //     // other fields
    // };

    // struct IdleState const idleState;

//State const idleState;


