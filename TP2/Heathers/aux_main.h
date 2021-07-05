/*
 * aux_main.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_AUX_MAIN_H_
#define HEATHERS_AUX_MAIN_H_


#endif /* HEATHERS_AUX_MAIN_H_ */

#include "../Heathers/ArrayEmployees.h"
//Program Title
#define TITLE "ABM"
#define SUB_TITLE_MAIN "Menu Principal"
#define SUB_TITLE_REG "ALTAS"
#define SUB_TITLE_MOD "MODIFICAR"
#define SUB_TITLE_DEL "BAJAS"
#define SUB_TITLE_INF "INFORME"
#define SUB_TITLE_ERROR "Error"

//Output Menu(Main)
#define MENU_MAIN_ONE "\n1. ALTAS."
#define MENU_MAIN_TWO "\n2. MODIFICACIONES."
#define MENU_MAIN_THREE "\n3. BAJAS."
#define MENU_MAIN_FOUR "\n4. INFORMAR."
#define MENU_MAIN_FIVE "\n5. Hardcode. (Test, only 10 Employees overwrites if needed)"
#define MENU_MAIN_SIX "\n6. Salir."

//Outut Modify Menu
#define MENU_MOD_ONE "\n1. Cambiar Nombre."
#define MENU_MOD_TWO "\n2. Cambiar Apellido."
#define MENU_MOD_THREE "\n3. Cambiar Salario."
#define MENU_MOD_FOUR "\n4. Cambiar Sector."
#define MENU_MOD_FIVE "\n5. Modificar otro empleado"
#define MENU_MOD_SIX "\n6. Salir"

//Output
#define TXT_FULL_DATABASE "\nNo es posible, base de datos llena."
#define TXT_EMPTY_DATABASE "\nNo es posible, base de datos vacia."
#define TXT_NEW_ID "\nEl Legajo del nuevo empleado es %d."
#define TXT_EMPLOYEE_DATA "\nLegajo: %05d\nNombre: %s, %s.\nSalario: %.02f\nSector: %d."
#define TXT_REMOVAL_SUCCESES "\nEl empleado fue dado de BAJA con exito."
#define TXT_INFORM "\nLa suma del sueldo de los empleados es %0.2f\nSiendo el promedio %0.2f\nY la cantidad de empleados cuyo sueldo supera el promedio es %d"
#define GOODBYE "\nHasta Luego! :D"

//Output Errors
#define MAIN_ERROR_MALFUNCTION_EXIT "\nEl programa parece estar funcionando mal, este se cerrará."
#define MAIN_ERROR_MISUSE_EXIT "\nEl usuario no es apto para el uso del programa, este se cerrará"

//Input options
#define INP_TXT_OPTION "\nOpción: "

#define INP_TXT_DATA_OK "\nSon estos datos correctos? (Si=1/No=0): "
#define INP_TXT_MORE_REG "\nDesea dar de ALTA a otro empleado? (Si=1/No=0): "
#define INP_TXT_MORE_DEL "\nDesea dar de BAJA a otro empleado? (Si=1/No=0): "

#define INP_TXT_DEL_ID "\nIngrese el legajo del empleado que desea borrar( Para cancelar ingrese 0 ): "

//Input employee data
#define INP_TXT_NAME "\nIngrese el nombre: "
#define INP_TXT_NAME_NEW "\nIngrese el nuevo nombre: "
#define INP_TXT_LAST_NAME "\nIngrese el apellido: "
#define INP_TXT_LAST_NAME_NEW "\nIngrese el nuevo apellido: "
#define INP_TXT_SALARY "\nIngrese el salario: "
#define INP_TXT_SALARY_NEW "\nIngrese el nuevo salario: "
#define INP_TXT_SECTOR "\nIngrese el sector: "
#define INP_TXT_SECTOR_NEW "\nIngrese el nuevo sector: "

//Input errors
#define INP_ERROR_MAIN_OPTION "\nError! Lo ingresado no corresponde con ninguna de las opciones del menu principal.\nIntentos Restantes: %d"
#define INP_ERROR_MOD_OPTION "\nError! Lo ingresado no corresponde con ninguna de las opciones de este menu.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_EXPECTED_INT "\nError! El numero ingresado no corresponde con los valores esperados.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_NUMBER "\nError! Lo ingresado no es un numero.\nIntentos Restantes: %d"
#define INP_ERROR_NOT_NAME "\nError! Lo ingresado contiene caracteres no esperados en un nombre.\nIntentos Restantes: %d"

//Numerical constants
#define MAX_EMP 11 //For testing, a 11 is recomended 1000 is to much load for static memory
#define MAX_TRYS 3
#define LEN_MAIN_OPT 6
#define LEN_MODY_OPT 6
#define LEN_INT_YN_OPT 2

/**
 * @fn int main_registerEmployee(Employee*, int)
 * @brief Lets user load a new emplyee on the database
 *
 * @param list
 * @param length
 * @return 0 if all ok, -1 if technical error, -2 if user is not apt to use the program
 */
int main_registerEmployee( Employee* list, int length );

/**
 * @fn int main_deleteEmployee(Employee*, int)
 * @brief Lets user pick an employee by ID to delete
 *
 * @param list
 * @param length
 * @return 0 if all ok, -1 if technical error, -2 if user is not apt to use the program
 */
int main_deleteEmployee( Employee* list, int length );

/**
 * @fn void mody_menuShow(void)
 * @brief Prints the modify menu
 *
 */
void mody_menuShow( void );

/**
 * @fn int main_modifyEmployee(Employee*, int)
 * @brief Lets user pick an employee on database by ID to modify, allowing user to
 * 		 change name, lastname, salary and sector
 *
 * @param list
 * @param length
 * @return 0 if all ok, -1 if technical error, -2 if user is not apt to use the program
 */
int main_modifyEmployee( Employee* list, int length );

/**
 * @fn int main_inform(Employee*, int)
 * @brief Shows the employees on list, sorted by name and sector, the sum of
 * 		  salaries, its averagege and how many employees salary is higher than
 * 		  the average.
 *
 * @param list
 * @param length
 * @return 0 if all ok, -1 if technical error
 */
int main_inform( Employee* list, int length );

/**
 * @fn int test_hardcode(Employee*, int)
 * @brief Fills the first 10 spaces of the database with random information
 * 		  For testing purposes
 *
 * @param list
 * @param length
 * @return 0 if all ok, -1 if technical error
 */
int test_hardcode( Employee* list, int length );

/**
 * @fn void main_menuShow(void)
 * @brief Prints Main Menu
 *
 */
void main_menuShow( void );

/**
 * @fn int main_menu(Employee*, int)
 * @brief Logic behind employees ABM main menu
 *
 * @param list
 * @param listLength
 * @return 0 if all ok, -1 if technical error, -2 if user is not apt to use the program
 */
int main_menu( Employee* list, int listLength );
