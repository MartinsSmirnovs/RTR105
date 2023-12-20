#include <math.h>
#include <stdio.h>

float input( const char* prompt )
{
    float value = 0;
    fprintf( stderr, prompt );
    scanf( "%f", &value );
    return value;
}

float asinIntegralUsingSteps( float lowerRange, float upperRange, float precision )
{
    float integralValue = 0;
    float integralValuePrevious = 0;
    int stepCount = 1;

    do
    {
        stepCount *= 2;

        const float step = ( lowerRange - upperRange ) / stepCount;

        integralValuePrevious = integralValue;

        integralValue = 0;
        for ( int i = 0; i < stepCount; i++ )
        {
            // Step displacement is a form of optimization
            const float stepDisplacement = step * 0.5;

            integralValue += step * asin( lowerRange + i * step + stepDisplacement );
        }
    }
    while ( fabs( integralValue - integralValuePrevious ) > precision );

    return integralValue;
}

int main()
{
    const float a = input( "Please input lower range value a in range[-1:1]:\n" );
    const float b = input( "Please input upper range value b in range[a:1]:\n" );
    const float precision = input( "Please input precision value:\n" );

    const float integral = asinIntegralUsingSteps( a, b, precision );

    printf( "Result: %.2f\n", integral );

    return 0;
}