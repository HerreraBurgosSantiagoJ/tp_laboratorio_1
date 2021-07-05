/*
 * inputLib.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#include <stdio_ext.h>
#include "../Heathers/input_lib.h"
#include "../Heathers/values_interpretation.h"

int inp_getInt( int* number, char* mesage, int trys )
{
	int returnAux = -1;
	int rigthRead = -1;
	if( number != NULL && mesage != NULL && trys > 0 )
	{
		do
		{
			if ( rigthRead != -1 )
			{
				printf(INT_INPUT_ERROR);
			}
			printf("%s", mesage);
			rigthRead = scanf("%d", number);
			__fpurge(stdin);
			trys--;
			if ( rigthRead )
			{
				returnAux = 0;
			}
		}while( rigthRead != 1 && trys != 0 );
	}
	return returnAux;
}

int inp_getIntConcrete( int* number, char* mesage, int trys , int optLength, int* options )
{
	int returnAux = -1;
	int firstLoop = 1;
	if( number != NULL && mesage != NULL && trys > 0 && optLength > 1 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getInt( number, mesage, trys ) == 0
				&& val_isAmongInts( *number, options, optLength ) )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}

int inp_getIntAvoid( int* number, char* mesage, int trys , int ignoredLength, int* ignored )
{
	int returnAux = -1;
	int firstLoop = 1;
	if( number != NULL && mesage != NULL && trys > 0 && ignoredLength > 1 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getInt( number, mesage, trys ) == 0
				&& val_isAmongInts( *number, ignored, ignoredLength ) == 0 )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}

int inp_getIntRange( int* number, char* mesage, int trys , int min, int max )
{
	int returnAux = -1;
	int firstLoop = 1;
	if( number != NULL && mesage != NULL && trys > 0 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getInt( number, mesage, trys ) == 0
				&& *number >= min && *number <= max )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}

int inp_getChar( char* character, char* mesage )
{
	int returnAux = -1;
	if( character != NULL && mesage != NULL )
	{
		printf("%s", mesage);
		scanf("%c", character);
		__fpurge(stdin);
		returnAux = 0;
	}
	return returnAux;
}

int inp_getCharConcrete( char* character, char* mesage, int trys , int optLength, char* options )
{
	int returnAux = -1;
	int firstLoop = 1;
	if( character != NULL && mesage != NULL && trys > 0 && optLength > 1 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getChar( character, mesage ) == 0
				&& val_isAmongChars( *character, options, optLength ) )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}

int inp_getcharAvoid( char* character, char* mesage, int trys , int ignoredLength, char* ignored )
{
	int returnAux = -1;
	int firstLoop = 1;
	if( character != NULL && mesage != NULL && trys > 0 && ignoredLength > 1 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getChar( character, mesage ) == 0
				&& val_isAmongChars( *character, ignored, ignoredLength ) == 0 )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}

int inp_getString( char* cString, char* mesage, int len)
{
	int returnAux = -1;
	char previousChar = ' ';
	if( cString != NULL && mesage != NULL )
	{
		printf("%s", mesage);
		fgets( cString, len, stdin );
		__fpurge(stdin);
		for( int i = 0; i < len; i++ )
		{
		    if( cString[i] == '\n' )
		    {
		        cString[i] = '\0';
		    }
		    if( previousChar == '\0' )
		    {
		        cString[i] = '\0';
		    }
		    previousChar = cString[i];
		}
		returnAux = 0;
	}
	return returnAux;
}

int inp_getName( char* name, char* mesage, int len, int trys )
{
	int returnAux = -1;
	int firstLoop = 1;
	if( name != NULL && mesage != NULL && trys > 0 && len > 1 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getString( name, mesage, len ) == 0
				&& val_stringHasAny( name, len, NAME_IGNORED_VALUES, NAME_IGNORED_VALUES_LEN ) == 0 )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}

int inp_getMail( char* mail, char* mesage, int len, int trys)
{
	int returnAux = -1;
	int firstLoop = 1;
	if( mail != NULL && mesage != NULL && trys > 0 && len > 1 )
	{
		do
		{
			if ( firstLoop == 0 )
			{
				printf( UNACCEPTABLE_VALUE_ERROR );
			}
			if ( inp_getString( mail, mesage, len ) == 0
				&& val_stringHasAny( mail, len, MAIL_IGNORED_VALUES, MAIL_IGNORED_VALUES_LEN ) == 0 )
			{
				returnAux = 0;
			}
			firstLoop = 0;
			trys--;
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
