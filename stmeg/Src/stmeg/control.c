#include "stmeg/control.h"

void ffoo( void )
{
	;
}

void control_flow_if( void )
{
	int a = 2;
	int b = 3;
	int c = 4;

	int r;
	if ( a > b )
	{
		r = a;
	}
	else
	{
		r = b;
	}


	if ( a + 1 > b )
	{
		ffoo();
	}
	else
	{
		ffoo();
	}


	if ( a >= b )
	{
		r = a;
	}
	else
	{
		r = b;
	}


	if ( a + 2 >= b )
	{
		ffoo();
	}
	else
	{
		ffoo();
	}


	if ( a < b )
	{
		r = a;
	}
	else
	{
		r = b;
	}


	if ( a < b )
	{
		ffoo();
	}


	if ( a <= b )
	{
		;
	}

}



void control_flow_switch( void )
{
	int a = 2;
	int b = 3;
	int c = 4;
	int d = 5;

	int r;

	if ( a == 1 )
	{
		r = b;
	}

	if ( a == 2 )
	{
		r = c;
	}

	if ( a == 3 )
	{
		r = d;
	}


	switch ( a )
	{
		case 1:
		case 2:
		case 3:
			r = a;
		break;

		case 4:
			r = b;
		break;

	}

}


/*
 * Used to make compiler generate sort of optimised
 * if-else assembly at -O2 level without nuking
 * out the entire code into oblivion.
 */
__attribute__((noinline))
void forcecompiler1 ( int* a, int* b )
{
	*a = 2;
	*b = 3;
}

__attribute__((noinline))
int forcecompiler2 ( int* r, int* a )
{
	return (*r)++ * (*a);
}

