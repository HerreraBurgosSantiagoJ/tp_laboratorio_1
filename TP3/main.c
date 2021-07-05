#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "steart.h"
#include "input_lib.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	int returnAux = -1;
    int option = 0;
    int options[10] = {1,2,3,4,5,6,7,8,9,10};
    int flagLoadedData = 0;
    int flagSortedData = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int listLen;
    do{
    	listLen = ll_len(listaEmpleados);
    	progHeader("ABM Empleados");
    	subHeader("MENU PRINCIPAL");
    	printf("\n\nEmpleados en la base de datos: %d\n\n1. Cargar los datos de los empleados desde el archivo data.csv\n2. Cargar los datos de los empleados desde el archivo data.bin\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv\n9. Guardar los datos de los empleados en el archivo data.bin\n10. Salir", listLen);
    	if( inp_getIntConcrete(&option, "\nOpcion: ", MAX_TRYS, 10, options,
    							"Error! Lo ingresado no corresponde con los valores esperados\nIntentos Restantes: %d",
								"Error! Lo ingresado no es un numero\nIntentos restantes: %d") == -1 )
    	{
    		break;
    	}
        switch(option)
        {
            case 1:
            	returnAux = controller_loadFromText("data.csv",listaEmpleados);
            	flagSortedData = 1;
            	break;
            case 2:
            	returnAux = controller_loadFromBinary("data.bin", listaEmpleados);
            	flagSortedData = 1;
            	break;
            case 3:
            	returnAux = controller_addEmployee(listaEmpleados);
            	flagSortedData = 0;
            	break;
            case 4:
            	if( flagLoadedData != 0 )
            	{
            		returnAux = controller_editEmployee(listaEmpleados);
            		flagSortedData = 0;
            	}
            	break;
            case 5:
            	if( flagLoadedData != 0 )
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	break;
            case 6:
            	if( flagLoadedData != 0 )
            	{
            		returnAux = controller_ListEmployee(listaEmpleados);
            	}
            	break;
            case 7:
            	if( flagLoadedData != 0 )
            	{
            		returnAux = controller_sortEmployee(listaEmpleados);
            		flagSortedData = 1;
            	}
            	break;
            case 8:
            	if( flagLoadedData != 0 && flagSortedData )
            	{
            		returnAux = controller_saveAsText("data.csv", listaEmpleados);
            	}
            	break;
            case 9:
            	if( flagLoadedData != 0 && flagSortedData )
            	{
            		returnAux = controller_saveAsBinary("data.bin", listaEmpleados);
            	}
            	break;
            case 10:
            	break;
        }
    }while(option != 10);
    return returnAux;
}

