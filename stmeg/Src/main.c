
#include <stdint.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <wchar.h>
#include <limits.h>
//#include <stddef.h>

#include <stdint.h>
#include <stdalign.h>

#include <stdlib.h>




void enable_fpu( void )
{

	__asm__
	(
		// CPACR is located at address 0xE000ED88
		"LDR.W	R0,	=0xE000ED88 \n\t"

		// or for execute only code, the instruction pair
		// MOVW R0, 0xED88
		// MOVT R0, 0xE000

		// Read CPACR
		"LDR	R1, [R0] \n\t"

		// Set bits 20-23 to enable CP10 and CP11 co-processors
		"ORR	R1, R1, #0xF << 20 \n\t"

		//Write back the modified value to the CPACR
		"STR	R1, [R0]"
	);


	// SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2) ); <--- dunno if works
}



void stackarray1 ( int size )
{
	int a = 0;
	int b = 1;

	int arr[size];

	int c = 2;
	int d = 3;

	arr[0] = -1;
}


// global (link scope) identifier, with storage
struct {
	float fX;
	float fY;
} PointF;

// declaration (can be many), no storage allocation :
// "there is an identifier definition called PointF in the global (link scope) scope
struct PointF;
struct PointF;
struct PointF;

// global (link scope) identifiers, with storage
struct {
	int X;
	int Y;
} g_pointA, g_pointB, g_pointC, *g_pointer;


// structure definition with TAG (PointD) to refer structure, no storage allocation
struct PointD {
	double dX;
	double dY;
};

// structure type definition without TAG, no storage allocation
typedef struct {
	int X;
	int Y;
} Point;

void structs( void ) {

	struct { char C; int I; double D; } mixA;
	mixA.C = 'a';
	mixA.I = 3;
	mixA.D = 1.618;

	// mixB's type is different than mixA's type although they are looking the same
	struct { char C; int I; double D; } mixB = { 'a', 3, 1.618 };


	// mixA = mixB; // error : incompatible types struct<anonymous>

	PointF.fX = .01F;
	PointF.fX = .02F;

	Point pointA = { 2, 3 };
	Point pointB = { .X = 2, .Y = 3 };
	Point pointC = { .Y = 4 }; // initializes .X with zero

	// pointA = { 4,5 }         // error
	pointA = (Point){ 4, 5 };  // ok : "compound literal" assignment

	// !!
	pointA = (Point){ .Y = 6 }; // !! overrides .X with zero

	//
	pointA = pointB;

	// PointF
    PointF.fY = .1F;
    PointF.fY = .2F;

    //global points
    g_pointA.X = 1;
    g_pointA.Y = 2;

    g_pointB.X = 10;
    g_pointB.Y = 20;

    g_pointC.X = 100;
    g_pointC.Y = 200;

    // assigment (copy)
    g_pointA = g_pointB;

    // struct member referencing
    g_pointer = &g_pointC;
    (*g_pointer).X = 22;
    (*g_pointer).Y = 33;

    // member dereferencing operator
    g_pointer->X = 44;
    g_pointer->Y = 55;

    struct PointD pointD1;
    struct PointD pointD2 = { .1, .2 };

    //pointD1 = { .1, .2 };              // error
    //pointD1 = (PointD){ .1, .2 };      // error
    pointD1 = (struct PointD){ .1, .2 }; // ok : "compound literal" assignment

	size_t position = 0;
	position = offsetof(  Point, Y );

}//structs

//-----------------------------------------------------------------------------









//-----------------------------------------------------------------------------

// gcc specific alignment attribute. See also __alignof__ (type)
struct TFieldAlign1 {
    uint8_t  ui8  __attribute__((aligned(16)));
    uint16_t ui16 __attribute__((aligned(16)));
};

// C11 specific _AlignAs
struct TFieldAlign2 {
	_Alignas (16) uint8_t  ui8 ;
	alignas(16)  uint16_t ui16 ; // macro: include stdalign.h
};


