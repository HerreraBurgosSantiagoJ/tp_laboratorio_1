/*
 * inputLib.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#include <stdio_ext.h>
#include "vallib.h"
#include <ctype.h>
#include "input_lib.h"

//Measure Tape===================================================================
int inp_getInt( int* number, char* mesage, int trys, char* errorNotANumber )
{
	int returnAux = -1;
	int rigthRead = -1;
	if( number != NULL && mesage != NULL && trys > 0 )
	{
		returnAux = -2;
		do
		{
			printf("%s", mesage);
			rigthRead = scanf("%d", number);
			__fpurge(stdin);
			trys--;
			if ( rigthRead )
			{
				returnAux = 0;
			}
			else
			{
				printf( errorNotANumber, trys );
			}
		}while( rigthRead != 1 && trys != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getIntConcrete( int* number, char* mesage, int trys , int optLength,
						int* options, char* valueError, char* errorNotANumber )
{
	int returnAux = -1;
	if( number != NULL && mesage != NULL && trys > 0 && optLength > 1 )
	{
		do
		{
			returnAux = inp_getInt( number, mesage, 1, " " );
			trys--;
			if( val_isAmongInts( *number, options, optLength ) == 0
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else if( returnAux != 0 )
			{
				printf( errorNotANumber, trys );
			}
		}while( trys != 0 && returnAux != 0 );
	}
 	return returnAux;
}
//Measure Tape===================================================================
int inp_getIntAvoid( int* number, char* mesage, int trys , int ignoredLength,
					int* ignored, char* valueError, char* errorNotANumber )
{
	int returnAux = -1;
	if( number != NULL && mesage != NULL && trys > 0 && ignoredLength > 1 )
	{
		do
		{
			returnAux = inp_getInt( number, mesage, 1, " " );
			trys--;
			if( val_isAmongInts( *number, ignored, ignoredLength )
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else if( returnAux != 0 )
			{
				printf( errorNotANumber, trys );
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getIntRange( int* number, char* mesage, int trys , int min, int max,
					char* valueError, char* errorNotANumber)
{
	int returnAux = -1;
	if( number != NULL && mesage != NULL && trys > 0 )
	{
		do
		{
			returnAux = inp_getInt( number, mesage, 1, " " );
			trys--;
			if ( ( *number < min || *number > max ) && returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else if( returnAux != 0 )
			{
				printf( errorNotANumber, trys );
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getFloat( float* number, char* mesage, int trys, char* errorNotANumber )
{
	int returnAux = -1; //Malfunction error
	int rigthRead = -1;
	if( number != NULL && mesage != NULL && trys > 0 )
	{
		returnAux = -2; //User Error
		do
		{
			printf( "%s", mesage);
			rigthRead = scanf( "%f", number );
			__fpurge(stdin);
			trys--;
			if( rigthRead == 0 )
			{
				printf( errorNotANumber, trys );
			}
			else
			{
				returnAux = 0;
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getFloatConcrete( float* number, char* mesage, int trys , int optLength,
						float* options, char* valueError, char* errorNotANumber )
{
	int returnAux = -1;
	if( number != NULL && mesage != NULL && trys > 0 && optLength > 1 )
	{
		do
		{
			returnAux = inp_getFloat( number, mesage, 1, " " );
			trys--;
			if( val_isAmongFloats( *number, options, optLength ) == 0
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else if( returnAux != 0 )
			{
				printf( errorNotANumber, trys );
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getFloatAvoid( float* number, char* mesage, int trys , int ignoredLength,
						float* ignored, char* valueError, char* errorNotANumber )
{
	int returnAux = -1;
	if( number != NULL && mesage != NULL && trys > 0 && ignoredLength > 1 )
	{
		do
		{
			returnAux = inp_getFloat( number, mesage, 1, " " );
			trys--;
			if( val_isAmongFloats( *number, ignored, ignoredLength ) == 1
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else if( returnAux != 0 )
			{
				printf( errorNotANumber, trys );
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getFloatRange( float* number, char* mesage, int trys , float min,
						float max, char* valueError, char* errorNotANumber )
{
	int returnAux = -1;
	if( number != NULL && mesage != NULL && trys > 0 )
	{
		do
		{
			returnAux = inp_getFloat( number, mesage, 1, " " );
			if ( ( *number <= min && *number >= max ) && returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else if( returnAux != 0 )
			{
				printf( errorNotANumber, trys );
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
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
//Measure Tape===================================================================
int inp_getCharConcrete( char* character, char* mesage, int trys , int optLength,
						char* options, char* valueError )
{
	int returnAux = -1;
	if( character != NULL && mesage != NULL && trys > 0 && optLength > 1 )
	{
		do
		{
			returnAux = inp_getChar( character, mesage );
			if( *character > 'Z' )
			{
				*character = toupper(*character);
			}
			trys--;
			if( val_isAmongChars( *character, options, optLength )
				&& returnAux == 0 )
			{
				returnAux = 0;
			}
			else if( returnAux != 0 )
			{
				printf( valueError, trys );
			}

		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getcharAvoid( char* character, char* mesage, int trys , int ignoredLength
					, char* ignored, char* valueError )
{
	int returnAux = -1;
	if( character != NULL && mesage != NULL && trys > 0 && ignoredLength > 1 )
	{
		do
		{
			returnAux = inp_getChar( character, mesage );
			trys--;
			if( val_isAmongChars( *character, ignored, ignoredLength ) == 1
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getString( char* cString, char* mesage, int stringLength )
{
	int returnAux = -1;
	char previousChar = ' ';
	if( cString != NULL && mesage != NULL )
	{
		printf("%s", mesage);
		fgets( cString, stringLength -1, stdin );
		__fpurge(stdin);
		for( int i = 0; i < stringLength; i++ )
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
//Measure Tape===================================================================
int inp_getName( char* name, char* mesage, int len, int trys, char* valueError )
{
	int returnAux = -1;
	if( name != NULL && mesage != NULL && trys > 0 && len > 1 )
	{
		do
		{
			returnAux = inp_getString( name, mesage, len );
			trys--;
			if ( val_stringHasAny( name, len, NAME_IGNORED_VALUES,
									NAME_IGNORED_VALUES_LEN ) == 1
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}

		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================
int inp_getMail( char* mail, char* mesage, int len, int trys, char* valueError )
{
	int returnAux = -1;
	if( mail != NULL && mesage != NULL && trys > 0 && len > 1 )
	{
		do
		{
			returnAux = inp_getString( mail, mesage, len );
			trys--;
			if ( val_stringHasAny( mail, len, MAIL_IGNORED_VALUES,
									MAIL_IGNORED_VALUES_LEN ) == 1
				&& returnAux == 0 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
		}while( trys != 0 && returnAux != 0 );
	}
	return returnAux;
}
//Measure Tape===================================================================

int inp_getDate( sDate* date, char* mesage, int trys, int lastYear, char* valueError, char* errorNotADate)
{
	int returnAux = -1;
	int rigthRead = 0;
	if( date != NULL && mesage != NULL && trys > 0 )
	{
		do
		{
			printf( "%s" ,mesage );
			rigthRead = scanf("%02d/%02d/%04d", &date->day, &date->month, &date->year);
			trys--;
			if( (date->day < 1 || date->day > 31 ||
				date->month < 1 || date->month > 12 ||
				date->year < lastYear ) )
			{
				printf( errorNotADate, trys );
				returnAux = -2;
			}
			else if( rigthRead != 3 )
			{
				printf( valueError, trys );
				returnAux = -2;
			}
			else
			{
				returnAux = 0;
			}
		}while(trys != 0 && returnAux != 0);
	}
	return returnAux;
}
