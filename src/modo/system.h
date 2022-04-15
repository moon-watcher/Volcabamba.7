#pragma once

//typedef void (*modoSystemUpdateFn) (void*, int);

typedef struct System
{
    // API
    void ( *init   ) ( );
    void ( *update ) ( );
    void ( *delete ) ( );
    void ( *add    ) ( );

    // vars
    void ( *updatefn ) (  );
    void **list;
    unsigned length;
    //
    unsigned max;
    char *name;
}
System;