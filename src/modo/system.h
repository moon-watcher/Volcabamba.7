#pragma once


typedef struct SystemNode {
	void *data;
	struct SystemNode *next;
	struct SystemNode *prev;
}
SystemNode;

typedef struct {
	 void (*update)(); 
     char *name;
	    
	SystemNode *head;
	SystemNode *tail;
}
System;


System     *system       ( void (*update) ( ), char *const );
void        systemUpdate ( System *const );
SystemNode *systemAdd    ( System *const, void *const );
void        systemDelete ( System *const, SystemNode *const );