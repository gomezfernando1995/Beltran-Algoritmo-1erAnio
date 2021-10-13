#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**********************************************************************************************************************************************************
2.	  Utilizando estructuras, crear un programa que permita almacenar la siguiente información de pacientes
                                                                               Diagnóstico		                                                                                     Fechas de control
        Nombre	          DNI	                Preventivo	                        Real	                        Localidad	                           Última cita	      Próxima cita
            Oliver	    35757100        	Esguince de tobillo    	Fractura de tobillo	        Quilmes	                             13/10/2021	     11/11/2021

    a.	Realice la carga de la información de veinte pacientes por parte del usuario
    b.	Crear un procedimiento que visualice en pantalla los pacientes que pertenezcan a una determinada localidad. La misma será
        recibida como parámetro del procedimiento y deberá ser consultada al usuario luego de la carga para informar los resultados.
    c.	Crear una función que al recibir el DNI de un paciente, retorne su nombre.
    d.	Informe en pantalla un listado de todos los casos en los que difiera el diagnóstico preventivo del real.
**********************************************************************************************************************************************************/
typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    char preventivo[50];
    char real[50];
} sDiagnostico;

typedef struct
{
    sFecha ultimaCita;
    sFecha proximaCita;
} sFechaControl;

typedef struct
{
    char nombre[50];
    float dni;
    sDiagnostico diagnosticos;
    char localidad[100];
    sFechaControl fechasControl;
} sPaciente;

/*==================================================             Funciones                 ================================================**/
int f_AskForChar(char* message, char aux[]);
int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max);
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max);
char* retornoNombre(sPaciente arrayPacientes[],int tam, float dni);

/*================================================           Procedimientos              ===============================================**/
void pCargaDeDatos(sPaciente arrayPacientes[],int tam);
 void pMostrarPorLocalidad(sPaciente arrayPacientes[],int tam,char buscarLocalidad[]);
 void pMostrarCasosDiferidos(sPaciente arrayPacientes[],int tam);


//=========================================                   FUNCION MAIN               ===================================================

int main()
{
    int tam=20;
    float auxDni;
    char buscarLocalidad[100];
    sPaciente arrayPacientes[tam];

    pCargaDeDatos(arrayPacientes,tam);
    system("cls");
    f_AskForChar("   Busqueda Por Localidad\n    -Ingrese localidad: ",buscarLocalidad);
    pMostrarPorLocalidad(arrayPacientes,tam,buscarLocalidad);
    f_AskForFloat(" Busqueda de Nombre por Dni\n  -Ingrese Dni: ","  Error, reingrese dni",&auxDni,100000,100000000);
    printf("\n -------------------------------\n           %s \n -------------------------------\n ",retornoNombre(arrayPacientes,tam,auxDni));
    pMostrarCasosDiferidos(arrayPacientes,tam);
    return 0;
}
//==========================================              Carga de informacion           ==================================================

void pCargaDeDatos(sPaciente arrayPacientes[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("\n ================ Paciente %d ================ ",i+1);
        f_AskForChar("\n -Nombre: ",arrayPacientes[i].nombre);
        f_AskForFloat(" -Dni: "," Reingrese dni: ",&arrayPacientes[i].dni,100000,100000000);
        f_AskForChar("\n ====== Diagnostico ======\n -Preventivo: ",arrayPacientes[i].diagnosticos.preventivo);
        f_AskForChar(" -Real: ",arrayPacientes[i].diagnosticos.real);
        f_AskForChar(" -------------------------\n -Localidad: ",arrayPacientes[i].localidad);
        f_AskForInt(" -------------------------\n ====== Ultima cita ======\n -Dia: ","  Error,reingrese dia: ",&arrayPacientes[i].fechasControl.ultimaCita.dia,1,31);
        f_AskForInt(" -Mes: ","  Error,reingrese mes: ",&arrayPacientes[i].fechasControl.ultimaCita.mes,1,12);
        f_AskForInt(" -Anio: ","  Error,reingrese anio: ",&arrayPacientes[i].fechasControl.ultimaCita.anio,2000,2021);
        f_AskForInt(" ====== Proxima cita ======\n -Dia: ","  Error,reingrese dia: ",&arrayPacientes[i].fechasControl.proximaCita.dia,1,31);
        f_AskForInt(" -Mes: ","  Error,reingrese mes: ",&arrayPacientes[i].fechasControl.proximaCita.mes,1,12);
        f_AskForInt(" -Anio: ","  Error,reingrese anio: ",&arrayPacientes[i].fechasControl.proximaCita.anio,2000,2023);
        printf("\n --------------  Carga Exitosa -------------- \n");
    }
}
//==========================================         Procedimiento Mostrar Por Localidad          ==================================================

 void pMostrarPorLocalidad(sPaciente arrayPacientes[],int tam,char buscarLocalidad[])
 {
     int i;
     printf("\n ======================================================================================================= ");
     for(i=0; i<tam; i++)
    {
        if(strcmp(buscarLocalidad,arrayPacientes[i].localidad))
        {
          printf("\n|   Paciente N%-3d Nombre:%-13s Dni:%-10.f Localidad:%-12s Diagnostico Real:%-6s   | ",i+1,arrayPacientes[i].nombre,arrayPacientes[i].dni,arrayPacientes[i].localidad,arrayPacientes[i].diagnosticos.real);
        }
    }
        printf("\n ======================================================================================================= \n");
 }
