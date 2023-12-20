#include <math.h>
#include <stdio.h>

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
    const float precision = input( "Please input precision value delta:\n" );

    float integralValue = 0;
    float integralValuePrevious = 0;
    int stepCount = 1;

    do
    {
        stepCount *= 2;

        const float step = ( b - a ) / stepCount;

        integralValuePrevious = integralValue;

        integralValue = 0;
        for ( int i = 0, integralValue = 0; i < stepCount; i++ )
        {
            integralValue += step * asin( a + i * step );
        }
        printf( "Rectangles: %d\n", stepCount );
        printf( "Intermediate: %.2f\n", integralValue );
    }
    while ( fabs( integralValue - integralValuePrevious ) > precision );

    printf( "Result: %.2f\n", integralValue );

    return 0;
}