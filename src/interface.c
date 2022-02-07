
#include <genesis.h>

void interfac1 ( )
{
    typedef struct
    {
        int  a;
        char b;
        int  c;
    }
    Interface;

    typedef struct
    {
        int  primero;
        char segundo;
    }
    Implementation1;

    typedef struct
    {
        int  primero;
        char segundo;
        int  tercero; 

        // otros
        char cuarto;
    }
    Implementation2;

    Interface var1 = { 1, 2, 3 };
    Interface var2 = { 7, 8, 9 };
    Implementation1 *i1 = (Interface*) &var1;
    Implementation2 *i2 = (Interface*) &var2;

    i2->primero = 11;
    i2->cuarto  = 4;

    drawInt ( i1->primero, 1, 1, 2 ); // 11
    drawInt ( i1->segundo, 1, 2, 2 ); // 2

    drawInt ( i2->primero, 1, 4, 2 ); // 11
    drawInt ( i2->segundo, 1, 5, 2 ); // 8
    drawInt ( i2->tercero, 1, 6, 2 ); // 9
    drawInt ( i2->cuarto,  1, 7, 2 ); // 4
}