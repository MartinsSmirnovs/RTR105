#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float input( const char* prompt )
{
    float value = 0;
    fprintf( stderr, prompt );
    scanf( "%f", &value );
    return value;
}

int main()
{
    const float a = input( "Please input lower range value a in range[-1:1]:\n" );
    const float b = input( "Please input upper range value b in range[a:1]:\n" );
    const float delta = input( "Please input precision value delta:\n" );

    const int S_Data = ( ( fabs( a ) + fabs( b ) ) / delta );
    float* data = malloc( S_Data * sizeof( float ) );

    fprintf( stderr, "\tx\t\tsin(x)\t\tsin\'(x)\t\tsin\''(x)\n" );

    float x = a;
    for ( int i = 0; i < S_Data; i++ )
    {
        data[ i ] = asin( x );
        x += delta;
    }

    x = a;
    // Since we need two next elements to be present in data list, we cannot continue
    // until the very last element in list
    for ( int i = 0; i < S_Data - 2; i++ )
    {
        const float asinX = data[ i ];
        const float nextAsinX = data[ i + 1 ];
        const float nextAfterAsinX = data[ i + 2 ];

        const float deltaAsin = nextAsinX - asinX;

        const float derivative = deltaAsin / delta;

        const float deltaAsinPrim = nextAfterAsinX - nextAsinX - deltaAsin;

        const float derivative2 = deltaAsinPrim / delta;

        printf( "%10.2f\t%10.2f\t%10.2f\t%10.2f\n", x, asinX, derivative, derivative2 );

        x += delta;
    }

    free( data );

    return 0;
}