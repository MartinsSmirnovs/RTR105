#undef __STRICT_ANSI__
#include <math.h>
#include <stdio.h>

float input( const char* prompt )
{
    float value = 0;
    printf( prompt );
    scanf( "%f", &value );
    return value;
}

float displacedAsin( float x, float displacement )
{
    return asin( x ) - displacement;
}

int main()
{
    float a = input( "Please input lower range value a in range[-1:1]:\n" );
    float b = input( "Please input upper range value b in range[a:1]:\n" );
    const float c = input( "Please input displacement value c in range[-1.57:1.57]:\n" );
    const float delta = input( "Please input precision value delta:\n" );

    const float initial = displacedAsin( a, c );

    int i = 0;

    if ( displacedAsin( a, c ) * displacedAsin( b, c ) > 0 )
    {
        printf( "There are no roots for asin(x) in range [%.3f;%.3f]\n", a, b );
        return 0;
    }

    float x = 0;
    while ( ( b - a ) > delta )
    {
        i++;
        x = ( a + b ) / 2;
        if ( initial * displacedAsin( x, c ) > 0 )
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }

    printf( "\n" );
    printf( "Iteration count to get desired precision: %d\n", i );
    printf( "The root can be found at x=%.6f, as asin(%.6f)-(%.6f)=%.6f\n", x, x, c, displacedAsin( x, c ) );

    return 0;
}