//typedef struct { double C1; char C2; char D; }__attribute__((packed)) AS6 ;

// unordered fields (regards to size)
typedef struct {
     char c;
     int  i;
     unsigned short us;
     char c2;
     double d;
} AS7;

// use "packed" attribute
typedef struct {
     char c;
     int  i;
     unsigned short us;
     char c2;
     double d;
} __attribute__((packed, aligned(1))) AS8;

// use "packed" attribute
typedef struct __attribute__( ( packed, aligned(1)) ) {
     char c;
     int  i;
     unsigned short us;
     char c2;
     double d;
} AS8a;

// use decreasing order of size
typedef struct {
     double d;
     int  i;
     unsigned short us;
     char c;
     char c2;
} AS9;

typedef struct { int   I; double  D;   char C; } AS1;
typedef struct { char  C;    int  I; double D; } AS2;
typedef struct { char C1;   char C2; double D; } AS3;
typedef struct { char C1;   char C2;    int D; } AS4;
typedef struct { double C1;   char C2; char D; } AS5;

typedef struct { double C1; char C2; char D; }__attribute__((packed)) AS6 ;

void structs_Alignment( void ) { // include stdalign.h

	// CPU's "natural" alignment ( register size, instruction size )
	// padding & padding bits
	// padding & padding bits initialization

	AS1 s1;

	s1.I = 1;
	s1.D = 1.0;
    s1.C = 'A';


	size_t sz1 = sizeof( AS1 );
	size_t sz2 = sizeof( AS2 );

	size_t align = 0;

	//align = _( AS1 ); // macro: include stdalign.h
	align = _Alignof( AS2 );
	align = _Alignof( AS3 );
	align = _Alignof( AS4 );
	align = _Alignof( AS5 );
	align = _Alignof( AS6 );
	align = _Alignof( AS7 );
	align = _Alignof( AS8 );

	int size = 0;
	size = sizeof( AS1 );
	size = sizeof( AS2 );
	size = sizeof( AS3 );
	size = sizeof( AS4 );
	size = sizeof( AS5 );
	size = sizeof( AS6 );
	size = sizeof( AS7 );
	size = sizeof( AS8 );

	size_t position = 0;
	position = offsetof(  AS3, C1 );
	position = offsetof(  AS4, C2 );

	//size_t sze = sizeof(max_align_t);

}//structs_Alignment

//-----------------------------------------------------------------------------



__attribute__(( packed, aligned(1) ))
typedef struct { char c1; char c2; double d; } A1;

typedef struct { char c1; char c2; double d; } A8;










void memoryManagement_alloc_calloc_realloc_free( void ) {

    char textA = NULL;

    //textA = "lorem ipsum";// !! DON'T it's risky

    // returned memory block contains "garbage" values.
    textA = (char) malloc( 12 );
    if ( NULL == textA )
       goto EXIT;

   strcpy( textA, "lorem ipsum" );

    char textB = NULL;

    // returned memory block contains "zeroed" values.
    textB = (char) calloc( 16, 1 );
    if ( NULL == textB )
       goto EXIT;

    strcpy( textB, " dolor sit amet" );

    size_t sizeA = strlen( textA );
    size_t sizeB = strlen( textB );

    // after successful realloc, previously malloced-buffer passed as first argument
    // is no longer valid and should not be "freed()".
    void* newBlock = realloc( textA, sizeA + sizeB + 1 );
   textA = newBlock ? (char*) newBlock : textA;

EXIT:
    textA ? 0 : free( textA );
    textB ? 0 : free( textB );

}//memoryManagement_alloc_calloc_realloc_free

//-----------------------------------------------------------------------------



























//------------------------------------------------------------------------------

