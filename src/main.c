#include <genesis.h>
#include "inc/modo.h"


void main ( ) {
    modo_init     = modo ( NULL );
    modo_managers = modo ( &managerUpdate );
    modo_middle   = modo ( NULL );
    modo_systems  = modo ( &systemUpdate );
    modo_end      = modo ( NULL );

    game ( );

    while ( 1 ) {
        modoUpdate ( modo_init     );
        modoUpdate ( modo_managers );
        modoUpdate ( modo_middle   );
        modoUpdate ( modo_systems  );
        modoUpdate ( modo_end      );
    }
}