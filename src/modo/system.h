#pragma once


typedef struct SystemNode {
	void *data;
	struct SystemNode *next;
	struct SystemNode *prev;
}
SystemNode;

typedef struct {
	void (*update)();
	SystemNode *head;
	SystemNode *tail;
}
System;


System     *system       ( void (*) () );
void        systemUpdate ( System *const );
SystemNode *systemAdd    ( System *const, void* );
void        systemDelete ( System *const, SystemNode *const );