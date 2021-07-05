/*
 * aux_main.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include <stdio.h>
#include <stdlib.h>
#include "../Heathers/aux_main.h"
#include "../Heathers/errors.h"
#include "../Heathers/calculate.h"
#include "../Heathers/steart.h"

void main_showMenu( int numberA, int numberB , int numberAReady, int numberBReady )
{
	progHeader( TITLE );
	if( numberAReady )
	{
		printf( MENU_OPT_ONE_B, numberA );
	}
	else
	{
		printf( MENU_OPT_ONE_A );
	}
	if( numberBReady )
	{
		printf( MENU_OPT_TWO_B, numberB );
	}
	else
	{
		printf( MENU_OPT_TWO_A );
	}
	printf( MENU_OPT_THREE );
	printf( MENU_OPT_FOUR );
	printf( MENU_OPT_FIVE );
}

int main_runOperations( int numberA, int numberB, long long int* sum,
						long long int* substraction, long long int* product,
						float* quotient, unsigned char* factorialA,
						unsigned char* factorialB, int* sizeFacA, int* sizeFacB)
{
	int returnAux = -1;
	int divError = 0;
	int facAError = 0;
	int facBError = 0;
	if ( sum != NULL && substraction != NULL && product != NULL &&
		quotient != NULL && factorialA != NULL && factorialB != NULL )
	{
		*sum = cal_add( numberA, numberB );
		*substraction = cal_subtract( numberA, numberB );
		*product = cal_multiply( numberA, numberB );
		if( cal_divide( numberA, numberB, quotient ) != 0 )
		{
			divError = 1;
		}
		if( cal_greatFactorial( numberA, factorialA, sizeFacA ) != 0 )
		{
			facAError = 1;
		}
		if( cal_greatFactorial( numberB, factorialB, sizeFacB ) != 0 )
		{
			facBError = 1;
		}
		returnAux = error_id( divError, facAError, facBError );
	}
	return returnAux;
}

void main_showResults( int numberA, int numberB, long long int sum,
					   long long int substraction, long long int product,
					   float quotient, unsigned char* factorialA,
					   unsigned char* factorialB, int errors, int sizeFacA,
					   int sizeFacB )
{
	progHeader( TITLE );
	subHeader( SUB_TITLE_A );
	printf( ADDITION_RES, numberA, numberB, sum );
	printf( SUBSTRACTION_RES, numberA, numberB, substraction );
	printf( MULTIPLICATION_RES, numberA, numberB, product );
	switch( errors )
	{
		case 0:
			printf( DIVICION_RES, numberA, numberB, quotient );
			printf( FACTORIAL_RES_ONE, numberA );
			cal_aux_GreatFac( factorialA, sizeFacA );
			printf( FACTORIAL_RES_ONE, numberB);
			cal_aux_GreatFac( factorialB, sizeFacB );
			break;
		case -2:
			printf( DIVICION_ERROR );
			printf( FACTORIAL_RES_ONE, numberA );
			cal_aux_GreatFac( factorialA, sizeFacA );
			printf( FACTORIAL_RES_ONE, numberB);
			cal_aux_GreatFac( factorialB, sizeFacB );
			break;
		case -3:
			printf( DIVICION_RES , numberA, numberB, quotient );
			printf( FACTORIAL_ERROR, numberA );
			printf( FACTORIAL_RES_ONE, numberB);
			cal_aux_GreatFac( factorialB, sizeFacB );
			break;
		case -4:
			printf( DIVICION_RES, numberA, numberB, quotient );
			printf( FACTORIAL_RES_ONE, numberA );
			cal_aux_GreatFac( factorialA, sizeFacA );
			printf( FACTORIAL_ERROR, numberB );
			break;
		case -5:
			printf( DIVICION_RES, numberA, numberB, quotient );
			printf( FACTORIAL_ERROR, numberA );
			printf( FACTORIAL_ERROR, numberB );
			break;
		case -6:
			printf( DIVICION_ERROR );
			printf( FACTORIAL_ERROR, numberA );
			printf( FACTORIAL_RES_ONE, numberB );
			cal_aux_GreatFac( factorialB, sizeFacB );
			break;
	}
}