void pointers1( void ) {

   int a = 0;
   int b = 0;

   unsigned int addressX = 0;
   unsigned int addressY = 0;

   char ar[] = "vwxyz";
   int  *pi;
   int* piA = NULL;
   int* piB = NULL;

   pi = 0;
   pi = '\0';
   pi = NULL;

   pi  = &a;
   *pi = 3;

   addressX = &a;
   addressY = pi;

   a = 5;
   b = *pi;

   pi++;
   *pi = 7;

   pi  = ar;
   *pi = 1684234849;

   a   = 3;
   piA = &a;
   piB = &a;

   int c = 0;
   c = *piA;
   c = *piB;

   c = 4;
   *piB = c;
   c = a + *piA + *piB;

   char d[] = "efgh";
   *pi = *(int*)d;

}//pointers1

//-----------------------------------------------------------------------------

void pointers2( void ) {

   int a = 0;
   int b = 0;
   int c = 0;
   int d = 0;
   int e = 0;

   int* pi  = NULL;

   int arr[] = { 0, 0, 0, 0, 0 };

   pi = &arr[0];
   *pi = 15;

   pi = pi + 1;
   *pi = 20;

   pi += 1;
   *pi = 25;

   pi++;
   *pi = 30;

   *pi++ = 35;

   *pi = 40;

   arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 0;

   pi = &arr[0];
   *(pi + 0) = 2;
   *(pi + 1) = 4;
   *(pi + 2) = 6;
   *(pi + 3) = 8;
   *(pi + 4) = 10;

   arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 0;

   pi = &arr[0];
   pi[0] = 3;
   pi[1] = 5;
   pi[2] = 7;
   pi[3] = 9;
   pi[4] = 11;

   arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 0;

   *arr = 111;
   *(arr + 0) = 100;
   *(arr + 1) = 200;
   *(arr + 2) = 300;
   *(arr + 3) = 400;
   *(arr + 4) = 500;


   pi = &arr[4];
   pi[-4] = 10;
   pi[-3] = 20;
   pi[-2] = 30;
   pi[-1] = 40;
   pi[ 0] = 50;


   pi = &c;

   // !! danger
   *(pi - 1) = 22;
   *(pi - 2) = 11;

   *(pi + 1) = 44;
   *(pi + 2) = 55;

   *(pi + 3) = 66;
   *(pi + 4) = 77;

   a = b = c = d = e;

   pi = (int*)&pi;

   // !! danger
   pi[-1] = 8;
   pi[-2] = 7;
   pi[-3] = 6;
   pi[-4] = 5;
   pi[-5] = 4;

   arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = 0;

   0[arr] = 7;
   1[arr] = 6;
   2[arr] = 5;
   3[arr] = 4;
   4[arr] = 2;

   // http://www.youtube.com/watch?v=IJNR2EpS0jw
   *(pi + 5) = 88;
   *(pi + 6) = 99;

}//pointers2

//-----------------------------------------------------------------------------

void pointers3( void ) {

	// see disassembly
	int    a =  3;
	int   *b = &a;
	int  **c = &b;
	int ***d = &c;

	   a = 2;
	  *b = 3;
     **c = 4;
	***d = 5;

}//pointers3

//------------------------------------------------------------------------------

void pointers4( void ) {

   // see disassembly
   int arrI[ 5 ] = { 10, 20, 30, 40, 50 };

   int *piA = NULL;
   int *piB = NULL;

   long double arrLD[ 5 ] = { .10L, .20L, .30L, .40L, .50L };

   long double *pldA = NULL;
   long double *pldB = NULL;

   size_t        size = 0;
   ptrdiff_t distance = 0;

   piA = &arrI[ 0 ];
   piB = &arrI[ 1 ];

   size = sizeof( int );
   distance = piA - piB;


   pldA = &arrLD[ 0 ];
   pldB = &arrLD[ 1 ];

   size = sizeof( long double );
   distance = pldA - pldB;

}//pointers4

//------------------------------------------------------------------------------

