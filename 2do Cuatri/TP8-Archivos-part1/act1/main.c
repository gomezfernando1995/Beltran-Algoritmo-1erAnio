#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/******************************************************************************************
1. Crear un programa que maneje un archivo donde se almacena la siguiente información
de veinte personas: Nombre, Apellido, Edad y Estatura. El programa deberá almacenar la
 información una vez que finalice dicha carga. El formato a ser almacenado, será cada
 información separada por el carácter punto y coma (;). Intente abrir el resultado con un
 programa de edición de planilla de cálculo (tipo Excel).
    Tenga en cuenta que cada vez que se ejecuta el programa, se debe incrementar el contenido
del archivo (agregar al final).
******************************************************************************************/
typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    int estatura;
} sPersona;

/******************************   Procedimientos    *********************************/
void pCargaDatos(sPersona persona [],int i);
/*********************************  Funciones *************************************/
int f_AskForChar(char* message, char aux[]);
int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max);
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max);
int checkIfFileExists(char * filename);
/*********************************************************************************/
//==============================================        FUNCION MAIN         =====================================================

int main()
{
    int tam=1;
    sPersona aPersonas[tam];
    FILE* txtPersonas;

     if(checkIfFileExists("personas.csv"))
     {
             printf("\n  El archivo existe,  se agregaran nuevos datos \n");
             txtPersonas= fopen("personas.csv","at");
            for(int i=0;i<tam;i++)
            {
             pCargaDatos(aPersonas,i);
             fprintf(txtPersonas,"\n%s;%s;%d;%d",aPersonas[i].nombre,aPersonas[i].apellido,aPersonas[i].edad,aPersonas[i].estatura);
            }
             printf("\nCarga exitosa\n");
             fclose(txtPersonas);
     }else{
             printf("\n   El archivo no existe, se creara uno nuevo\n");
             txtPersonas= fopen("personas.csv","wt");
            for(int i=0;i<tam;i++)
            {
             pCargaDatos(aPersonas,i);
             fprintf(txtPersonas,"\n%s;%s;%d;%d",aPersonas[i].nombre,aPersonas[i].apellido,aPersonas[i].edad,aPersonas[i].estatura);
            }
             printf("\nCarga exitosa\n");
             fclose(txtPersonas);
     }
    return 0;
}
//===================================================================================================================

//==============================================         PROCEDIMIENTO         ===================================================

void pCargaDatos(sPersona persona [],int i)
{
          f_AskForChar("\n Nombre: ",persona[i].nombre);
          f_AskForChar(" Apellido: ",persona[i].apellido);
          f_AskForInt(" Edad: "," Error, reingrese edad: ",&persona[i].edad,1,110);
          f_AskForInt(" Estatura: "," Error, reingrese estatura: ",&persona[i].estatura,30,300);
}
//==============================================         FUNCIONES               =====================================================
int checkIfFileExists(char * filename)
{
    FILE *file;
    if ((file = fopen(filename, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
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
