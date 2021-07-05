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
 * @return 0 if it's not, 1 if it its, -1 values == NULL
 */
int val_isAmongChars( char value, char* values, int valuesLength );

/**
 * @fn int val_isAmongFloats(float, float*, int)
 * @brief Checks if an Float value is among an array of values
 *
 * @param value
 * @param values
 * @param valuesLength
 * @return
 */
int val_isAmongFloats( float value, float* values, int valuesLength );

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

/**
 * @fn int val_swap(void*, void*)
 * @brief swaps the pointers given
 *
 * @param valueA pointer
 * @param valueB pointer
 * @return 0 if all ok, -1 if a pointer is not given
 */
int val_swap( void* valueA, void* valueB );

/**
 * @fn int val_strCpy(char*, char*)
 * @brief Copies the content on "from" on "to" string safely
 *
 * @param from
 * @param to
 * @return
 */
int val_strCpy( char* from, char* to, int toLen );


///Not Ready for use
/**
 * @fn int val_strCmp(char*, char*, int)
 * @brief Compares the data between two strings
 *
 * @param aString
 * @param bString
 * @param cmpLimit
 * @return
 */
int val_strCmp( char* aString, char* bString, int cmpLimit );
