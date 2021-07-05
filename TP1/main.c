#include <stdio_ext.h>
#include <stdlib.h>

//Personal includes
#include "../Heathers/calculate.h"
#include "../Heathers/input_lib.h"
#include "../Heathers/aux_main.h"
#include "../Heathers/errors.h"
#include "../Heathers/my_system.h"
#include "../Heathers/steart.h"

//Output for Input
#define INPUT_OPT_NUMBER "\nIngrese el numero de la accion que desea realizar: "
#define INPUT_NUMBER_A "\nIngrese el numero A: "
#define INPUT_NUMBER_B "\nIngrese el numero B: "

//Exit Farewell
#define GOODBYE "\nHasta luego! :D"

//Lengths
#define MAIN_OPTIONS_LEN 5

//Number of trys
#define MAX_TRYS 3
//After this number of trys the user will be considered not apt and program will shut downS


int main( void )
{
	//Operands declaration
	int numberA;
	int numberB;
	long long int sum;
	long long int substraction;
	long long int product;
	float division;
	unsigned char factorialA[MAX_FACTORIAL_LENGTH];
	unsigned char factorialB[MAX_FACTORIAL_LENGTH];

	//Flags declaration
	int numberAReady = 0;
	int numberBReady = 0;
	int operationsReady = 0;

	//Aux declaration
	int options[MAIN_OPTIONS_LEN] = {1,2,3,4,5};
	int option = 0;
	int errorExit = 0;
	int errorAux;
	int sizeFacA;
	int sizeFacB;

	// Program start
	do
	{
		//Prints the main menu
		main_showMenu( numberA, numberB, numberAReady, numberBReady );
		//Asks the user for menu accion he needs to realize
		errorExit = inp_getIntConcrete( &option, INPUT_OPT_NUMBER, MAX_TRYS,
										MAIN_OPTIONS_LEN, options );

		//If the user is considered capable then the program runs
		if( errorExit == 0 )
		{
			switch( option )
			{
				case 1:
					//Asks user for a number for number A
					errorExit = inp_getInt( &numberA, INPUT_NUMBER_A, MAX_TRYS );
					if ( errorExit == 0 )
					{
						//Declares number A is ready to use
						numberAReady = 1;
						//Shuts down access to main>option4
						operationsReady = 0;
					}
					break;
				case 2:
					//Asks user for a number for number B
					errorExit = inp_getInt( &numberB, INPUT_NUMBER_B, MAX_TRYS );
					if ( errorExit == 0 )
					{
						//Declares number B is ready to use
						numberBReady = 1;
						//Shuts down access to main>option4
						operationsReady = 0;
					}
					break;
				case 3:
					//Can not access until number A and number B are loaded
					if( numberAReady && numberBReady )
					{
						//Runs operations based on number A and number B values
						errorAux = main_runOperations( numberA, numberB, &sum,
														&substraction, &product,
														&division, factorialA,
														factorialB, &sizeFacA,
														&sizeFacB);
						//Allows access to main>option4
						operationsReady = 1;
					}
					else
					{
						//If access not allowed shows error
						printf( EMPTY_VALUES_ERROR );
						//Waits for enter
						sys_pause();
					}
					break;
				case 4:
					//Can not access until operations are run
					if( operationsReady )
					{
						//Clears the screen
						system("clear");
						//Shows the results of the operations run
						main_showResults(numberA, numberB, sum, substraction,
										product, division, factorialA, factorialB
										, errorAux, sizeFacA, sizeFacB);
						//Waits for enter
						sys_pause();
					}
					else
					{
						//If access not allowed shows error
						printf( EMPTY_VALUES_ERROR );
						//Waits for enter
						sys_pause();
					}
					break;
				case 5:
					//Exit mesage
					printf( GOODBYE );
					//Waits for enter
					sys_pause();
					break;
			}
		}
	}while( option != 5 && errorExit == 0 );

	//In case of emergency exit
	if( errorExit == -1 )
	{
		//Exit error: User incapable
		printf( EXIT_ERROR );
		//Waits for enter
		sys_pause();
	}
	return 0;
}
