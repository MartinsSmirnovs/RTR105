#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input( const char* prompt, char buffer[], int size )
{
    fprintf( stderr, prompt );
    fgets( buffer, size, stdin );

    const int stringLength = strnlen( buffer, size ) - 1; // The last character is newline
    buffer[ stringLength ] = 0; // Remove the appended newline

    return stringLength;
}

void swap( char* left, char* right )
{
    const char buffer = *left;

    *left = *right;
    *right = buffer;
}

void sort( char buffer[], int size )
{
    for ( int i = 0; i < size - 1; i++ )
    {
        bool swapped = false;
        for ( int j = 0; j < size - i - 1; j++ )
        {
            if ( buffer[ j ] > buffer[ j + 1 ] )
            {
                swap( &buffer[ j ], &buffer[ j + 1 ] );
                swapped = true;
            }
        }

        // If we did not swap, then we have finished sorting
        if ( !swapped )
        {
            return;
        }
    }
}

// Allocates memory for new filtered string
// Deallocation is a responsibility of a caller
// The buffer must be sorted beforehand
char* filterNonLetters( const char buffer[], int size )
{
    int newBufferSize = 0;
    for ( int i = 0; i < size; i++ )
    {
        const char symbol = buffer[ i ];
        if ( symbol >= 'A' & symbol <= 'Z' || symbol >= 'a' && symbol <= 'z' )
        {
            newBufferSize++;
        }
    }

    newBufferSize++; // For zero terminator
    char* filteredBuffer = (char*)malloc( newBufferSize );
    memset( filteredBuffer, 0, newBufferSize );

    int counter = 0;
    for ( int i = 0; i < size; i++ )
    {
        const char symbol = buffer[ i ];
        if ( symbol >= 'A' & symbol <= 'Z' || symbol >= 'a' && symbol <= 'z' )
        {
            filteredBuffer[ counter ] = symbol;
            counter++;
        }
    }

    return filteredBuffer;
}

int main()
{
    // Arbitrary large buffer of data
    char data[ 250 ];
    memset( data, 0, sizeof( data ) );

    const int size = input( "Please input a sentence:\n", data, sizeof( data ) );

    fprintf( stderr, "Median symbol in the sentence is: %c\n", data[ size / 2 ] );

    sort( data, size );
    char* filteredData = filterNonLetters( data, size );
    const int filteredDataSize = strlen( filteredData );

    fprintf( stderr, "Min letter in the sentence: %c\n", filteredData[ 0 ] );
    fprintf( stderr, "Max letter in the sentence: %c\n", filteredData[ filteredDataSize - 1 ] );

    int sum = 0;
    for ( int i = 0; i < filteredDataSize; i++ )
    {
        sum += filteredData[ i ];
    }
    fprintf( stderr, "Avarage letter in the sentence is: %c\n", sum / filteredDataSize );

    int occurrenceTable[ 'z' - 'A' ];
    const int S_OccurrenceTable = sizeof( occurrenceTable ) / sizeof( occurrenceTable[ 0 ] );
    memset( occurrenceTable, 0, sizeof( occurrenceTable ) );

    for ( int i = 0; i < filteredDataSize; i++ )
    {
        occurrenceTable[ filteredData[ i ] - 'A' ]++;
    }

    char mostCommonChar = 0;
    char occurrences = 0;
    for ( char i = 0; i < S_OccurrenceTable; i++ )
    {
        if ( occurrenceTable[ i ] > occurrences )
        {
            mostCommonChar = i + 'A';
            occurrences = occurrenceTable[ i ];
        }
    }

    fprintf( stderr, "Most common letter in the sentence: %c\n", mostCommonChar );

    for ( int i = 0; i < filteredDataSize; i++ )
    {
        printf( "%3c ", filteredData[ i ] );
    }
    printf( "\n" );

    for ( int i = 0; i < filteredDataSize; i++ )
    {
        printf( "%3d ", filteredData[ i ] );
    }
    printf( "\n" );

    free( filteredData );

    return 0;
}
