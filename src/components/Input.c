#include "Input.h"


inline static void init ( ComponentInput *this ) {
    Joyreader *joy = &this->joy; 
    joyreader_init ( joy, joy->port );
}


inline static void update ( ComponentInput *this ) {
    joyreader_update ( &this->joy );
}


inline static void handler ( ComponentInput *this, void (*handler)() ) {
    this->handler = handler;
}


struct $ComponentInput $ComponentInput = { init, update, handler };