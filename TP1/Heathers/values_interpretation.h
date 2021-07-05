/*
 * values_interpretation.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_VALUES_INTERPRETATION_H_
#define HEATHERS_VALUES_INTERPRETATION_H_



#endif /* HEATHERS_VALUES_INTERPRETATION_H_ */

/**
 * @fn int val_isAmongInts(int, int*, int)
 * @brief Checks if an int value is among an array of values
 *
 * @param value
 * @param values
 * @param valuesLength
 * @return 0 if it's not, 1 if it its, -1 values == NULL
 */
int val_isAmongInts( int value, int* values, int valuesLength);

/**
 * @fn int val_isAmongChars(char, char*, int)
 * @brief Checks if an Char value is among an array of values
 *
 * @param value
 * @param values
 * @param valuesLength
 * @return0 if it's not, 1 if it its, -1 values == NULL
 */
int val_isAmongChars( char value, char* values, int valuesLength );

/**
 * @fn int val_stringHasAny(char*, int, char*, int)
 * @brief Checks if any of the values is in a string
 *
 * @param cString
 * @param cStringLen
 * @param values
 * @param valuesLength
 * @return 0 if is not any, 1 if any is, -1 if values == NULL
 */
int val_stringHasAny( char* cString, int cStringLen, char* values, int valuesLength );
