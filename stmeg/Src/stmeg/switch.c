#include <math.h>


/*
 * switch sample : lookup table
 */
float sinus( int angle )
{
    // TODO : process sign 0..360 degrees
    angle = angle > 45 ? 90 - angle : angle;

    switch( angle ) {

        default : return NAN;

        case 0  : return .0000;
        case 1  : return .0175;
        case 2  : return .0349;
        case 3  : return .0523;
        case 4  : return .0698;
        case 5  : return .0872;
        case 6  : return .1045;
        case 7  : return .1219;
        case 8  : return .1392;
        case 9  : return .1564;
        case 10 : return .1736;
        case 11 : return .1908;
        case 12 : return .2079;
        case 13 : return .2250;
        case 14 : return .2419;
        case 15 : return .2588;
        case 16 : return .2756;
        case 17 : return .2924;
        case 18 : return .3090;
        case 19 : return .3256;
        case 20 : return .3420;
        case 21 : return .3584;
        case 22 : return .3746;
        case 23 : return .3907;
        case 24 : return .4067;
        case 25 : return .4226;
        case 26 : return .4384;
        case 27 : return .4540;
        case 28 : return .4695;
        case 29 : return .4848;
        case 30 : return .5000;
        case 31 : return .5150;
        case 32 : return .5299;
        case 33 : return .5446;
        case 34 : return .5592;
        case 35 : return .5736;
        case 36 : return .5878;
        case 37 : return .6018;
        case 38 : return .6157;
        case 39 : return .6293;
        case 40 : return .6428;
        case 41 : return .6561;
        case 42 : return .6691;
        case 43 : return .6820;
        case 44 : return .6947;
        case 45 : return .7071;

    };//switch

}//sinus
