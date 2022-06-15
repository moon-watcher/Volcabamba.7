#include "Input.h"


inline void ComponentInput_Init ( ComponentInput *this ) {
    Joyreader *joy = &this->joy; 
    joyreader_init ( joy, joy->port );
}


inline void ComponentInput_Update ( ComponentInput *this ) {
    joyreader_update ( &this->joy );
}


inline void ComponentInput_Handler ( ComponentInput *this, void (*handler)() ) {
    this->handler = handler;
}