//==========================================              Funcion  Dni Que retorna nombre         ==================================================

char* retornoNombre(sPaciente arrayPacientes[],int tam, float dni)
{
    int i;
    for(i=0; i<tam; i++)
    {
            if(dni==arrayPacientes[i].dni)
            {
                return arrayPacientes[i].nombre;
            }
    }
    return "\n El Dni ingresado no existe \n";
}
//==========================================              Procedimiento Informe  Casos Diferidos         ===============================================

 void pMostrarCasosDiferidos(sPaciente arrayPacientes[],int tam)
 {
     int i, contador=0;
     printf("\n ======================================================================================================= ");
     for(i=0; i<tam; i++)
    {
        if(strcmp(arrayPacientes[i].diagnosticos.preventivo,arrayPacientes[i].diagnosticos.real))
        {
          printf("\n|   Paciente N%-3d Nombre:%-13s  Diagnostico Preventivo:%-10s Diagnostico Real:%-10s   | ",i+1,arrayPacientes[i].nombre,arrayPacientes[i].diagnosticos.preventivo,arrayPacientes[i].diagnosticos.real);
          contador=1;
        }
    }
        if(contador==0){ printf("\n                            NO HAY CASOS DIFERIDOS EN DIAGNOSTICOS                              ");}
        printf("\n ======================================================================================================= \n");
 }

//==============================================         FUNCIONES               =====================================================


/** \brief SOLICITAR/PEDIR UN DATO  CADENA DE TEXTO
 *
 * \param message ->  mensaje que se quiere mostrar por consola
 * \param aux-> puntero de la variable donde sera guardado la informacion ingresada
 * \return retorna 0 en caso  de que alguna variable sea NULL-- 1 si la carga finaliza con exito
 *
 */
int f_AskForChar(char* message, char aux[])
{
    int retorno =0;
    if(message!=NULL )
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%[^\n]s",aux);
        for (int i=0; aux[i]!= '\0'; i++)
        {
            aux[i] = tolower(aux[i]);
        }
        aux[0] = toupper(aux[0]);
        retorno=1;
    }
    return retorno;
}

/** \brief   SOLICITAR/PEDIR UN DATO TIPO FLOAT
 *
 * \param message ->  mensaje que se quiere mostrar por consola
 * \param mensageError -> mensaje de error cuando el usuario ingresa el dato mal
 * \param aux-> puntero de la variable donde sera guardado la informacion ingresada
 * \param min-> valor minimo que puede tomar la variable ingresada
 * \param max-> valor minimo que puede tomar la variable ingresada
 * \return retorna 0 en caso  de que alguna variable sea NULL-- 1 si la carga finaliza con exito
 *
 */
int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL && mensageError!=NULL && aux!=NULL)
    {
        printf("%s",message);
        scanf("%f",aux);
        while(*aux<min || *aux>max)
        {
            printf("\n %s",mensageError);
            scanf("%f",aux);
        }
        retorno=1;
    }
    return retorno;
}

/** \brief SOLICITAR/PEDIR UN DATO ENTERO
 *
 * \param message ->  mensaje que se quiere mostrar por consola
 * \param mensageError -> mensaje de error cuando el usuario ingresa el dato mal
 * \param aux-> puntero de la variable donde sera guardado la informacion ingresada
 * \param min-> valor minimo que puede tomar la variable ingresada
 * \param max-> valor minimo que puede tomar la variable ingresada
 * \return retorna 0 en caso  de que alguna variable sea NULL-- 1 si la carga finaliza con exito
 *
 */
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
    {
        printf("%s",message);
        scanf("%d",aux);
        while( *aux<min || *aux>max )
        {
            printf("\n %s",mensageError);
            scanf("%d",aux);
        }
        retorno=1;
    }
    return retorno;
}
