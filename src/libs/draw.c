#include <genesis.h>
#include "draw.h"

void drawText ( const char *str, u16 x, u16 y )
{
    SYS_disableInts();
    VDP_drawText ( str, x, y );
    SYS_enableInts();
}


void drawInt ( u32 nb, u8 x, u8 y, u8 zeros )
{
    char str [ zeros+1 ];
    intToStr ( nb, str, zeros );

    drawText ( str, x, y );
}


void drawUInt ( u32 nb, u8 x, u8 y, u8 zeros )
{
    char str [ zeros+1 ];
    uintToStr ( nb, str, zeros );

    drawText ( str, x, y );
}


void drawFix32 ( fix32 nb, u8 x, u8 y, u8 zeros )
{
    char str[16];

    fix32ToStr ( nb, str, zeros );
    drawText ( str, x, y );
}


void drawMem ( u8 x, u8 y )
{
    drawUInt ( MEM_getAllocated(), x, y, 5 );
}



void Text ( const char *str, u16 x, u16 y ) { drawText ( str, x, y );       }
void Int  ( u32 nb, u8 x, u8 y, u8 zeros )  { drawInt  ( nb, x, y, zeros ); }
void UInt ( u32 nb, u8 x, u8 y, u8 zeros )  { drawUInt ( nb, x, y, zeros ); }
