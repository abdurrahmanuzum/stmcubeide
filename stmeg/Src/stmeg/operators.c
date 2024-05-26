


void operators_additive( void )
{
   // see disassembly
   char ca = 2;
   char cb = 3;
   char cc = 0;

   short sa = 2;
   short sb = 3;
   short sc = 0;

   int ia = 2;
   int ib = 3;
   int ic = 0;

   unsigned int ua = 2;
   unsigned int ub = 3;
   unsigned int uc = 0;

   float fa = .2F;
   float fb = .3F;
   float fc = .0F;

   cc = ca + cb;
   cc = cb - ca;
   cc = ca - cb;


   /*
    * Compare the number of opcodes between
    * operating on shots and operating on ints.
    * Using the native type of the processor
    * reduces the number of opcodes required.
    */
   sc = sa + sb;
   sc = sb - sa;
   sc = sa - sb;

   ic = ia + ib;
   ic = ib - ia;
   ic = ia - ib;


   uc = ua + ub;
   uc = ub - ua;
   uc = ua - ub;

   fc = fa + fb;
   fc = fb - fa;
   fc = fa - fb;

}//operators_additive



void operators_multiplicative( void )
{
   // see disassembly
   char ca = 2;
   char cb = 3;
   char cc = 0;

   int ia = 2;
   int ib = -3;
   int ic = 0;

   unsigned int ua = 2;
   unsigned int ub = 3;
   unsigned int uc = 0;

   float fa = .2F;
   float fb = .3F;
   float fc = .0F;

   cc = ca * cb;
   cc = cc / ca;
   cc = cb % ca;

   ic = ia * ib;
   ic = ic / ia;
   ic = ib % ia;

   uc = ua * ub;
   uc = uc / ua;
   uc = ub % ua; // remainder

   fc = fa * fb;
   fc = fc / fa;

   //fc = fc % fa; // ?
   //fc = fc % ia; // ?

   // remainder
   int a =  ib % -5;
   int b = ib %  2;
   int c = ib % -2;

}//operators_multiplicative



void operators_binary( void )
{
   // see disassembly
   char ca = 2;
   char cb = 3;
   char cc = 0;

   short sa = 2;
   short sb = 3;
   short sc = 0;

   int ia = 2;
   int ib = 3;
   int ic = 0;

   unsigned int ua = 2;
   unsigned int ub = 3;
   unsigned int uc = 0;

   cc = ca & cb;
   cc = ca | cb;
   cc = ca ^ cb;
   cc = ~ca;

   cc = ca << 1;
   cc = ca << 2;

   sc = sa & sb;
   sc = sa | sb;
   sc = sa ^ sb;
   sc = ~sa;

   sc = sa << 1;
   sc = sa << 2;

   sc = -3;
   sc = sc << 1;
   sc = -3;
   sc = sc >> 1;

   ic = ia & ib;
   ic = ia | ib;
   ic = ia ^ ib;
   ic = ~ia;

   ic = -3;
   ic = ic << 1;
   ic = -3;
   ic = ic >> 1;

   uc = ua & ub;
   uc = ua | ub;
   uc = ua ^ ub;
   uc = ~ua;

   uc = 8;
   uc = uc << 1;
   uc = 8;
   uc = uc >> 1;

}//operators_binary



void operators_logical( void )
{
  // see disassembly
  int a = 2;
  int b = 3;
  int c = 0;

  _Bool result = 0;

  // equality
  result = a == a;
  result = !( a != b );

  // inequality
  result = a != b;
  result = !( a == b );

  // logical and
  result = ( a > b ) && ( b > c );

  // logical inclusive or
  result = ( a > b ) || ( b > c );

  // logical exclusive or (equivalent)
  result = ( a > b ) != ( b > c );

  // bool normalized exclusive or (equivalent)
  result = !a != !c;
  result = (_Bool)a != (_Bool)c;

  result = a >= b;
  result = !( a < b );

  result = a < b;
  result = !( a >= b );

  result = a <= b;
  result = !( a > b );

}//operators_logical



void operators_assignment( void )
{
   // see disassembly
   int a = 2;
   int b = 3;
   int r = 0;

   r = r + 1;
   r += 1;

   r = r - 1;
   r -= 1;

   r = 1;
   r = r * a;
   r *= a;

   r = r / 2;
   r /= 2;

   r = 5;
   r = r % 2;

   r = 5;
   r %=  2;

   // TODO : diğer "compound assignment" operatörleri

}//operators_assignment



void operators_conditionalExpression( void )
{
   // see disassembly
   int a = 2;
   int b = 3;

   int min = 0;
   int max = 0;

   min =  a < b ? a : b;
   max =  a > b ? a : b;

   if ( a < b )
   {
      min = a;
   }
   else
   {
      min = b;
   };

   if ( a > b )
   {
      max = a;
   }
   else
   {
      max = b;
   };


   int  x    = 0;
   char sign = '.';

   x = 0;
   sign = x < 0 ? '-' :
          x > 0 ? '+' :
          '.';

   if ( x < 0 )
   {
	   sign = '-';
   }
   else if ( x > 0 )
   {
	   sign = '+';
   }
   else
   {
	   sign = '.';
   }

   x = -5;
   sign = x < 0 ? '-' :
          x > 0 ? '+' :
          '.';

   x = +5;
   sign = x < 0 ? '-' :
          x > 0 ? '+' :
          '.';

   enum { colder, cold, warm, hot, hotter } climate = colder;

   int c = 18;
   climate = ( c <= -10 ) ? colder :
             ( c > -10 ) && ( c <= 10 ) ? cold :
             ( c >  10 ) && ( c <= 25 ) ? warm :
             ( c >  25 ) && ( c <= 35 ) ? hot  :
             hotter;


}//operators_conditionalExpression
