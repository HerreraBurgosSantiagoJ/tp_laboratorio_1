/*
 * calculate.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_CALCULATE_H_
#define HEATHERS_CALCULATE_H_



#endif /* HEATHERS_CALCULATE_H_ */

//Posible errors
#define DIVICION_ERROR "\nError, la divicion por cero no es posible"
#define FACTORIAL_ERROR "\nError, no se puede calcular el factorial de %d ya que es un numero negativo"
//Overflow error not considered in this version

#define MAX_FACTORIAL_LENGTH 50

/**
 * @fn long long int cal_add(int, int)
 * @brief gets 2 numbers to sum them returns the sum
 *
 * @param numberA
 * @param numberB
 * @return numberA + number B
 */
long long int cal_add( int numberA, int numberB );

/**
 * @fn int cal_subtract(int, int)
 * @brief Substracts B from A
 *
 * @param numberA
 * @param numberB
 * @return A-B
 */
long long int cal_subtract(int  numberA, int numberB );

/**
 * @fn long long int cal_multiply(int, int)
 * @brief Multiplies A*B
 *
 * @param factorA
 * @param factorB
 * @return A*B
 */
long long int cal_multiply(int factorA, int factorB );

/**
 * @fn int cal_divide(int, int, float*)
 * @brief Divides dividend on divider
 *
 * @param dividend
 * @param divider
 * @param quotient Pointer to return the division
 * @return 0 if all OK,-1 if divider is 0
 */
int cal_divide(int dividend, int divider, float *quotient );

/**
 * @fn int cal_factorial(int, long long int*)
 * @brief Will calculate (number)!
 *
 * @param number
 * @param factorial Pointer to return answer
 * @return 0 if all OK, -1 if number < 0
 */
int cal_factorial( int number, long long int* factorial );

/**
 * @fn int cal_greatFactorial(int, unsigned char*, int*)
 * @brief Will calculate (number)! use when number is greater than 12
 *
 * @param number
 * @param factorial Pointer to return answer (is read backwards from, size - 1)
 * @param size Length of factorial
 * @return 0 if no pointer is not given to factorial or number < 0
 */
int cal_greatFactorial( int number, unsigned char* factorial, int* size );

/**
 * @fn int cal_aux_GreatFac(unsigned char*, int)
 * @brief Helps to print out a greater factorial
 *
 * @param factorial
 * @param size
 * @return 0 if all OK, -1 if no pointer given or size < 1
 */
int cal_aux_GreatFac( unsigned char* factorial, int size );
