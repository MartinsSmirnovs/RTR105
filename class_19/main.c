#include <math.h>
#include <stdio.h>

// MAKE THIS USING ARRAYS

int main()
{
    const float a = -1;
    const float b = 1;
    const float deltaX = 1.e-2;
    float x = a;

    fprintf( stderr, "\tx\t\tsin(x)\t\tsin\'(x)\t\tsin\''(x)\n" );

    x = a;
    while ( x < b )
    {
        const float asinX = asin( x );

        const float deltaAsin = asin( x + deltaX ) - asin( x );

        const float derivative = deltaAsin / deltaX;

        const float deltaAsinPrim = asin( x + deltaX + deltaX ) - asin( x + deltaX ) - deltaAsin;

        const float derivative2 = deltaAsinPrim / deltaX;

        printf( "%10.2f\t%10.2f\t%10.2f\t%10.2f\n", x, asinX, derivative, derivative2 );

        x += deltaX;
    }

    return 0;
}