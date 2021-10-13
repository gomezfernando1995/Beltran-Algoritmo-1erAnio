#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_AUTO 2
/***************************************************************************************************************************************************************
						------>	GOMEZ FERNANDO GABRIEL- DNI: 39387109<--------

1.	 Utilizando estructuras, crear un programa que permita almacenar la siguiente información de dueños de automóviles Automóviles
                                        Nombre	DNI	Patente	Año	Marca	Modelo	Kilometraje
                                        Oliver	35757100	AAA000	2007	Honda	Fit	56000
    a.	Realice la carga de la información de diez propietarios por parte del usuario. Tenga en cuenta que cada propietario puede tener
    asignado un automóvil como mínimo y cuatro como máximo.
    b.	Crear un procedimiento que visualice en pantalla los automóviles que pertenezcan a un determinado año. El mismo será recibido
    como parámetro del procedimiento y deberá ser consultado al usuario luego de la carga para informar los resultados.
    c.	Crear una función que al recibir el DNI de un propietario, retorne la cantidad de automóviles que tiene asociados.
    d.	Informe en pantalla un listado de todos los propietarios que tengan más de un automóvil asociado.
******************************************************************************************************************************************************************************/

typedef struct
{
    char patente[7];
    int anio;
    char marca[30];
    char modelo[30];
    float kilometraje;
    int isEmpty;
} sAutomovil;

typedef struct
{
    char nombre[50];
    float dni;
    sAutomovil aAutos[TAM_AUTO];
} sPersona;

///--------------------------------------------------------          Procedimientos           -----------------------------------------------------------------------
void p_Carga(sPersona aPersonas[],int tamPers,int tamAuto);
void p_MostrarAutoSegunAnio(sPersona aPersonas[],int tamPers,int tamAuto);
void p_listadoConMasAutos(sPersona aPersonas[],int tamPers,int tamAuto);
void p_Submenu(sPersona aPersonas[],int tamPers,int tamAuto);
///--------------------------------------------------------             Funciones           -----------------------------------------------------------------------
int f_AskForChar(char* message, char aux[]);
int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max);
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max);
int f_IsEmpty(sPersona array[],int tam,int tamAuto);
int f_AutoisEmpty(sPersona array[],int tam,int tamAuto);
int f_CantidadVehiculosPorDni(sPersona aPersonas[],int tamPers,int tamAuto);
//===============================                   FUNCION MAIN               ========================================================================

int main()
{
    int tamPers=10,tamAuto=TAM_AUTO;
    sPersona aPersonas[tamPers];

    f_IsEmpty(aPersonas,tamPers,tamAuto);
    p_Carga(aPersonas,tamPers,tamAuto);
    p_Submenu(aPersonas,tamPers,tamAuto);
    return 0;
}

//================================     PROCEDIMIENTO ALTA   DE VEHICULOS        ===============================================================

void p_Carga( sPersona aPersonas[],int tamPers,int tamAuto)
{
    int i, j,contadorAutos;
    char agregarVehiculo[5];

    for(i=0; i<tamPers; i++)
    {
        contadorAutos=0;
        system("cls");
        printf("\n            SISTEMA DE CONTROL VEHICULAR\n\n====================  Persona N%d  ====================\n",i+1);
        f_AskForChar(" Nombre: ",aPersonas[i].nombre);
        f_AskForFloat(" Dni: "," Reingrese dni: ",&aPersonas[i].dni,100000,100000000);
        do
        {
            if(contadorAutos==1)
            {
                f_AskForChar(" \n Desea agregar un vehiculo S/N: ",agregarVehiculo);
            }
            if((strcmp(agregarVehiculo,"S")==0 && j!=-1 && contadorAutos<tamAuto) || contadorAutos==0)
            {
                j=f_AutoisEmpty(aPersonas,tamPers,tamAuto);
                printf("\n      ------------- Vechiculo  -------------");
                f_AskForChar("\n   Marca: ",aPersonas[i].aAutos[j].marca);
                f_AskForChar("   Modelo: ",aPersonas[i].aAutos[j].modelo);
                f_AskForChar("   Patente: ",aPersonas[i].aAutos[j].patente);
                f_AskForInt("   Anio: "," Error,reingrese anio:  ",&aPersonas[i].aAutos[j].anio,1900,2022);
                f_AskForFloat("   Kilometraje: "," Error, reingrese kilometraje: ",&aPersonas[i].aAutos[j].kilometraje,0,9999999);
                aPersonas[i].aAutos[j].isEmpty=0;
                contadorAutos++;
                printf("\n      -----------[ Carga Existosa ]-----------\n");
            }
            else if(contadorAutos==tamAuto && strcmp(agregarVehiculo,"S")==0 )
            {
                printf("\n     Esta persona no puede ingresar mas de %d vehiculos\n       Pase el siguente  ..\n",tamAuto);
                contadorAutos=0;
                break;
            }
        }
        while(strcmp(agregarVehiculo,"N") || contadorAutos ==0);
    }
}
//========================================                    SUBMENU        ===============================================================

