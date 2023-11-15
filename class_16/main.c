#include <math.h>
#include <stdio.h>

long double myAsin( double x )
{
    long double result = 0;
    long double a = 0;

    // The calculation of 0th element in Taylor's series for asin is really just x / 1
    a = x / 1;
    result += a;

    const int iterations = 500;
    for ( int k = 1; k <= iterations; k++ )
    {
        a *= ( pow( 2 * k - 1, 2 ) * pow( x, 2 ) ) / ( 2 * k * ( 2 * k + 1 ) );
        result += a;

        if ( k == iterations || k >= iterations - 1 )
        {
            printf( "a%d = %.30Le      S%d = %.30Lf\n", k, a, k, result );
        }
    }

    return result;
}

int main()
{
    double x = 0;
    printf( "Please input x in range [-1, 1]:\n" );
    scanf( "%lf", &x );
    printf( "\n" );

    const long double asinSystem = asin( x );
    printf( "System calculated value of asin( %lf ): %.30Lf\n\n", x, asinSystem );

    const long double asinCustom = myAsin( x );
    printf( "Library calculated value of asin( %lf ): %.30Lf\n\n", x, asinCustom );

    printf( "Comparison:\n" );
    printf( "System : % .30Lf\n", asinSystem );
    printf( "Library: % .30Lf\n", asinCustom );
    printf( "Delta  : % .30Lf\n\n", asinSystem - asinCustom );

    printf( "               500                             \n"
            "               ===                  (2 . k + 1)\n"
            "               \\        (2 . k)! . x           \n"
            "sin(%*.2f) =    /     = ------------------------\n"
            "               ===      k       2              \n"
            "              k = 0    4  . (k!)  . (2 . k + 1)\n\n", 2, x );


    printf( "                                 2    2    \n"
            "                      (2 . k - 1)  . x     \n"
            "recurrence relation: -------------------   \n"
            "                     2 . k . (2 . k + 1)   \n" );

    return 0;
}
