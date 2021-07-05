
#include <stdio_ext.h>
#include "../Heathers/aux_main.h"
#include "../Heathers/ArrayEmployees.h"
#include "../Heathers/steart.h"
#include "../Heathers/my_system.h"

int main()
{
	int returnAux = -1;
    Employee empList[MAX_EMP];
    if( initEmployees( empList, MAX_EMP ) == 0 )
    {
    	returnAux = main_menu( empList, MAX_EMP );
    }
    if( returnAux != 0 )
    {
    	progHeader( TITLE );
    	subHeader( SUB_TITLE_ERROR );
    }
    if( returnAux == -1 )
    {
    	printf( MAIN_ERROR_MALFUNCTION_EXIT );
    	sys_pause();
    }
    if( returnAux == -2 )
    {
    	printf( MAIN_ERROR_MISUSE_EXIT );
    	sys_pause();
    }
    return returnAux;
}
