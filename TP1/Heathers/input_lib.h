/*
 * inputLib.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_INPUT_LIB_H_
#define HEATHERS_INPUT_LIB_H_



#endif /* HEATHERS_INPUT_LIB_H_ */


#define INT_INPUT_ERROR "\nError, lo ingresado no es un numero"
#define UNACCEPTABLE_VALUE_ERROR "\nError, lo ingresado no se encuentra entre los valores aceptables"
#define NAME_IGNORED_VALUES "|1234567890\'¿°!\"#$%&/()=?¡¬@·~½{[]}\\*-+.,:;_<>"
#define NAME_IGNORED_VALUES_LEN 52
#define MAIL_IGNORED_VALUES "|\'¿°!\"#$&/()=?¡¬·~{[]}\\*,:;<>½ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MAIL_IGNORED_VALUES_LEN 63

/**
 * @fn int inp_getInt(int*, char*, int)
 * @brief Mesages the user to enter an int value, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit
 * @return returns 1 if all OK, -1 if trys hit 0 and no int entered
 */
int inp_getInt( int* number, char* mesage, int trys );

/**
 * @fn int inp_getIntConcrete(int*, char*, int, int, int*)
 * @brief Mesages the user to enter a specific int value, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit. Trys number may be extended
 * @param optLength Options length ( Can't be <1 )
 * @param options Expected int values (Error, if user can't meet any)
 * @return returns 1 if all OK, -1 if trys hit 0 and/or expected input not meet
 */
int inp_getIntConcrete( int* number, char* mesage, int trys , int optLength, int* options );

/**
 * @fn int inp_getIntAvoid(int*, char*, int, int, int*)
 * @brief Mesages the user to enter an int value that is diferent to the ignored list, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit. Trys number may be extended
 * @param ignoredLength Ignored list length ( Can't be <1 )
 * @param ignored Values that must not be entered (Error, if user enters any)
 * @return returns 1 if all OK, -1 if trys hit 0 and/or input value among ignored list
 */
int inp_getIntAvoid( int* number, char* mesage, int trys , int ignoredLength, int* ignored );

/**
 * @fn int inp_getIntRange(int*, char*, int, int, int)
 * @brief Mesages the user to enter an int value in a certain range, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit. Trys number may be extended
 * @param min Minimum expected int
 * @param max Maximum expected int
 * @return returns 1 if all OK, -1 if trys hit 0 and/or input value not in range
 */
int inp_getIntRange( int* number, char* mesage, int trys , int min, int max );

/**
 * @fn int inp_getChar(char*, char*)
 * @brief Mesages the user to enter a char
 *
 * @param character Pointer to char, to store the entered value
 * @param mesage Mesage asking for input
 * @return returns 1 if all OK, -1 if char or mesage == NULL
 */
int inp_getChar( char* character, char* mesage );

/**
 * @fn int inp_getCharConcrete(char*, char*, int, int, char*)
 * @brief Mesages the user to enter a specific char, shows an error mesage else
 *
 * @param character Pointer to char, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param optLength Options length ( Can't be <1 )
 * @param options Expected int values (Error, if user can't meet any)
 * @return 1 if all OK, -1 if char or mesage == NULL or expected values not meet
 */
int inp_getCharConcrete( char* character, char* mesage, int trys , int optLength, char* options );

/**
 * @fn int inp_getcharAvoid(char*, char*, int, int, char*)
 * @brief Mesages the user to enter an char that is not in the ignored list, shows an error mesage else
 *
 * @param character Pointer to char, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param ignoredLength Ignored list length ( Can't be <1 )
 * @param ignored Values that must not be entered (Error, if user enters any)
 * @return returns 1 if all OK, -1 if trys hit 0 and/or input value among ignored list
 */
int inp_getcharAvoid( char* character, char* mesage, int trys , int ignoredLength, char* ignored );

/**
 * @fn int inp_getString(char*, char*, int)
 * @brief Asks the user through mesage to enter a string (name for example)
 *
 * @param cString Memory allocation to save the string input
 * @param mesage Mesage asking for input
 * @param len cString length
 * @return 0 if all OK, -1 if any memory allocation given is NULL
 */
int inp_getString( char* cString, char* mesage, int len);

/**
 * @fn int inp_getName(char*, char*, int, int)
 * @brief Asks the user through mesage to enter a name, will reject any character not expected in a name
 *
 * @param name Memory allocation to save the input name
 * @param mesage Mesage asking for input
 * @param len name length
 * @param trys numbers of trys before an error exit
 * @return 0 if all OK, -1 if any memory allocation given is NULL or trys run out
 */
int inp_getName( char* name, char* mesage, int len, int trys );

/**
 * @fn int inp_getMail(char*, char*, int, int)
 * @brief Asks the user through mesage to enter a mail, will reject any character not expected in a mail
 *
 * @param mail Memory allocation to save the input mail
 * @param mesage Mesage asking for input
 * @param len mail length
 * @param trys numbers of trys before an error exit
 * @return 0 if all OK, -1 if any memory allocation given is NULL or trys run out
 */
int inp_getMail( char* mail, char* mesage, int len, int trys);