void  p_Submenu(sPersona aPersonas[],int tamPers,int tamAuto)
{
    int opcion;
        system("cls");
   do{
        f_AskForInt(" \n\n  1-Ver por Año\n  2-Ver por Dni\n  3-Listado personas con mas vehiculos\n  4-Salir\n\n    Ingrese opcion: "," Error, reingrese opcion",&opcion,1,4);
        switch(opcion)
        {
            case 1:
                    p_MostrarAutoSegunAnio(aPersonas,tamPers,tamAuto);
            break;
             case 2:
                 printf(" \n--------------------------------------\n El dni tiene asociado tiene %d vehiculos\n--------------------------------------\n ",f_CantidadVehiculosPorDni(aPersonas,tamPers,tamAuto));
            break;
            case 3:
                p_listadoConMasAutos(aPersonas,tamPers,tamAuto);
            break;
        }
   }while(opcion!=4);
}

//================================     PROCEDIMIENTO  MOSTRAR VEHICULOS SEGUN AÑO        ===============================================================

void p_MostrarAutoSegunAnio(sPersona aPersonas[],int tamPers,int tamAuto)
{
    int opcionAnio,i,j;
    system("cls");
    f_AskForInt("\n   Ingrese el Anio para ver los autos: "," Error,reingrese el dato:  ",&opcionAnio,1900,2022);
    printf("\n----------------------------------------------------------------------------------------");
    for(i=0; i<tamPers; i++)
    {
        for(j=0; j<tamAuto; j++)
        {
            if(opcionAnio==aPersonas[i].aAutos[j].anio)
            {
                printf("\n Duenio: %-7s Marca:%-7s Modelo:%-7s Anio:%d ",aPersonas[i].nombre,aPersonas[i].aAutos[j].marca,aPersonas[i].aAutos[j].modelo,aPersonas[i].aAutos[j].anio);
            }
        }
    }
        printf("\n----------------------------------------------------------------------------------------\n");
}
//================================     FUNCION  CANTIDAD DE  VEHICULOS  POR DNI       ===============================================================

int f_CantidadVehiculosPorDni(sPersona aPersonas[],int tamPers,int tamAuto)
{
    int i,j,totalAutos=0;
    float dni;
    system("cls");
    f_AskForFloat("\n Dni: "," Reingrese dni: ",&dni,100000,100000000);
    for(i=0; i<tamPers; i++)
    {
        if(dni == aPersonas[i].dni)
        {
            for(j=0; j<tamAuto; j++)
            {
                if(aPersonas[i].aAutos[j].isEmpty==0)
                {
                    totalAutos++;
                }
            }
        }
    }
    return totalAutos;
}

//================================     FUNCION  PERSONAS CON MAS DE UN AUTO       ===============================================================

void p_listadoConMasAutos(sPersona aPersonas[],int tamPers,int tamAuto)
{
    int i,j,totalAutos=0;
    for(i=0; i<tamPers; i++)
    {
            for(j=0; j<tamAuto; j++)
            {
                if(aPersonas[i].aAutos[j].isEmpty==0)
                {
                    totalAutos++;
                }
                if(totalAutos>1)
                {
                    printf("\n          %s",aPersonas[i].nombre);
                }
            }
            totalAutos=0;
    }
}

//==============================================                      FUNCIONES               ===============================================================

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

int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
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

int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
    {
        printf("%s",message);
        scanf("%d",aux);
        while( *aux<min || *aux>max)
        {
            printf("\n %s",mensageError);
            scanf("%d",aux);
        }
        retorno=1;
    }
    return retorno;
}

int  f_IsEmpty(sPersona array[],int tam,int tamAuto)
{
    int result = -1;
    int i,j;

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tamAuto; j++)
        {
            array[i].aAutos[j].isEmpty =1;
            result=0;
        }
    }
    return result;
}

int  f_AutoisEmpty(sPersona array[],int tam,int tamAuto)
{
    int i,j,retorno=-1;

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tamAuto; j++)
        {
            if (array[i].aAutos[j].isEmpty==1)
            {
                retorno=j;
                return j;
            }
        }
    }
    return retorno;
}

