#include "stmeg/arrays.h"



void arrays( void ) {

   //int arrA[];  // error: array size missing
   int arrB[ 0 ];
   int arrC[ 5 ];

   char lettersA[] = { 65, 66, 67, 68, 69 };
   char lettersB[] = { 'A','B','C','D','E' };

   char stringA[] = { 'A','B','C','D','E', 0 };
   char stringB[] = { 'A','B','C','D','E', '\0' };
   char stringC[] = { "ABCDE" };

   wchar_t unicodeA[] = { L'Ğ', L'Ü', L'Ş', L'İ', L'Ö', L'Ç', 0 };
   wchar_t unicodeB[] = L"ĞÜŞİÖÇ";

   int arrQ[ 2 ] = { 1, 2, 3 }; // initialize the first 2, discard the 3rd.
   int arrW[ 3 ] = { 1, 2, 3 }; // initialize all.
   int arrX[ 4 ] = { 1, 2, 3 }; // initialize the first 3, leave 4th uninitialized.
   int arrY[ 5 ] = { [2] = 30 };// initialize the 3rd. initialize the rest with zero.
   int arrZ[ 5 ] = {};          // initialize all with zero.

   size_t size = 0;
   int count   = 0;


   //size = sizeof( arrA );
   size = sizeof( arrB );

   size  = sizeof( arrC );
   size  = sizeof arrC;
   count = sizeof( arrC ) / sizeof( int );

   size = sizeof( lettersA );
   size = sizeof( lettersB );

   size = sizeof( stringA );
   size = sizeof( stringB );
   size = sizeof( stringC );

   size = sizeof( wchar_t );
   size = sizeof( unicodeA );

   size  = sizeof( unicodeB );
   count = sizeof( unicodeB ) / sizeof( wchar_t );

   size = sizeof( arrW );
   size = sizeof( arrX );
   size = sizeof( arrY );

   size = sizeof stringB;
   size = sizeof( arrX );
   size = sizeof( arrY );

   size  = sizeof( arrC );
   size  = sizeof arrC;

   //arrA[ 0 ] = 1;
   arrB[ 0 ] = 1;

   arrC[ 0 ] = 10;
   arrC[ 1 ] = 20;

}//arrays

