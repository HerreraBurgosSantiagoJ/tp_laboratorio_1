/*
 * inputLib.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_INPUT_LIB_H_
#define HEATHERS_INPUT_LIB_H_

typedef struct{
	int day;
	int month;
	int year;
}sDate;

#endif /* HEATHERS_INPUT_LIB_H_ */


#define INT_INPUT_ERROR "\nError, lo ingresado no es un numero"
#define UNACCEPTABLE_VALUE_ERROR "\nError, lo ingresado no se encuentra entre los valores aceptables"
#define NAME_IGNORED_VALUES "|1234567890\'¿°!\"#$%&/()=?¡¬@·~½{[]}\\*-+.,:;_<>"
#define NAME_IGNORED_VALUES_LEN 52
#define MAIL_IGNORED_VALUES "|\'¿°!\"#$&/()=?¡¬·~{[]}\\*,:;<>½ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define MAIL_IGNORED_VALUES_LEN 59

/**
 * @fn int inp_getInt(int*, char*, int)
 * @brief Mesages the user to enter an int value, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an int in the given trys
 */
int inp_getInt( int* number, char* mesage, int trys, char* errorNotANumber );

/**
 * @fn int inp_getIntConcrete(int*, char*, int, int, int*)
 * @brief Mesages the user to enter a specific int value, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param optLength Options length ( Can't be <1 )
 * @param options Expected int values (Error, if user can't meet any)
 * @param valueError Error mesage, that is shown when user enters values that aren't among the options shown
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter a concrete int in the given trys

 */
int inp_getIntConcrete( int* number, char* mesage, int trys , int optLength,
						int* options, char* valueError, char* errorNotANumber );

/**
 * @fn int inp_getIntAvoid(int*, char*, int, int, int*)
 * @brief Mesages the user to enter an int value that is diferent to the ignored list, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param ignoredLength Ignored list length ( Can't be <1 )
 * @param ignored Values that must not be entered (Error, if user enters any)
 * @param valueError Error mesage, that is shown when user enters values that aren't among the options shown
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an int diferent than the ignored list in the given trys
 */
int inp_getIntAvoid( int* number, char* mesage, int trys , int ignoredLength,
					int* ignored, char* valueError, char* errorNotANumber );

/**
 * @fn int inp_getIntRange(int*, char*, int, int, int)
 * @brief Mesages the user to enter an int value in a certain range, shows an error mesage else
 *
 * @param number Pointer to int, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param min Minimum expected int
 * @param max Maximum expected int
 * @param valueError Error mesage, that is shown when user enters values that aren't among the options shown
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an int in the given trys and range
 */
int inp_getIntRange( int* number, char* mesage, int trys , int min, int max,
					char* valueError, char* errorNotANumber);

/**
 * @fn int inp_getFloat(float*, char*, int, char*)
 * @brief Mesages the user to enter an float value, shows an error mesage else
 *
 * @param number Pointer to float, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an float in the given trys
 */
int inp_getFloat( float* number, char* mesage, int trys, char* errorNotANumber );

/**
 * @fn int inp_getFloatConcrete(float*, char*, int, int, float*, char*, char*)
 * @brief Mesages the user to enter a specific float value, shows an error mesage else
 *
 * @param number Pointer to float, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param optLength Options length ( Can't be <1 )
 * @param options Expected float values (Error, if user can't meet any)
 * @param valueError Error mesage, that is shown when user enters values that aren't among the options shown
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter a concrete float in the given trys
 */
int inp_getFloatConcrete( float* number, char* mesage, int trys , int optLength,
						float* options, char* valueError,
						char* errorNotANumber );

/**
 * @fn int inp_getFloatAvoid(float*, char*, int, int, float*, char*, char*)
 * @brief
 *
 * @param number
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param ignoredLength Ignored list length ( Can't be <1 )
 * @param ignored Values that must not be entered (Error, if user enters any)
 * @param valueError Error mesage, that is shown when user enters values that are among the options shown
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an float diferent than the ignored list in the given trys
 */
int inp_getFloatAvoid( float* number, char* mesage, int trys , int ignoredLength,
						float* ignored, char* valueError,
						char* errorNotANumber );

/**
 * @fn int inp_getFloatRange(float*, char*, int, float, float, char*, char*)
 * @brief
 *
 * @param number
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param min Minimum expected float
 * @param max Maximum expected float
 * @param valueError Error mesage, that is shown when user enters values that aren't among the options shown
 * @param errorNotANumber Error mesage, that is shown when user enters anything but a number
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an float in the given trys and range
 */
int inp_getFloatRange( float* number, char* mesage, int trys , float min,
						float max, char* valueError, char* errorNotANumber );

/**
 * @fn int inp_getChar(char*, char*)
 * @brief Mesages the user to enter a char
 *
 * @param character Pointer to char, to store the entered value
 * @param mesage Mesage asking for input
 * @return 0 if all OK
 * @return -1 if given NULL parameters
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
 * @param valueError Error mesage, that is shown when user enters values that aren't among the options shown
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter a concrete char in the given trys
 */
int inp_getCharConcrete( char* character, char* mesage, int trys , int optLength,
						char* options, char* valueError );

/**
 * @fn int inp_getcharAvoid(char*, char*, int, int, char*)
 * @brief Mesages the user to enter an char that is not in the ignored list, shows an error mesage else
 *
 * @param character Pointer to char, to store the entered value
 * @param mesage Mesage asking for input
 * @param trys Number of trys before an error exit.
 * @param ignoredLength Ignored list length ( Can't be <1 )
 * @param ignored Values that must not be entered (Error, if user enters any)
 * @param valueError Error mesage, that is shown when user enters values that are among the options shown
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an char that is not in the ignored list in the given trys
 */
int inp_getcharAvoid( char* character, char* mesage, int trys , int ignoredLength
					, char* ignored, char* valueError );

/**
 * @fn int inp_getString(char*, char*, int)
 * @brief Asks the user through mesage to enter a string (name for example)
 *
 * @param cString Memory allocation to save the string input
 * @param mesage Mesage asking for input
 * @param stringLength cString length
 * @return 0 if all OK
 * @return -1 if given NULL parameters
 */
int inp_getString( char* cString, char* mesage, int stringLength );

/**
 * @fn int inp_getName(char*, char*, int, int)
 * @brief Asks the user through mesage to enter a name, will reject any character not expected in a name
 *
 * @param name Memory allocation to save the input name
 * @param mesage Mesage asking for input
 * @param len name length
 * @param trys numbers of trys before an error exit
 * @param valueError Error mesage, that is shown when user enters values that are among the options shown
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an NAME in the given trys
 */
int inp_getName( char* name, char* mesage, int len, int trys, char* valueError );

/**
 * @fn int inp_getMail(char*, char*, int, int)
 * @brief Asks the user through mesage to enter a mail, will reject any character not expected in a mail
 *
 * @param mail Memory allocation to save the input mail
 * @param mesage Mesage asking for input
 * @param len mail length
 * @param trys numbers of trys before an error exit
 * @param valueError Error mesage, that is shown when user enters values that are among the options shown
 * @return 0 if all OK
 * @return -1 if given NULL parameters or trys < 1
 * @return -2 if user does not enter an E-MAIL address in the given trys
 */
int inp_getMail( char* mail, char* mesage, int len, int trys, char* valueError );

int inp_getDate( sDate* date, char* mesage, int trys, int lastYear, char* valueError, char* errorNotADate);
