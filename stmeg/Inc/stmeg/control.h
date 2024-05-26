#ifndef _CONTROL_H_
#define _CONTROL_H_


void foo( void );

void control_flow_if( void );

void control_flow_switch( void );

__attribute__((noinline))
void forcecompiler1 ( int* a, int* b );

__attribute__((noinline))
int forcecompiler2 ( int* r, int* a );


#endif
