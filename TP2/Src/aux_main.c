/*
 * aux_main.c
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "../Heathers/aux_main.h"
#include "../Heathers/steart.h"
#include "../Heathers/ArrayEmployees.h"
#include "../Heathers/input_lib.h"
#include "../Heathers/my_system.h"
//#include "../Heathers/"

int main_registerEmployee( Employee* list, int length )
{
	int returnAux = -1;
	int allOk = 1;
	int options[LEN_INT_YN_OPT] = {0,1};
	int keepOn;
	Employee auxEmp;
	if( list != NULL && length > 0 )
	{
		do
		{
			progHeader( TITLE );
			subHeader( SUB_TITLE_REG );
			keepOn = 0;
			if( allOk && empHasSpace( list, length ) )
			{
				auxEmp.id = generateID( list, length );
				auxEmp.isEmpty = 0;
				printf( TXT_NEW_ID, auxEmp.id );
			}
			else if( allOk )
			{
				printf( TXT_FULL_DATABASE );
				returnAux = 0;
				sys_pause();
				break;
			}

			if( inp_getName( auxEmp.lastName, INP_TXT_LAST_NAME, NAME_LENGTH,
							MAX_TRYS, INP_ERROR_NOT_NAME)== 0 &&
				inp_getName( auxEmp.name, INP_TXT_NAME, NAME_LENGTH, MAX_TRYS,
							INP_ERROR_NOT_NAME) == 0 &&
				inp_getFloat( &auxEmp.salary, INP_TXT_SALARY, MAX_TRYS,
							INP_ERROR_NOT_NUMBER) == 0 &&
				inp_getInt( &auxEmp.sector, INP_TXT_SECTOR, MAX_TRYS,
							INP_ERROR_NOT_NUMBER) == 0 )
			{
				printf( TXT_EMPLOYEE_DATA, auxEmp.id, auxEmp.lastName,
						auxEmp.name, auxEmp.salary, auxEmp.sector );
				returnAux = inp_getIntConcrete( &allOk, INP_TXT_DATA_OK,
												MAX_TRYS, LEN_INT_YN_OPT,
												options,
												INP_ERROR_NOT_EXPECTED_INT,
												INP_ERROR_NOT_NUMBER );
			}
			else
			{
				returnAux = -2;
				break;
			}

			if( allOk && returnAux == 0 )
			{
				returnAux = addEmployee(list, length, auxEmp.id, auxEmp.name,
										auxEmp.lastName, auxEmp.salary,
										auxEmp.sector );
				returnAux = inp_getIntConcrete( &keepOn, INP_TXT_MORE_REG,
												MAX_TRYS, LEN_INT_YN_OPT,
												options,
												INP_ERROR_NOT_EXPECTED_INT,
												INP_ERROR_NOT_NUMBER );
			}
			else if( returnAux == 0 )
			{
				keepOn = 1;
			}


		}while( keepOn && returnAux != -2 );
	}
	return returnAux;
}

int main_deleteEmployee( Employee* list, int length )
{
	int returnAux = -1;
	int options[LEN_INT_YN_OPT] = {0,1};
	int auxID;
	int auxMax;
	int keepOn;
	int position;
	int allOk = 1;
	int trys = MAX_TRYS;
	if( list != NULL && length > 0 )
	{
		do
		{
			keepOn = 0;
			progHeader( TITLE );
			subHeader( SUB_TITLE_DEL );

			if( emp_therAreEmployees( list, length ) )
			{
				printEmployees( list, length );
			}
			else
			{
				printf( TXT_EMPTY_DATABASE );
				sys_pause();
				returnAux = 0;
				break;
			}

			auxMax = emp_findGreaterID( list, length );

			if( inp_getIntRange( &auxID, INP_TXT_DEL_ID, trys, 0, auxMax,
								INP_ERROR_NOT_EXPECTED_INT,
								INP_ERROR_NOT_NUMBER) == 0
				&& auxID != 0
				&& (position = findEmployeeById( list, length, auxID )) != -1 )
			{
				progHeader( TITLE );
				subHeader( SUB_TITLE_DEL );
				printf( TXT_EMPLOYEE_DATA, list[position].id,
						list[position].lastName, list[position].name,
						list[position].salary, list[position].sector );
				returnAux = inp_getIntConcrete(&allOk, INP_TXT_DATA_OK,
												MAX_TRYS, LEN_INT_YN_OPT,
												options,
												INP_ERROR_NOT_EXPECTED_INT,
												INP_ERROR_NOT_NUMBER);
			}
			else if( auxID == 0 )
			{
				returnAux = 0;
				break;
			}
			else if( position == -1 && trys > 0 )
			{
				trys--;
				printf( INP_ERROR_NOT_EXPECTED_INT, trys );
				sys_pause();
				keepOn = 1;
				continue;
			}
			else if( position == -1 )
			{
				returnAux = -2;
				break;
			}

			if( allOk )
			{
				returnAux = removeEmployee( list, length, auxID );
				printf( TXT_REMOVAL_SUCCESES );
			}
			else
			{
				keepOn = 1;
				continue;
			}

			returnAux = inp_getIntConcrete( &keepOn, INP_TXT_MORE_DEL, MAX_TRYS,
											LEN_INT_YN_OPT, options,
											INP_ERROR_NOT_EXPECTED_INT,
											INP_ERROR_NOT_NUMBER );

		}while( keepOn && returnAux == 0 );
	}
	return returnAux;
}

void mody_menuShow( void )
{
	printf( MENU_MOD_ONE );
	printf( MENU_MOD_TWO );
	printf( MENU_MOD_THREE );
	printf( MENU_MOD_FOUR );
	printf( MENU_MOD_FIVE );
	printf( MENU_MOD_SIX );
}

int mody_menu( Employee* employee, int* keepOn )
{
	int returnAux = -1;
	int options[LEN_MODY_OPT] = {1, 2, 3, 4, 5, 6};
	int option = 0;
	if( employee != NULL )
	{
		do
		{
			progHeader(TITLE);
			subHeader(SUB_TITLE_MOD);
			printf( TXT_EMPLOYEE_DATA, employee->id, employee->lastName,
					employee->name, employee->salary, employee->sector );
			mody_menuShow();
			if( inp_getIntConcrete(&option, INP_TXT_OPTION, MAX_TRYS,
											LEN_MODY_OPT, options,
											INP_ERROR_MOD_OPTION,
											INP_ERROR_NOT_NUMBER) != 0 )
			{
				returnAux = -2;
				break;
			}
			switch ( option )
			{
			case 1:
				returnAux = inp_getName(employee->name, INP_TXT_NAME_NEW,
										NAME_LENGTH, MAX_TRYS,
										INP_ERROR_NOT_NAME);
				break;
			case 2:
				returnAux = inp_getName(employee->lastName,
										INP_TXT_LAST_NAME_NEW, NAME_LENGTH,
										MAX_TRYS, INP_ERROR_NOT_NAME);
				break;
			case 3:
				returnAux = inp_getFloat(&employee->salary, INP_TXT_SALARY_NEW,
										MAX_TRYS, INP_ERROR_NOT_NUMBER);
				break;
			case 4:
				returnAux = inp_getInt(&employee->sector, INP_TXT_SECTOR_NEW,
										MAX_TRYS, INP_ERROR_NOT_NAME);
				break;
			case 5:
				*keepOn = 1;
				returnAux = 0;
				break;
			case 6:
				returnAux = 0;
				break;
			}
		}while( returnAux != -2 && option != 5 && option != 6 );
	}
	return returnAux;
}

int main_modifyEmployee( Employee* list, int length )
{
	int returnAux = -1;
	int keepOn;
	int auxMax;
	int auxMin;
	int auxID;
	int position;
	if( list != NULL && length > 0 )
	{
		do
		{
			keepOn = 0;
			progHeader( TITLE );
			subHeader( SUB_TITLE_MOD );

			if( emp_therAreEmployees( list, length ) )
			{
				printEmployees( list, length );
			}
			else
			{
				printf( TXT_EMPTY_DATABASE );
				sys_pause();
				returnAux = 0;
				break;
			}

			auxMax = emp_findGreaterID( list, length );
			auxMin = emp_findMinorID( list, length );

			if( inp_getIntRange( &auxID, INP_TXT_DEL_ID, MAX_TRYS, auxMin,
								auxMax, INP_ERROR_NOT_EXPECTED_INT,
								INP_ERROR_NOT_NUMBER) == 0 )
			{
				position = findEmployeeById( list, length, auxID );
				returnAux = mody_menu( &list[position], &keepOn );
			}
			else
			{
				returnAux = -2;
			}

		}while( keepOn && returnAux == 0 );
	}
	return returnAux;
}

int main_inform( Employee* list, int length )
{
	int returnAux = -1;
	int empQuantity = 0;
	int empQuanHighPay = 0;
	float salarySum = 0;
	float salaryAverage;
	if( list != NULL && length > 0 )
	{
		if( sortEmployees(list, length, 1) == 0 )
		{
			printEmployees(list, length);
			returnAux = 0;
		}

		for( int i = 0; i < length; i++ )
		{
			if( list[i].isEmpty == 0 )
			{
				salarySum += list[i].salary;
				empQuantity++;
			}
		}

		salaryAverage = salarySum / empQuantity;

		for( int i = 0; i < length; i++ )
		{
			if( list[i].isEmpty == 0 && list[i].salary > salaryAverage )
			{
				empQuanHighPay++;
			}
		}

		if( returnAux == 0 )
		{
			printf( TXT_INFORM, salarySum, salaryAverage, empQuanHighPay );
		}
	}
	return returnAux;
}

int test_hardcode( Employee* list, int length )
{
	int returnAux = -1;
	char names[10][10] = { "Abigail\0", "Alex\0", "Eugenia\0", "Manuel\0",
							"Luciana\0", "Rodrigo\0", "Reina\0", "Abraham\0",
							"Leonora\0", "Francisco\0"};
	char lastNames[10][10] = {"Martines\0", "Fernandez\0", "Sanchez\0",
								"Belgrano\0", "Nuñez\0", "Galvan\0", "Paramo\0",
								"Aranda\0", "Torrente\0", "Flores\0"};
	float salaries[10] = {676872, 116453, 921130, 80413, 38509, 58301, 559059,
							822747, 78699, 28814};
	int sector[10] = { 2, 3, 4, 1, 3, 2, 4, 2, 1, 2 };
	if( list != NULL && length > 10 )
	{
		for( int i = 0; i < 10; i++ )
		{
			returnAux = addEmployee( list, length, i+1, names[i], lastNames[i],
									salaries[i], sector[i] );
		}
		returnAux = 0;
	}
	return returnAux;
}

void main_menuShow( void )
{
	printf( MENU_MAIN_ONE );
	printf( MENU_MAIN_TWO );
	printf( MENU_MAIN_THREE );
	printf( MENU_MAIN_FOUR );
	printf( MENU_MAIN_FIVE );
	printf( MENU_MAIN_SIX );
}

int main_menu( Employee* list, int listLength )
{
	int returnAux = -1;
	int option = 0;
	int options[LEN_MAIN_OPT] = {1,2,3,4,5,6};
	if( list != NULL && listLength > 0 )
	{
		do
		{
			progHeader( TITLE );
			subHeader( SUB_TITLE_MAIN );
			main_menuShow();
			returnAux = inp_getIntConcrete(&option, INP_TXT_OPTION, MAX_TRYS,
											LEN_MAIN_OPT, options,
											INP_ERROR_MAIN_OPTION,
											INP_ERROR_NOT_NUMBER);
			if( returnAux == -2 )
			{
				break;
			}
			switch(option)
			{
			case 1:
				if( empHasSpace( list, listLength ) == 1 )
				{
					returnAux = main_registerEmployee( list, listLength );
				}
				else
				{
					printf( TXT_FULL_DATABASE );
					sys_pause();
				}
				break;
			case 2:
				if( emp_therAreEmployees( list, listLength ) )
				{
					returnAux = main_modifyEmployee( list, listLength );
				}
				else
				{
					printf( TXT_EMPTY_DATABASE );
					sys_pause();
				}
				break;
			case 3:
				if( emp_therAreEmployees( list, listLength ) )
				{
					returnAux = main_deleteEmployee( list, listLength );
				}
				else
				{
					printf( TXT_EMPTY_DATABASE );
					sys_pause();
				}
				break;
			case 4:
				if( emp_therAreEmployees( list, listLength ) )
				{
					returnAux = main_inform( list, listLength );
					sys_pause();
				}
				else
				{
					printf( TXT_EMPTY_DATABASE );
					sys_pause();
				}
				break;
			case 5:
				returnAux = test_hardcode( list, listLength );
				break;
			case 6:
				printf( GOODBYE );
				returnAux = 0;
				break;
			}
		}while( option != 6 && returnAux == 0 );
	}
	return returnAux;
}
