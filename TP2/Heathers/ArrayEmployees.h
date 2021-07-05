#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define NAME_LENGTH 51

typedef struct{

 int id;
 char name[NAME_LENGTH];
 char lastName[NAME_LENGTH];
 float salary;
 int sector;
 int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

//Agrupa funciones que permiten trabajar con los datos almacenados en la estructura Employee,
//la cual representa los datos de un empleado de la empresa.


/** \brief To indicate that all position in the array are empty,
 * this function set the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(Employee* list, int len, int order);



/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int printEmployees(Employee* list, int length);



/** \brief Copies the string from on the string to
 *
 * \param to Char array where the data will be copied
 * \param from Char array containing the data to be copied
 *
 */

void strpas(char to[],char from[]);



/** \brief Generates an ID adding one to the last ID created
 *
 * \param list Struct array to check the last ID created
 * \param len Length of list
 * \return New ID
 *
 */

int generateID(Employee* list, int len);



/** \brief Calculates the average salary of all employees in list
 *
 * \param list Struct array to check all of the employees salary's
 * \param len Length of list
 * \return Average of salaries
 *
 */

float averageSalary(Employee* list, int len);



/** \brief Logicaly checks if the emp list has free space
 *
 * \param list To be checked
 * \param len Length of list
 * \return index (1) if yes, (0) otherwise
 *
 */

char empHasSpace(Employee* list, int len);

/** \brief Finds index of given ID
 *
 * \param list To be checked
 * \param len Length of list
 * \return index if ID exists, (-1) if user cancels search or search doesn't hit on given trys
 *
 */
int getidindex(Employee* list, int len);

/**
 * @fn int emp_therAreEmployees(Employee*, int)
 * @brief
 *
 * @param list
 * @param length
 * @return
 */
int emp_therAreEmployees( Employee* list, int length );

/**
 * @fn int emp_findEmpty(Employee*, int)
 * @brief
 *
 * @param list
 * @param length
 * @return
 */
int emp_findEmpty( Employee* list, int length );

int emp_findGreaterID( Employee* list, int length );

int emp_findMinorID( Employee* list, int length );
