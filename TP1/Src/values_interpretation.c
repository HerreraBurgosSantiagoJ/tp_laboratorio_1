/*
 * values_interpretation.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include <stdio.h>
#include "../Heathers/values_interpretation.h"

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
		if( ( value > 64 || value < 90 ) && ( values[0] > 96 || values[0] < 123 ) )
		{
			value+=32;
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

int val_stringHasAny( char* cString, int cStringLen, char* values, int valuesLength )
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
