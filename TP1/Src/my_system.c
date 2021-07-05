/*
 * my_system.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include <stdio.h>
#include "../Heathers/my_system.h"

void sys_pause( void )
{
	printf( SYS_PAUSE );
	getchar();
}
