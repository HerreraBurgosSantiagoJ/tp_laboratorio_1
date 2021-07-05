/*
 * errors.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include "../Heathers/errors.h"

int error_id( int divError,	int facAError, int facBError )
{
	/*
	 Errors IDs:
	 -2 = DIVICION_ERROR (only)
	 -3 = FACTORIAL_ERROR (only number A)
	 -4 = FACTORIAL_ERROR (only number B)
	 -5 = FACTORIAL_ERROR (both numbers)
	 -6 = DIVICION_ERROR && FACTORIAL_ERROR (only number A)
	*/
	int error;
	if( divError == 1 && facAError == 1)
	{
		error = -6;
	}
	else if( facAError == 1 && facBError == 1 )
	{
		error = -5;
	}
	else if( facAError == 0 && facBError == 1 )
	{
		error = -4;
	}
	else if( facAError == 1 && facBError == 0 )
	{
		error = -3;
	}
	else if( divError == 1 )
	{
		error = -2;
	}
	else
	{
		error = 0;
	}
	return error;
}
