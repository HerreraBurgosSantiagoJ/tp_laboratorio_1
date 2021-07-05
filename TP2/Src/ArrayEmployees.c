#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../Heathers/ArrayEmployees.h"
#include "../Heathers/vallib.h"

int initEmployees(Employee* list, int len)
{
    int returnAux = -1;
    if ( len > 0 && list != NULL )
    {
        for (int i = 0 ; i < len ; i++)
        {
            list[i].isEmpty = 1;
        }
        returnAux=0;
    }
    return returnAux;
}

int addEmployee(Employee* list, int len, int id, char* name, char* lastName,
				float salary, int sector)
{
    int returnAux = -1;
    if( len > 0 && list != NULL )
    {
        for( int i = 0 ;i < len ;i++ )
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id=id;
                val_strCpy(name, list[i].name, NAME_LENGTH);
                val_strCpy( lastName, list[i].lastName, NAME_LENGTH);
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].isEmpty=0;
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int returnAux = -1;
    if ( len > 0 && list != NULL)
    {
        for ( int i = 0; i < len; i++ )
        {
            if ( list[i].id == id && list[i].isEmpty == 0 )
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

int removeEmployee(Employee* list, int len, int id)
{
    int returnAux = -1;
    if ( len > 0 && list != NULL )
    {
        for ( int i = 0; i < len; i++ )
        {
            if ( list[i].id == id )
            {
                list[i].isEmpty = 1;
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

int emp_swap( Employee* empA, Employee* empB )
{
	int returnAux;
	Employee auxEmp;
	if( empA != NULL && empB != NULL )
	{
		auxEmp = *empA;
		*empA = *empB;
		*empB = auxEmp;
		returnAux = 0;
	}
	return returnAux;
}

int sortEmployees(Employee* list, int len, int order)
{
    int returnAux = -1;
    int strCmpAux;
    if ( len > 0 && list != NULL )
    {
        for ( int i = 0; i < len; i++ )
        {
            for ( int j = i + 1; j < len; j++ )
            {
                if( ( list[i].sector > list[j].sector && order == 1 ) ||
                	( list[i].sector < list[j].sector && order == 0 ) )
                {
                	emp_swap( &list[i], &list[j] );
                }
            }
        }
        for ( int i = 0; i < len; i++ )
        {
        	for ( int j = i + 1; j < len; j++ )
        	{
        		strCmpAux = strncmp( list[i].lastName, list[j].lastName,
        							NAME_LENGTH );
        		if( ( ( strCmpAux > 0 && order == 1 ) ||
        			( strCmpAux < 0 && order == 0 ) ) &&
        			list[i].sector == list[j].sector )
        		{
        			emp_swap( &list[i], &list[j] );
        		}
        	}
        }
        returnAux = 0;
    }
    return returnAux;
}

int printEmployees(Employee* list, int length)
{
    int returnAux = -1;
    int flagFirstLoop = 1;
    for ( int i = 0 ; i < length; i++ )
    {
    	if( flagFirstLoop && list[i].isEmpty == 0 )
    	{
    		printf("\n     ID           Apellido               Nombre              Salario          Sector       \n");
    		printf("-------------------------------------------------------------------------------------------\n");
    		flagFirstLoop = 0;
    	}
        if ( list[i].isEmpty == 0 )
        {
            printf("    %05d   |%19s  |%19s  |%15.2f |        %02d\n",
            		list[i].id, list[i].lastName, list[i].name, list[i].salary,
					list[i].sector);
            printf("-------------------------------------------------------------------------------------------\n");
            returnAux = 0;
        }
    }
    return returnAux;
}

int generateID(Employee* list, int len)
{
    int returnAux = -1;
    if( list != NULL && len > 0 )
    {
    	returnAux = 0;
    	for( int i = 0; i < len; i++ )
    	{
    		if( list[i].isEmpty == 0 && list[i].id > returnAux )
    		{
    			returnAux = list[i].id;
    		}
    	}
    	returnAux++;
    }
    return returnAux;
}

float averageSalary(Employee* list, int len)
{
    float returnAux = -1;
    int empQuantity = 0;
    int flagFirstLoop = 1;
    if( list != NULL && len > 0 )
    {
    	for ( int i = 0 ; i<len ; i++ )
    	{
    		if( flagFirstLoop && list[i].isEmpty == 0 )
    		{
    			returnAux = list[i].salary;
    			empQuantity++;
    			flagFirstLoop = 0;
    		}
    		if( list[i].isEmpty == 0 )
    		{
    			returnAux+=list[i].salary;
    			empQuantity++;
    		}
    	}
    	returnAux = returnAux / (float) empQuantity;
    }
    return returnAux;
}

char empHasSpace(Employee* list, int len)
{
    char returnAux = -1;
    if( list != NULL && len > 0 )
    {
    	for( int i = 0; i < len; i++ )
    	{
    		if( list[i].isEmpty == 1 )
    		{
    			returnAux = 1;
    			break;
    		}
    	}
    	if( returnAux == -1 )
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

int getIdIndex(Employee* list, int len, int id)
{
    int returnAux = -1;
    if( list != NULL && len > 0 && id > 0 )
    {
    	for( int i = 0; i < len; i++ )
    	{
    		if( list[i].isEmpty == 0 && list[i].id == id )
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

int emp_therAreEmployees( Employee* list, int length )
{
	int returnAux = -1;
	if( list != NULL && length > 0 )
	{
		for( int i = 0; i < length; i++ )
		{
			if( list[i].isEmpty == 0 )
			{
				returnAux = 1;
				break;
			}
		}
		if( returnAux == -1 )
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

int emp_findEmpty( Employee* list, int length )
{
	int returnAux = -1;
	if( list != NULL && length > 0 )
	{
		for( int i = 0; i < length; i++ )
		{
			if( list[i].isEmpty == 1 )
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

int emp_findGreaterID( Employee* list, int length )
{
	int returnAux = -1;
	int firstEmployee = 1;
	if( list != NULL && length > 0 )
	{
		returnAux = 0;
		for( int i = 0; i < length; i++ )
		{
			if( ( firstEmployee || returnAux < list[i].id ) &&
				list[i].isEmpty == 0 )
			{
				returnAux = list[i].id;
				firstEmployee = 0;
			}
		}
	}
	return returnAux;
}

int emp_findMinorID( Employee* list, int length )
{
	int returnAux = -1;
	int firstEmployee = 1;
	if( list != NULL && length > 0 )
	{
		for( int i = 0; i < length; i++ )
		{
			if( ( firstEmployee || returnAux > list[i].id ) &&
				list[i].isEmpty == 0 )
			{
				returnAux = list[i].id;
				firstEmployee = 0;
			}
		}
	}
	return returnAux;
}
