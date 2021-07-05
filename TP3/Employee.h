#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int employee_setId(Employee* this,int id);
int employee_getId(void* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

Employee* employee_newEmpty();
Employee* employee_new( char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr );
void employee_delete(Employee* toDelete);

int employee_show( Employee* this );

int employee_cmpId( void* empA, void* empB );
int employee_cmpNombre( void* empA, void* empB );
int employee_cmpHorasTrabajadas( void* empA, void* empB );
int employee_cmpSueldo( void* empA, void* empB );

#endif // employee_H_INCLUDED
