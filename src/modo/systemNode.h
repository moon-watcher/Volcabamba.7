#pragma once


typedef struct SystemNode {
	void *data;
	struct SystemNode *next;
	struct SystemNode *prev;
}
SystemNode;


#define systemNodeSet( E, N, V );                       \
    SystemNode **V = malloc ( sizeof(SystemNode) * N ); \
    E->sysnodes = V;

#define systemNodeGet( E, V ) \
    SystemNode *const *V = E->sysnodes;



#define systemNodeStructSet( E, T, V ) \
    T *V = malloc ( sizeof(T) ); \
    E->sysnodes = V;
    
#define systemNodeStructGet( E, T, V ) \
    T *const V = E->sysnodes;
