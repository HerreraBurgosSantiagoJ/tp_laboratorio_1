#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "input_lib.h"
#include "my_system.h"
#include "steart.h"
#include "vallib.h"

int aux_inp_getID( int* id, LinkedList* list, char* mesage, int trys, char* valueError, char* errorNotANumber )
{
	int returnAux = -1;
	int found = 0;
	int listLength;
	Employee* auxEmp;
	if( id != NULL && list != NULL && mesage != NULL && valueError != NULL &&
		errorNotANumber != NULL )
	{
		listLength = ll_len(list);
		do
		{
			returnAux = inp_getInt(id, mesage, 1, "");
			trys--;
			for( int i = 0; i < listLength; i++ )
			{
				auxEmp = (Employee*) ll_get(list, i);
				if( auxEmp->id == *id )
				{
					found = 1;
					returnAux = 0;
					break;
				}
			}
			if( returnAux == 0 && found == 0 )
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

int aux_employee_showAll( LinkedList* this )
{
	int returnAux = -1;
	int len;
	Employee* auxEmp;
	if( this != NULL )
	{
		len = ll_len(this);
		printf("\n ID | Nombre | Horas Trabajadas | Sueldo");
		printf("\n========================================");
		for( int i = 0; i < len; i++ )
		{
			if((auxEmp = ll_get(this, i))!=NULL &&
				employee_show( auxEmp ) != -1 &&
				printf("\n-----------------------------------------"))
			{
				returnAux = 0;
			}
			else
			{
				returnAux = -1;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	FILE* pFile;
	if( path != NULL &&
		pArrayListEmployee != NULL &&
		(pFile = fopen(path,"r")) != NULL )
	{
		returnAux = parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
	}
	return returnAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	FILE* pFile;
	if( path != NULL &&
		pArrayListEmployee != NULL &&
		(pFile = fopen(path,"rb")) != NULL )
	{
		returnAux = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		fclose(pFile);
	}
	return returnAux;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	Employee* pAuxEmp;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int rightData;
	int more;
	int options[2] = {0,1};
	if( pArrayListEmployee != NULL )
	{
		//Loop Init
		do{
			rightData = 0;
			more = 0;

			progHeader("ABM Empleados");
			subHeader("ALTAS");

			if( void_generateID(pArrayListEmployee, employee_getId, &id) == -1 ||
				inp_getName(nombre, "\nIngrese el nombre del empleado: ", 128, MAX_TRYS, "Error! Lo ingresado contiene caracteres no correspondientes con un nombre\n Intentos restantes: %d" ) == -1 ||
				inp_getInt(&horasTrabajadas, "\nIngrese las horas trabajadas por el empleado: ", MAX_TRYS, "Error! Lo ingresado no es un numero.\nIntentos Restantes: %d") == -1 ||
				inp_getInt(&sueldo, "\nIngrese el sueldo del empleado: ", MAX_TRYS, "Error! Lo ingresado no es un numero.\nIntentos Restantes: %d") == -1 )
			{
				break;
			}

			progHeader("ABM Empleados");
			subHeader("ALTA empleados");
			printf("\nLos datos ingresados del empleado de legajo %d son:\n-Nombre: %s\n-Horas Trabajadas: %d\n-Sueldo: %d.", id, nombre, horasTrabajadas, sueldo );
			if( inp_getIntConcrete(&rightData,
									"\nSon estos datos correctos? (Si = 1 / No = 0): ",
									MAX_TRYS, 2, options,
									"Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d",
									"Error! Lo ingresado no es un numero. \nIntentos restantes: %d") == 0
				&& rightData )
			{
				pAuxEmp = employee_newEmpty();
			}


			if( employee_setId(pAuxEmp, id) == -1 ||
				employee_setNombre(pAuxEmp, nombre) == -1 ||
				employee_setHorasTrabajadas(pAuxEmp, horasTrabajadas) == -1 ||
				employee_setSueldo(pAuxEmp, sueldo) == -1 ||
				(returnAux = ll_add(pArrayListEmployee, pAuxEmp)) == -1 )
			{
				break;
			}

			if( inp_getIntConcrete(&more, "\nDesea agregar un nuevo empleado? (Si = 1 / No = 0): ",
									MAX_TRYS, 2, options,
									"Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d",
									"Error! Lo ingresado no es un numero. \nIntentos restantes: %d") == -1 )
			{
				break;
			}

		}while( (rightData == 0 || more == 1) && returnAux == 0 );
	}
	return returnAux;
}

int aux_editMenu( Employee* pAuxEmp, int* more )
{
	int returnAux = -1;
	int options[5] = {1,2,3,4,5};
	int option;
	if( pAuxEmp != NULL && more != NULL )
	{
		do
		{
			printf("\nID: %d\nNombre: %s\nHoras Trabajadas: %d\nSueldo: %d", pAuxEmp->id, pAuxEmp->nombre, pAuxEmp->horasTrabajadas, pAuxEmp->sueldo);
			printf("\n\n1. Modificar Nombre\n2. Modificar Horas Trabajadas\n3. Modificar Sueldo\n4. Modificar Otro empleado\n Menu Principal");

			if( inp_getIntConcrete(&option, "\nOpcion: ", MAX_TRYS, 5, options, "Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d", "Error! Lo ingresado no es un numero. \nIntentos restantes: %d") == -1 )
			{
				break;
			}
			switch( option )
			{
			case 1:
				returnAux = inp_getName(pAuxEmp->nombre, "\nIngrese el nuevo nombre del empleado:", 128, MAX_TRYS, "Error! Lo ingresado contiene caracteres no esperados en un nombre\nIntentos restantes: %d");
				break;
			case 2:
				returnAux = inp_getInt(&pAuxEmp->horasTrabajadas, "\nIngrese las horas trabajadas: ", MAX_TRYS, "Error! Lo ingresado no es un numero.\nIntentos restantes: %d");
				break;
			case 3:
				returnAux = inp_getInt(&pAuxEmp->sueldo, "\nIngrese el nuevo sueldo: ", MAX_TRYS, "Error! Lo ingresado no es un numero.\nIntentos restantes: %d");
				break;
			case 4:
				returnAux = 0;
				*more = 1;
				break;
			case 5:
				returnAux = 0;
				*more = 0;
				break;
			}
		}while( option != 4 && option != 5 );
	}
	return returnAux;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	int auxID;
	int more;
	Employee* pAuxEmp;
	if( pArrayListEmployee != NULL )
	{
		do
		{
			more = 0;
			progHeader("ABM EMPLEADOS");
			subHeader("MODIFICACIONES");

			aux_employee_showAll(pArrayListEmployee);

			if( aux_inp_getID(&auxID, pArrayListEmployee, "\n\nIngrese el Id del empleado que desea modificar: ", MAX_TRYS, "Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d", "Error! Lo ingresado no es un numero. \nIntentos restantes: %d") == -2 ||
				(pAuxEmp = ll_get(pArrayListEmployee, auxID)) == NULL)
			{
				returnAux = -2;
				break;
			}

			progHeader("ABM EMPLEADOS");
			subHeader("MODIFICACIONES");

			returnAux = aux_editMenu(pAuxEmp, &more);

		}while( more == 1 && returnAux != -1 && returnAux != -2 );
	}
	return returnAux;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	Employee* pAuxEmp;
	int idToDelete;
	int more;
	int option;
	int options[2] = {0,1};
	if( pArrayListEmployee != NULL )
	{
		do
		{
			option = 1;
			more = 0;
			progHeader("ABM EMPLEADOS");
			subHeader("BAJAS");

			aux_employee_showAll(pArrayListEmployee);

			if( ll_len(pArrayListEmployee) == 0 ||
				aux_inp_getID(&idToDelete, pArrayListEmployee, "\n\nIngrese el Id del empleado que desea borrar de la base de datos: ", MAX_TRYS, "Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d", "Error! Lo ingresado no es un numero. \nIntentos restantes: %d") == -2 ||
				(pAuxEmp = ll_pop(pArrayListEmployee, idToDelete)) == NULL)
			{
				printf("\nError! No hay mas empleados en la base de datos para borrar.");
				returnAux = -2;
				break;
			}

			progHeader("ABM EMPLEADOS");
			subHeader("BAJAS");

			printf("\nID: %d\nNombre: %s\nHoras Trabajadas: %d\nSueldo: %d", pAuxEmp->id, pAuxEmp->nombre, pAuxEmp->horasTrabajadas, pAuxEmp->sueldo);

			if( inp_getIntConcrete(&option, "\nSon estos datos correctos? (NO = 0, Si = 1): ", MAX_TRYS, 2, options, "Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d", "Error! Lo ingresado no es un numero. \nIntentos restantes: %d") == -1 )
			{
				break;
			}
			else if( option == 1 )
			{
				free(pAuxEmp);
				returnAux = inp_getIntConcrete(&more, "\nDesea borrar mas? (NO = 0, Si = 1): ", MAX_TRYS, 2, options, "Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d", "Error! Lo ingresado no es un numero. \nIntentos restantes: %d");
			}
			else
			{
				returnAux = ll_add(pArrayListEmployee, pAuxEmp);
			}

		}while( option == 0 || more == 1 );
	}
	return returnAux;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	if( pArrayListEmployee != NULL )
	{
		progHeader("ABM EMPLEADOS");
		subHeader("LISTA DE EMPLEADOS");

		aux_employee_showAll(pArrayListEmployee);
	}
	return returnAux;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee( LinkedList* pArrayListEmployee )
{
	int returnAux = -1;
	int option;
	int options[4] = {1,2,3,4};
	if( pArrayListEmployee != NULL )
	{
		progHeader("ABM EMPLEADOS");
		subHeader("ORDENAR EMPLEADOS");
		printf("\n\n1. Ordenar por Id\n2. Ordenar por Nombre\n3. Ordenar por Horas Trabajadas\n4. Ordenar por Sueldo");
		returnAux = inp_getIntConcrete(&option, "\nOpcion: ", MAX_TRYS, 4, options, "Error! Lo ingresado no corresponde con los valores esperados. \nIntentos restantes: %d", "Error! Lo ingresado no es un numero. \nIntentos restantes: %d");
		if( returnAux == 0 )
		{
			switch( option )
			{
			case 1:
				returnAux = ll_sort(pArrayListEmployee, employee_cmpId, 1);
				break;
			case 2:
				returnAux = ll_sort(pArrayListEmployee, employee_cmpNombre, 1);
				break;
			case 3:
				returnAux = ll_sort(pArrayListEmployee, employee_cmpHorasTrabajadas, 1);
				break;
			case 4:
				returnAux = ll_sort(pArrayListEmployee, employee_cmpSueldo, 1);
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	int len;
	FILE* pFile;
	Employee* pAuxEmp;
	pFile = fopen(path,"w");
	if( pArrayListEmployee != NULL && path != NULL && pFile != NULL )
	{
		len = ll_len(pArrayListEmployee);
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		returnAux = 0;
		for( int i = 0; i < len; i++)
		{
			if( (pAuxEmp=ll_get(pArrayListEmployee, i)) != NULL )
			{
				fprintf(pFile,"%d,%s,%d,%d\n",pAuxEmp->id,pAuxEmp->nombre,pAuxEmp->horasTrabajadas,pAuxEmp->sueldo);
			}
			else
			{
				returnAux = -1;
				break;
			}
		}
		fclose(pFile);
	}
	return returnAux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	int len;
	Employee* pAuxEmp;
	FILE* pFile;
	pFile = fopen(path,"b");
	if( pArrayListEmployee != NULL && path != NULL && pFile != NULL )
	{
		len = ll_len(pArrayListEmployee);
		returnAux = 0;
		for( int i = 0; i < len; i++ )
		{
			if( ( pAuxEmp = ll_get(pArrayListEmployee, i) ) != NULL )
			{
				fwrite(pAuxEmp,sizeof(Employee),1,pFile);
			}
			else
			{
				returnAux = -1;
				break;
			}
		}
		fclose(pFile);
	}
	return returnAux;
}
