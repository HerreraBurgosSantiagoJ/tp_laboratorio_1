/*
 * calculate.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include <stdio.h>
#include "../Heathers/calculate.h"

long long int cal_add( int numberA, int numberB )
{
	long long int sum;
	sum = numberA + numberB;
	return sum;
}

long long int cal_subtract(int  numberA, int numberB )
{
	long long int substraction;
	substraction = numberA - numberB;
	return substraction;
}

long long int cal_multiply(int factorA, int factorB )
{
	long long int product;
	product = factorA * factorB;
	return product;
}

int cal_divide(int dividend, int divider, float *quotient )
{
	int returnAux = -1;
	if( divider != 0 )
	{
		*quotient = (float)dividend / (float) divider;
		returnAux = 0;
	}
	return returnAux;
}

int cal_factorial( int number, long long int* factorial )
{
	int returnAux = -1;
	if( number >= 0 )
	{
		*factorial = 1;
		for( ; number >= 2; number-- )
		{
			*factorial *= number;
		}
		returnAux = 0;
	}
	return returnAux;
}

int cal_greatFactorial( int number, unsigned char* factorial, int* size )
{
	int returnAux = -1;
	int carried;
	*size = 0;
	if( factorial != NULL )
	{
		factorial[0] = 1;
		for( ; number >= 2; number-- )
		{
			carried = 0;
			for( int i = 0; i <= *size; i++ )
			{
				carried = ( factorial[i] * number ) + carried;
				factorial[i] = carried % 10;
				carried = carried / 10;
			}
			while( carried > 0 )
			{
				*size += 1;
				factorial[*size] = carried % 10;
				carried = carried / 10;
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int cal_aux_GreatFac( unsigned char* factorial, int size )
{
	int returnAux = -1;
	if ( factorial != NULL )
	{
		for( ; size >= 0; size-- )
		{
			printf("%u", factorial[size] );
		}
	}
	return returnAux;
}
