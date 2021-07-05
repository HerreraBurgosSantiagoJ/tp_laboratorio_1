/*
 * errors.h
 *
 *  Created on: 24 mar. 2021
 *      Author: plainsight
 */

#ifndef HEATHERS_ERRORS_H_
#define HEATHERS_ERRORS_H_



#endif /* HEATHERS_ERRORS_H_ */

//Usual errors
#define EMPTY_VALUES_ERROR "\nError, la accion no puede completarse sin el ingreso de los datos correspondientes\nIntente otra opción"

//Exit Error
#define EXIT_ERROR "\nDebido a la incapacidad del usuario para usar el programa, determinada\npor los constantes errores en el ingreso de datos, el programa se cerrará."

/**
 * @fn int error_id(int, int, int)
 * @brief Id's the calculation errors
 *
 * @param divError 1 if there's a division Error, 0 if not
 * @param facAError 1 if there's a factorial Error for A, 0 if not
 * @param facBError 1 if there's a factorial Error for B, 0 if not
 * @return the calculation error id if it exists
 */
int error_id( int divError,	int facAError, int facBError );

