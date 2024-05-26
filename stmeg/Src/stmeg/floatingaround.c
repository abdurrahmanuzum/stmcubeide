#include "stmeg/floatingaround.h"
#include <math.h>
#include <float.h>



void floatQuirks( void )
{
    float x = 1.1;
    _Bool result = x != 1.1;

    result = (float)x != (double)1.1;
    result = x != 1.1F;

   float f = 0.1F;

   // runtime calculations of values
   f = 0.0F;
   f += 0.2F;
   f += 0.2F;

   f += 0.2F;
   f += 0.2F;
   f += 0.2F;

   f += 0.2F;
   f += 0.2F;

   f += 0.2F;
   f += 0.2F;
   f += 0.2F;

   // compile time calculations of values
   float ft = 0.2F * 10;
   float fs = 0.2F + 0.2F + 0.2F + 0.2F + 0.2F + 0.2F + 0.2F + 0.2F + 0.2F + 0.2F;

   float fk = 0.5F;
   fk = 2.5F;
   float fk1 = 0;

   // runtime calculations of values
   fk1 += 2.6F;
   fk1 += 2.6F;
   fk1 += 2.6F;
   fk1 += 2.6F;
   fk1 += 2.6F;

   fk1 += 2.6F;
   fk1 += 2.6F;
   fk1 += 2.6F;
   fk1 += 2.6F;
   fk1 += 2.6F;

   float fk2 = 2.6F * 10;

   result = fk1 == fk2;

   int loop = 10;
   f = 0.0F;

   double value = .02;
   double diff = value - value;
   result = diff == NAN;


   while ( loop-- )
   {
      f += 0.1F;
   }


   f = 0.0F;
   for ( int j = 0 ; j < 10; j++ )
   {
      f += 0.1F;
   }

   result = f == ( 10 * 0.1F );

   float secondFromStart = nextafterf( FLT_EPSILON, INFINITY );

   // round(256.49999) == 256;
   // roundf(256.49999) == 257;

   // for(ever) : http://www.youtube.com/watch?v=IJNR2EpS0jw
   for( double d = 0; d != 0.3; d += 0.1 );

}//floatQuirks