void pointers5( void ) {

   // see disassembly
   int arr[ 5 ] = { 10, 20, 30, 40, 50 };

   int *pi = NULL;

   pi = arr;

   arr[ 0 ]   = 11;
   *(arr + 0) = 12;
   pi[ 0 ]    = 13;
   *(pi + 0)  = 14;

   arr[ 1 ]   = 22;
   *(arr + 1) = 23;
   pi[ 1 ]    = 24;
   *(pi + 1)  = 25;

   arr[ 2 ]   = 33;
   *(arr + 2) = 34;
   pi[ 2 ]    = 35;
   *(pi + 2)  = 36;

   arr[ 3 ]   = 44;
   *(arr + 3) = 45;
   pi[ 3 ]    = 46;
   *(pi + 3)  = 47;

   arr[ 4 ]   = 55;
   *(arr + 4) = 56;
   pi[ 4 ]    = 57;
   *(pi + 4)  = 58;

}//pointers5

//------------------------------------------------------------------------------

void pointers6( void ) {

   // see disassembly
   int *arr = NULL;

   arr = malloc( 5 * sizeof(int) );

   arr[ 0 ]   = 11;
   *(arr + 0) = 12;

   arr[ 1 ]   = 22;
   *(arr + 1) = 23;

   arr[ 2 ]   = 33;
   *(arr + 2) = 34;

   arr[ 3 ]   = 44;
   *(arr + 3) = 45;

   arr[ 4 ]   = 55;
   *(arr + 4) = 56;

   free( arr );

}//pointers6

//------------------------------------------------------------------------------

void pointersConstantPointers( void ) {

   int a = 0;
   int b = 0;

   // both same
   const int *pcA;
   int const *pcB;

   int *const cpi = &a;

   const int *const cpci = &a;

   pcA = &a;
   pcB = &b;

   // *pcA = 3; // error
   // *pcB = 5; // error

   // cpi = &b; // error

}//pointersConstantPointers


//------------------------------------------------------------------------------
















// defines special type for ( 3 x 4 ) of integers.
typedef int Special3D[ 3 ][ 4 ];

void arrays_multiDimensional() {

    char valuesA[ 5 ][ 2 ] = { {0,1}, {2,3}, {4,5}, {6,7}, {8,9} };

	int valuesB[   ][ 3 ] = { {1,3,5} , {2,4,6} };
	int valuesC[ 2 ][ 3 ] = { {1,3,5} , {2,4,6} };
	//int valuesC[ 2 ][  ] = { {1,3,5} , {2,4,6} };// error : array type has incomplete element type

	int valuesE[ 2 ][ 3 ][ 4 ] = {
		{
			{111, 112, 113, 114} ,  {121, 122, 123, 124} ,  {131, 132, 133, 134}
		},
		{
			{211, 212, 213, 214} ,  {221, 222, 223, 224} ,  {231, 232, 233, 234}
		}
	};

	int distanceAsBytes = (int)&valuesA[0][0] - (int)&valuesA[1][0];

	// see disassembly
	int value = 0;
	value = valuesA[0][0];
	value = valuesA[0][1];

	value = valuesA[1][0];
	value = valuesA[1][1];

	value = valuesA[2][0];
	value = valuesA[3][1];

	const int lengthI = 4;
	const int lengthJ = 3;
	const int lengthK = 2;

	size_t size = sizeof valuesE;

	for ( int k = 0; k < lengthK; k++ ) {

		for ( int j = 0; j < lengthJ; j++ ) {

			for ( int i = 0; i < lengthI; i++ ) {

				int hundreds = k + 1;
				int tens     = j + 1;
				int ones     = i;

				valuesE[ k ][ j ][ i ] = 100*hundreds + 10*tens + ones;
				printf( "%d%d%d ", hundreds, tens, ones );

			}//fori

		}//forj

	}//fork

	Special3D* p3D = NULL;
	size_t allocateBytes = sizeof(Special3D) * lengthK;

	void* buffer = malloc( allocateBytes );
	if ( buffer == NULL ) {
		// not enough memory, terminate the program with failure
	    exit( EXIT_FAILURE );
	}

	// Casting void* to int(*)[3][4]. Same effect as casting to Special3D*
	p3D = (int(*)[3][4]) buffer;

	for ( int k = 0; k < lengthK; k++ ) {

		for ( int j = 0; j < lengthJ; j++ ) {

			for ( int i = 0; i < lengthI; i++ ) {

				int hundreds = k + 1;
				int tens     = j + 1;
				int ones     = i;

				p3D[ k ][ j ][ i ] = 100*hundreds + 10*tens + ones;

			}//fori

		}//forj

	}//fork

    // free the previously allocated memory
	free( p3D );

}//arrays_multiDimensional

