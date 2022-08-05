#pragma once


typedef struct ModoNode {
	void *data;
	struct ModoNode *next;
	unsigned char count;
}
ModoNode;


typedef struct {
	ModoNode *head;
	void (*update)();
	unsigned char size;
}
Modo;


Modo *modo             ( void (*)() );
void  modoAdd          ( Modo *const, void *const );
void  modoUpdate       ( Modo *const );
void  modoDelete       ( Modo *const, void *const );
void  modoDeleteForce  ( Modo *const, void *const );
void  modoInfoManagers ( Modo *const );
void  modoInfoSystems  ( Modo *const );