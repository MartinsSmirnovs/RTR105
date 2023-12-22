#include <math.h>
#include <stdio.h>

long double input( const char* prompt )
{
    long double value = 0;
    fprintf( stderr, prompt );
    scanf( "%Lf", &value );
    return value;
}

enum Method
{
    Method_Step = 0,
    Method_Trapezoid,
    Method_Simpsons
};

long double asinIntegralUsingSteps( long double lowerRange, long double step, long double stepCount )
{
    long double integralValue = 0;

    for ( long int i = 0; i < stepCount; i++ )
    {
        const long double a = lowerRange + i * step;

        // Step displacement is a form of optimization
        integralValue += step * asin( a + step / 2 );
    }

    return integralValue;
}

long double asinIntegralUsingSimpsonsRule( long double lowerRange, long double step, long double stepCount )
{
    long double integralValue = 0;

    // We have to do one iteration less due to the algorithm requiring one value forward
    for ( long int i = 0; i < stepCount - 1; i++ )
    {
        const long double a = lowerRange + step * i;
        const long double b = lowerRange + step * ( i + 1 );

        integralValue += asin( a ) + 4 * asin( ( a + b ) / 2 ) + asin( b );
    }

    return integralValue * step / 6;
}

long double asinIntegralUsingTrapezoids( long double lowerRange, long double step, long double stepCount )
{
    long double integralValue = 0;

    // We have to do one iteration less due to the algorithm requiring one value forward
    for ( long int i = 0; i < stepCount - 1; i++ )
    {
        const long double a = lowerRange + step * i;
        const long double b = lowerRange + step * ( i + 1 );

        const long double point = asin( a );
        const long double pointNext = asin( b );

        integralValue += ( point + pointNext ) * step / 2;
    }

    return integralValue;
}

long double asinIntegral( long double lowerRange, long double upperRange, long double precision, enum Method method )
{
    long double integralValue = 0;
    long double integralValuePrevious = 0;
    long int stepCount = 1;

    do
    {
        stepCount *= 2;

        const long double step = ( lowerRange - upperRange ) / stepCount;

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


    // fprintf( stderr, "Step count: %ld\n", stepCount );

    return integralValue;
}

int main()
{
    const long double a = input( "Please input lower range value a in range[-1:1]:\n" );
    const long double b = input( "Please input upper range value b in range[a:1]:\n" );
    const long double precision = input( "Please input precision value:\n" );

    const long double integralUsingSteps = asinIntegral( a, b, precision, Method_Step );
    const long double integralUsingTrapezoids = asinIntegral( a, b, precision, Method_Trapezoid );
    const long double integralUsingSimpsonsRule = asinIntegral( a, b, precision, Method_Simpsons );

    printf( "asin(x) integral value in range [ %.5Lf : %.5Lf ] using step function method: %.30Lf\n", a, b, integralUsingSteps );
    printf( "asin(x) integral value in range [ %.5Lf : %.5Lf ] using trapezoidal rule:     %.30Lf\n", a, b, integralUsingTrapezoids );
    printf( "asin(x) integral value in range [ %.5Lf : %.5Lf ] using Simpson's rule:       %.30Lf\n", a, b, integralUsingSimpsonsRule );

    return 0;
}