//-----------------------------------------------------------------------------

void arrays_multiDimensionalJagged() {

	// jagged array sample
	// refer https://en.wikipedia.org/wiki/Jagged_array
	int** values = NULL;

    // TODO : implement check for return value of all "malloc()"s for an allocation error
    int arrayCount = 3;
    values = (int**) malloc( arrayCount * sizeof(int*) );

    const int leastElementCount = 2;
	for ( int i = 0; i < arrayCount; i++ ) {

		int  length = i + leastElementCount;
		int* buffer = malloc( length * sizeof(int) );

		values[ i ] = buffer;

		// fill the buffer
		for ( int j = 0; j < length; j++ ) {

			values[ i ][ j ] = i*10 + j;

		}//forj

	}//fori


	int distanceAsBytes = (int)&values[0][0] - (int)&values[1][0];

	// see disassembly
	int value = 0;
	value = values[0][0];
	value = values[0][1];
	value = values[0][2];

	value = values[1][0];
	value = values[1][1];
	value = values[1][2];

	value = values[2][0];
	value = values[2][1];
	value = values[2][2];

	// TODO : we need lots of "free()"s here...

}//arrays_multiDimensionalJagged

//-----------------------------------------------------------------------------

void arrays_multiDimensionalJaggedvsFlat() {

	// jagged array sample
	// refer https://en.wikipedia.org/wiki/Jagged_array

	int** jagged = NULL;
    int   flat[3][3] = { {0,1,2}, {10,11,12}, {20,21,22} };

    // TODO : implement check for return value of all "malloc"s for an allocation error
    int arrayCount = 3;
    jagged = (int**) malloc( 2 * sizeof(int*) );

    const int leastElementCount = 2;
	for ( int i = 0; i < arrayCount; i++ ) {

		int  length = i + leastElementCount;
		int* buffer = malloc( length * sizeof(int) );

		jagged[ i ] = buffer;

		// fill the buffer
		for ( int j = 0; j < length; j++ ) {

			jagged[ i ][ j ] = i*10 + j;

		}//forj

	}//fori

	int distanceAsBytes = 0;
	distanceAsBytes = (int)&jagged[0][0] - (int)&jagged[1][0];
	distanceAsBytes = (int)&flat[0][0]   - (int)&flat[1][0];

	// see disassembly
	int value = 0;

	value = flat[0][0];
	value = jagged[0][0];

	value = jagged[0][0];
	value = jagged[0][1];
	value = jagged[0][2];

	value = jagged[1][0];
	value = jagged[1][1];
	value = jagged[1][2];

	value = flat[0][0];
	value = flat[0][1];
	value = flat[0][2];

	value = flat[1][0];
	value = flat[1][1];
	value = flat[1][2];

	// TODO : we need lots of "free()"s here...

}//arrays_multiDimensionalJagged

//-----------------------------------------------------------------------------









int main( void )
{


	enable_fpu();


	pointers1();
	pointers2();
	pointers3();
	pointers4();
	pointers5();
	pointers6();
	pointersConstantPointers();

	//memoryManagement_alloc_calloc_realloc_free();



	structs_Alignment();

	char c3 = 'N';
	char c2 = 'I';
	char c1 = 'A';
	char c0 = 'M';

	enable_fpu();

	stackarray1( 4 );








}



