typedef struct {
    void (*setX) ( Entity*, int );
    void (*setY) ( Entity*, int );
    void (*enableInput)();
}
InterfaceCommon;


// void (*setPosition)      ( Entity*, fix32 x, fix32 y );
// void (*setFallara)       ( Entity*, int x, int y );
// int  (*getInt)           ( );
// int  (*getFalla)         ( );
// void (*disableInput)     ( Entity*, int nill );