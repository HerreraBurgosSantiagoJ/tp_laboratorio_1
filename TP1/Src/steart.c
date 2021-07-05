#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void progHeader( char* title )
{
    int length = strlen( title );
    int lineLength = 82;
    int spaceLengh = (lineLength - length) / 2;
    int i;
    system( "clear" );
    for ( i = 0; i < lineLength; i++ )
    {
        printf( "=" );
    }
    printf( "\n" );
    for ( i = 0; i < spaceLengh; i++ )
    {
        printf( " " );
    }
    printf( "%s", title );
    for ( i = 0 ; i < spaceLengh; i++ )
    {
        printf( " " );
    }
    printf( "\n" );
    for ( i = 0; i < lineLength; i++ )
    {
        printf( "=" );
    }
}

void subHeader( char* sub )
{
    int length = strlen( sub );
    printf( "\n%s\n", sub );
    for ( int i = 0 ; i < length; i++ )
    {
        printf("-");
    }
    printf("\n");
}
