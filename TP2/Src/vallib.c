/*
 * values_interpretation.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vallib.h>

int val_isAmongInts( int value, int* values, int valuesLength )
{
	int returnAux = -1;
	if( values != NULL )
	{
		for( int i = 0; i < valuesLength; i++)
		{
			if( value == values[i] )
			{
				returnAux = 1;
				break;
			}
			else
			{
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

int val_isAmongChars( char value, char* values, int valuesLength )
{
	int returnAux = -1;
	if( values != NULL )
	{
		if( ( value > 64 || value < 90 )
			&& ( values[0] > 96 || values[0] < 123 ) )
		{
			value = tolower( value );
		}
		for( int i = 0; i < valuesLength; i++)
		{
			if( value == values[i] )
			{
				returnAux = 1;
				break;
			}
			else
			{
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

int val_isAmongFloats( float value, float* values, int valuesLength )
{
	int returnAux = -1;
	if( values != NULL )
	{
		for( int i = 0; i < valuesLength; i++)
		{
			if( value == values[i] )
			{
				returnAux = 1;
				break;
			}
			else
			{
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

int val_stringHasAny( char* cString, int cStringLen, char* values,
					int valuesLength )
{
	int returnAux = -1;
	if( cString != NULL && values != NULL && cStringLen > 1 && valuesLength > 1 )
	{
		for( int i = 0; i < cStringLen; i++ )
		{
			if( val_isAmongChars( cString[i], values, valuesLength) )
			{
				returnAux = 1;
				break;
			}
		}
		if ( returnAux != 1 )
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

int val_swap( void* valueA, void* valueB )
{
	int returnAux = -1;
	void* auxValue;
	if( valueA != NULL && valueB != NULL )
	{
		auxValue = valueA;
		valueA = valueB;
		valueB = auxValue;
		returnAux = 0;
	}
	return returnAux;
}

int val_strLen( char* string )
{
	int returnAux = 0;
	int i = 0;
	if( string != NULL )
	{
		do
		{
			i++;
		}while( string[i] != '\0' );
		returnAux = i;
	}
	return returnAux;
}

int val_strCpy( char* from, char* to, int toLen )
{
	int returnAux = -1;
	int end = 0;
	if( from != NULL && to != NULL )
	{
		for( int i = 0; i < toLen; i++ )
		{
			if( end )
			{
				to[i] = '\0';
			}
			else
			{
				to[i] = from[i];
			}

			if( from[i] == '\0' || i == toLen - 2 )
			{
				end = 1;
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int val_strCmp( char* aString, char* bString, int cmpLimit )
{
	int returnAux = 0;
	if( aString != NULL && bString != NULL && cmpLimit > 0 )
	{
		for( int i = 0; i < cmpLimit; i++ )
		{
			if( aString[i] > bString[i] )
			{
				returnAux = -bString[i];
			}
			if( aString[i] > bString[i] )
			{
				returnAux = +bString[i];
				break;
			}
		}
	}
	return returnAux;
}
