#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

void literals( void ) {

   // size as multiples of char
   size_t size = 0;

   // GCC -std=c99 komut satırı parametresi ve #include<stdbool.h> gerekli
   _Bool result = false;

/*

   Decimal: 97
   Hex    : 0x61
   Binary : 0b01100001
   Octal  : 0141

*/
   char c = 0;

   c = 97;   // decimal (base 10) literal
   c = 0x61; // hexadecimal (base 16) literal
   c = 0141; // octal (base 8) literal
   c = 'a';  // character literal

   // binary literal, gcc specific
   c = 0b01100001;

   // single char literals (ASCII)
   char c01 = 'a';
   char c02 = -67;
   char c03 = '\0';
   char c04 = 0;

   char c05 = ' ';
   char c06 = '\\';
   //char c07 = ''';

   // non printable chars (escape sequence)
   char c08 = '"';
   char c09 = '\a';
   char c10 = '\b';
   char c11 = '\f';
   char c12 = '\n';
   char c13 = '\r';
   char c14 = '\t';
   char c15 = '\v';

   char c16 = '\456'; // octal
   char c17 = '\xAF'; // hex

   //unsigned short     c18 = '\u20AC';
   //unsigned short int c19 = '\u20AC';
   //unsigned int       c20 = '\U40FFAA11';

   signed int si1 = -3;
   int        si2 = -3;

   long int liA = 10L;
   long     liB = 10L;

   long long int  lliA = 10LL;
   long long      lliB = 10LL;

   unsigned long long int ulliA = 10ULL;
   unsigned long long     ulliB = 10ULL;

   char text01[] = "hello";
   //char text02[] = "I'm";
   //char text03[] = "C:\Windows\System32\drivers\";
   //char text04[] = "he said "hello"";
   //char text05[] = "he said "hello"";

   // UNICODE char literal
   wchar_t wc01 = L'ç';
   size = sizeof( wc01 );

   // UNICODE string literal
   wchar_t text06[] = L"ĞÜŞİÖÇ ğüşiöç Iı";
   size = sizeof( text06 );

   // IEEE 754 single precision floating point number (4 Byte)
   float f01 = 0;
   float f02 = .0;
   float f03 = .0F;
   float f04 = 3.14F;
   float f05 = FLT_EPSILON;

   float pi          = 3.14159;
   float aMole       = 6.02E23;
   float anotherMole = 6.022e23;

   float electronCharge = 1.60217657e-19;
   float protonMass     = 1.67262178e-27;

   // IEEE 754 double precision floating point number (8 Byte)
   double d01 = .0;
   double d02 = .456;
   double d03 = DBL_EPSILON;

   // intel specific extended 80bit (10 Byte)
   long double ldGR = 1.618L;
   long double ldPI = 3.14159265358979323846264338328L;
   long double ld01 = LDBL_EPSILON;

   // C99 specific IEEE 754 double precision floating point HEXADECIMAL (base 16) literal
   // 1.100110011001100110011001100110011001100110011001101 x 2^(-4).
   double d04 = 0x1.999999999999Ap-4;

   double d05 = 0xF.999999999999aP-4;
   double d06 = 0xF.FFFFFFFFFFFFFP-4;
   double d07 = 0x1p-1;
   double d08 = 0x2p-1;
   double d09 = 0x3p-1;

   // Ap --> exact binary match

}//literals



itX = 0; // implicitly typed int
itY = 0; // implicitly typed int
void integers( void ) {

	char          c  = 0;
	signed char   sc = 0;
	unsigned char uc = 0;

	short         s  = 0;
	signed short  ss = 0;
	unsigned char us = 0;

	int          i  = 0;
	signed int   si = 0;
	unsigned int ui = 0;

	signed   sn = 0; // int
	unsigned un = 0; // int

	long          l  = 0;
	signed long   sl = 1;
	unsigned long ul = 1;

	long long          ll  = 0;
	signed long long  sll  = 1;
	unsigned long long ull = 1;

	// fixed length across platforms (  stdint.h or inttypes.h )
	int16_t  i16  = 0;
	uint16_t ui16 = 0;

	int32_t  i32  = 0;
	uint32_t ui32 = 0;

	size_t size = 0;

   // platform dependant and may vary platform to platform ( limits.h )
	int bitCount = CHAR_BIT;
	int value = CHAR_MIN;
	value     = CHAR_MAX;

	size = sizeof( char );
    //size = sizeof int;  //syntax error
    size = sizeof value;  // ok

    size = sizeof( c );
    size = sizeof( 0 );
	size = sizeof( 0L );
    size = sizeof( 0LL );

	size = sizeof( int );
	size = sizeof( unsigned int );
	bitCount = CHAR_BIT * sizeof( unsigned int );

	size = sizeof( i );
	size = sizeof( ui );

	ui = (unsigned) 0xFFFFFFFF;
	i  = (signed) ui;
    ui = 0xFFFFFFFF;

    // !
    // i = ui / ( i + 1 );

}//integers



void typePromotion( void ) {

	int   i =  1;
	float f =  0.10F;
	float r =  0.00F;

	r = f + i;

	char  c  = 2;
	short s  = 3;
	unsigned int u = 6;

	i = i + c;

	i = i + s;

	i = i + u;

	long long l = 1L + c;

}//typePromotion



void typePromotionPromoteToInt( void ) {

	// see disassembly
	// all ranks lower than int (signed or unsigned), promote to int
	_Bool b =  false;
	char  c =  'a';
	short s =  -8;

	int r = 0;

	r = b + c + s;

}//typePromotionPromoteToInt



void typePromotionSameWidth( void ) {

	// see disassembly
	// same size different rank
	signed   int negativeOne =  -1;
	unsigned int positiveOne =  +1;

	_Bool result = false;

	result = positiveOne < negativeOne;

}//typePromotionSameWidth














