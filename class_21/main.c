#include <math.h>
#include <stdio.h>

float input( const char* prompt )
{
    float value = 0;
    fprintf( stderr, prompt );
    scanf( "%f", &value );
    return value;
}

enum Method
{
    Method_Step = 0,
    Method_Trapezoid,
    Method_Simpsons
};

float asinIntegralUsingSteps( float lowerRange, float step, float stepCount )
{
    float integralValue = 0;

    for ( int i = 0; i < stepCount; i++ )
    {
        const float a = lowerRange + i * step;

        // Step displacement is a form of optimization
        integralValue += step * asin( a + step / 2 );
    }

    return integralValue;
}

float asinIntegralUsingSimpsonsRule( float lowerRange, float step, float stepCount )
{
    float integralValue = 0;

    // We have to do one iteration less due to the algorithm requiring one value forward
    for ( int i = 0; i < stepCount - 1; i++ )
    {
        const float a = lowerRange + step * i;
        const float b = lowerRange + step * ( i + 1 );

        integralValue += asin( a ) + 4 * asin( ( a + b ) / 2 ) + asin( b );
    }

    return integralValue * step / 6;
}

float asinIntegralUsingTrapezoids( float lowerRange, float step, float stepCount )
{
    float integralValue = 0;

    // We have to do one iteration less due to the algorithm requiring one value forward
    for ( int i = 0; i < stepCount - 1; i++ )
    {
        const float a = lowerRange + step * i;
        const float b = lowerRange + step * ( i + 1 );

        const float point = asin( a );
        const float pointNext = asin( b );

        integralValue += ( point + pointNext ) * step / 2;
    }

    return integralValue;
}

float asinIntegral( float lowerRange, float upperRange, float precision, enum Method method )
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

        switch ( method )
        {
            case Method_Step:
            {
                integralValue = asinIntegralUsingSteps( lowerRange, step, stepCount );
            }
            break;
            case Method_Trapezoid:
            {
                integralValue = asinIntegralUsingTrapezoids( lowerRange, step, stepCount );
            }
            break;
            case Method_Simpsons:
            {
                integralValue = asinIntegralUsingSimpsonsRule( lowerRange, step, stepCount );
            }
            break;
            default:
                return -1;
                break;
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

    const float integralUsingSteps = asinIntegral( a, b, precision, Method_Step );
    const float integralUsingTrapezoids = asinIntegral( a, b, precision, Method_Trapezoid );
    const float integralUsingSimpsonsRule = asinIntegral( a, b, precision, Method_Simpsons );

    printf( "asin(x) integral value in range [ %.5f : %.5f ] using step function method: %.5f\n", a, b, integralUsingSteps );
    printf( "asin(x) integral value in range [ %.5f : %.5f ] using trapezoidal rule: %.5f\n", a, b, integralUsingTrapezoids );
    printf( "asin(x) integral value in range [ %.5f : %.5f ] using Simpson's rule: %.5f\n", a, b, integralUsingSimpsonsRule );

    return 0;
}