#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	Employee* pAuxEmp;
	char buffer [4][128];
	int line = 1;
	if( pFile != NULL && pArrayListEmployee != NULL )
	{
		do
		{
			fscanf( pFile, "%s[^,]", buffer[0] );
			fscanf( pFile, "%s[^,]", buffer[1] );
			fscanf( pFile, "%s[^,]", buffer[2] );
			fscanf( pFile, "%s", buffer[3] );
			if( line > 1 )
			{
				pAuxEmp = employee_new( buffer[0], buffer[1], buffer[2], buffer[3] );
				returnAux = ll_add( pArrayListEmployee, pAuxEmp );
			}
			line++;
		}while( ftell(pFile) != EOF && pAuxEmp != NULL && returnAux != -1 );
	}
    return returnAux;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	Employee* pAuxEmp;
	if( pFile != NULL && pArrayListEmployee != NULL )
	{
		do
		{
			pAuxEmp = employee_newEmpty();
			if( pAuxEmp != NULL )
			{
				returnAux = fread( pAuxEmp, sizeof(Employee), 1, pFile);
			}
		}while( ftell(pFile) != EOF && returnAux == 1 );
		if( returnAux != 1 )
		{
			returnAux = -1;
		}
	}
    return returnAux;
}
