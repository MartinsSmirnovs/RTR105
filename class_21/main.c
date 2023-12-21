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

float asinIntegralUsingSimpsonsRule( float lowerRange, float upperRange, float precision )
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
        // We have to do one iteration less due to the algorithm requiring one value forward
        for ( int i = 0; i < stepCount - 1; i++ )
        {
            integralValue += asin( lowerRange + step * i ) + 4 * asin( lowerRange + step * i + step / 2 ) + asin( lowerRange + step * ( i + 1 ) );
        }

        integralValue *= step / 6;
    }
    while ( fabs( integralValue - integralValuePrevious ) > precision );

    return integralValue;
}


float asinIntegralUsingTrapezoids( float lowerRange, float upperRange, float precision )
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

        // We have to do one iteration less due to the algorithm requiring one value forward
        for ( int i = 0; i < stepCount - 1; i++ )
        {
            const float point = asin( lowerRange + i * step );
            const float pointNext = asin( lowerRange + ( i + 1 ) * step );

            integralValue += ( point + pointNext ) * step / 2;
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

    const float integralUsingSteps = asinIntegralUsingSteps( a, b, precision );
    const float integralUsingTrapezoids = asinIntegralUsingTrapezoids( a, b, precision );
    const float integralUsingSimpsonsRule = asinIntegralUsingSimpsonsRule( a, b, precision );

    printf( "asin(x) integral value in range [%.2f:%.2f] using step function method: %.2f\n", a, b, integralUsingSteps );
    printf( "asin(x) integral value in range [%.2f:%.2f] using trapezoidal rule: %.2f\n", a, b, integralUsingTrapezoids );
    printf( "asin(x) integral value in range [%.2f:%.2f] using Simpson's rule: %.2f\n", a, b, integralUsingSimpsonsRule );

    return 0;
}