/*
 * aux_main.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_AUX_MAIN_H_
#define HEATHERS_AUX_MAIN_H_


#endif /* HEATHERS_AUX_MAIN_H_ */

//Program Title
#define TITLE "Calculadora"
#define SUB_TITLE_A "Resolucion"

//Output Menu
#define MENU_OPT_ONE_A "\n1. Ingresar 1er operando (A=X)"
#define MENU_OPT_ONE_B "\n1. Ingresar 1er operando (A=%d)"
#define MENU_OPT_TWO_A "\n2. Ingresar 2do operando (B=Y)"
#define MENU_OPT_TWO_B "\n2. Ingresar 2do operando (B=%d)"
#define MENU_OPT_THREE "\n3. Calcular todas las operaciones"
#define MENU_OPT_FOUR "\n4. Informar resultados"
#define MENU_OPT_FIVE "\n5. Salir"

//Output Results
#define ADDITION_RES "\nEl resultado de %d+%d es: %lld"
#define SUBSTRACTION_RES "\nEl resultado de %d-%d es: %lld"
#define MULTIPLICATION_RES "\nEl resultado de %d*%d es: %lld"
#define DIVICION_RES "\nEl resultado de %d/%d es: %0.2f"
#define FACTORIAL_RES_ONE "\nEl factorial de %d es: "

/**
 * @fn void main_showMenu(int, int, int, int)
 * @brief Prints out the program main menu
 *
 * @param numberA operand just for showing
 * @param numberB operand just for showing
 * @param numberAReady flag to show/or not number A in main menu
 * @param numberBReady flag to show/or not number A in main menu
 */
void main_showMenu( int numberA, int numberB , int numberAReady, int numberBReady );

/**
 * @fn int main_runOperations(int, int, long long int*, long long int*, long long int*, float*, unsigned char*, unsigned char*, int*, int*)
 * @brief Runs math operations over numberA and numberB operands
 *
 * @param numberA operand
 * @param numberB operand
 * @param sum memory allocation to enter A + B
 * @param substraction memory allocation to enter A - B
 * @param product memory allocation to enter A * B
 * @param quotient memory allocation to enter A / B
 * @param factorialA memory allocation to enter A!
 * @param factorialB memory allocation to enter B!
 * @param sizeFacA factorialA length
 * @param sizeFacB factorialA length
 * @return 0 if all OK or the error id
 *
 * Errors IDs:
	 -1 = Given NULL Memory allocations
	 -2 = DIVICION_ERROR (only)
	 -3 = FACTORIAL_ERROR (only number A)
	 -4 = FACTORIAL_ERROR (only number B)
	 -5 = FACTORIAL_ERROR (both numbers)
	 -6 = DIVICION_ERROR && FACTORIAL_ERROR (only number A)
 */
int main_runOperations( int numberA, int numberB, long long int* sum,
						long long int* substraction, long long int* product,
						float* quotient, unsigned char* factorialA,
						unsigned char* factorialB, int* sizeFacA, int* sizeFacB);


/**
 * @fn void main_showResults(int, int, long long int, long long int, long long int, float, unsigned char*, unsigned char*, int, int, int)
 * @brief Shows the results of math operations over the A and B number operands
 *
 * @param numberA operand
 * @param numberB operand
 * @param sum A + B
 * @param substraction A - B
 * @param product A * B
 * @param quotient A / B
 * @param factorialA A!
 * @param factorialB B!
 * @param errors
 * @param sizeFacA
 * @param sizeFacB
 */
void main_showResults( int numberA, int numberB, long long int sum,
					   long long int substraction, long long int product,
					   float quotient, unsigned char* factorialA,
					   unsigned char* factorialB, int errors , int sizeFacA,
					   int sizeFacB);
