#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_newEmpty()
{
	Employee* newEmployee = (Employee*) malloc( sizeof( Employee ) );
	return newEmployee;
}

Employee* employee_new( char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr )
{
	Employee* newEmployee = employee_newEmpty();
	int id;
	int horas;
	int sueldo;
	if( newEmployee != NULL &&
		idStr != NULL &&
		nombreStr != NULL &&
		horasTrabajadasStr != NULL )
	{
		id = atoi(idStr);
		horas = atoi(horasTrabajadasStr);
		sueldo = atoi( sueldoStr );
		if( employee_setId(newEmployee, id) == -1 ||
			employee_setNombre(newEmployee, nombreStr) == -1 ||
			employee_setHorasTrabajadas(newEmployee, horas) == -1 ||
			employee_setSueldo(newEmployee, sueldo) == -1 )
		{
			newEmployee = NULL;
		}
	}
	return newEmployee;
}

void employee_delete( Employee* toDelete )
{
	free(toDelete);
}

int employee_setId(Employee* this,int id)
{
	int returnAux = -1;
	if( this != NULL )
	{
		this->id = id;
		returnAux = 0;
	}
	return returnAux;
}

int employee_getId(void* this,int* id)
{
	int returnAux = -1;
	Employee* pAuxEmp = (Employee*) this;
	if( this != NULL && id != NULL)
	{
		*id = pAuxEmp->id;
		returnAux = 0;
	}
	return returnAux;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int returnAux = -1;
	if( this != NULL && nombre != NULL)
	{
		strncpy( this->nombre, nombre, 128);
		returnAux = 0;
	}
	return returnAux;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int returnAux = -1;
	if( this != NULL && nombre != NULL)
	{
		strncpy( nombre, this->nombre, 128);
		returnAux = 0;
	}
	return returnAux;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int returnAux = -1;
	if( this != NULL )
	{
		this->horasTrabajadas = horasTrabajadas;
		returnAux = 0;
	}
	return returnAux;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int returnAux = -1;
	if( this != NULL )
	{
		*horasTrabajadas = this->horasTrabajadas;
		returnAux = 0;
	}
	return returnAux;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int returnAux = -1;
	if( this != NULL )
	{
		this->sueldo = sueldo;
		returnAux = 0;
	}
	return returnAux;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int returnAux = -1;
	if( this != NULL )
	{
		*sueldo = this->sueldo;
		returnAux = 0;
	}
	return returnAux;
}

int employee_show( Employee* this )
{
	int returnAux = -1;
	if( this != NULL )
	{
		printf("\n%d|%s|%d|%d",
				this->id,
				this->nombre,
				this->horasTrabajadas,
				this->sueldo);
		returnAux = 0;
	}
	return returnAux;
}

int employee_cmpId( void* empA, void* empB )
{
	int returnAux = -1;
	int idA;
	int idB;
	if( empA != NULL && empB != NULL )
	{
		employee_getId(empA, &idA);
		employee_getId(empB, &idB);
		if( idA < idB )
		{
			returnAux = -1;
		}
		else if( idA > idB )
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

int employee_cmpNombre( void* empA, void* empB )
{
	int returnAux;
	char nameA[128];
	char nameB[128];
	if( empA != NULL && empB != NULL )
	{
		employee_getNombre((Employee*)empA, nameA);
		employee_getNombre((Employee*)empB, nameB);
		returnAux = strncmp( nameA, nameB, 128 );
	}
	return returnAux;
}

int employee_cmpHorasTrabajadas( void* empA, void* empB )
{
	int returnAux = 0;
	int horasTrabajadasA;
	int horasTrabajadasB;
	if( empA != NULL && empB != NULL )
	{
		employee_getHorasTrabajadas((Employee*)empA, &horasTrabajadasA);
		employee_getHorasTrabajadas((Employee*)empB, &horasTrabajadasB);
		if( horasTrabajadasA < horasTrabajadasB )
		{
			returnAux = -1;
		}
		else if( horasTrabajadasA > horasTrabajadasB )
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
	}
	return returnAux;
}

int employee_cmpSueldo( void* empA, void* empB )
{
	int returnAux = -1;
	int sueldoA;
	int sueldoB;
	if( empA != NULL && empB != NULL )
	{
		employee_getSueldo((Employee*)empA, &sueldoA);
		employee_getSueldo((Employee*)empB, &sueldoB);
		if( sueldoA < sueldoB )
		{
			returnAux = -1;
		}
		else if( sueldoA > sueldoB )
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
	}
	return returnAux;
}
