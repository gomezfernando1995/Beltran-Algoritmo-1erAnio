
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*  3.	Hacer un programa que registre 10 alumnos y guarde: nombre, nombre de la asignatura y 4 notas. Calcular y mostrar el promedio y la suma de las notas.*/

typedef struct
{
    char asignatura[50];
    int nota;
}sMateria;

typedef struct
{
    char nombre[50];
    sMateria aMaterias[4];
}sAlumno;

///--------------------------------------------------------             Funciones  Secundarias         -------------------------------------------------------
int askForChar(char* message, int tam,char aux[],int posicion);
void requestData(sAlumno cargaAlumnos[],int tam);
void showData(sAlumno cargaAlumnos[],int tam);
int askForInt(char* message, int tam,int* aux,int j);

//===============================                   FUNCION MAIN               ===============================

int main()
{
    int tam=10;
     sAlumno cargaAlumnos[tam];

     requestData(cargaAlumnos,tam);
     showData(cargaAlumnos,tam);
}
//================================  PEDIR DATOS ============================================

void requestData(sAlumno cargaAlumnos[],int tam)
{
    int i,j;
    sAlumno aux;

     for (i=0; i < tam; i++)
    {
        askForChar(" Nombre de alumno:",tam,aux.nombre,i);
        cargaAlumnos[i]= aux;
        for (j=0; j < 4; j++)
        {
             askForChar("Ingrese la materia: ",tam,  aux.aMaterias->asignatura,j);
             askForInt("Ingrese nota: ",tam,  &aux.aMaterias->nota ,j);

             strcpy(cargaAlumnos[i].aMaterias[j].asignatura, aux.aMaterias->asignatura);
             cargaAlumnos[i].aMaterias[j].nota=aux.aMaterias->nota;
        printf("============================ \n");
        }
    }
}
//=================================  MOSTRAR DATOS ==========================================

void showData(sAlumno cargaAlumnos[],int tam)
{
     int i, j;
     float total;

    system("cls");
    for (i=0; i < tam; i++)
    {
        printf("\n=================================== \n\n");
        printf("   Nombre: %s \n", cargaAlumnos[i].nombre);
        total = 0;
        for (j=0; j < 4; j++)
        {
            printf("\n Materia: %-15s  Nota: %d ",cargaAlumnos[i].aMaterias[j].asignatura,cargaAlumnos[i].aMaterias[j].nota);
            total = total + cargaAlumnos[i].aMaterias[j].nota;
        }
        printf(" \n Total: %.f ", total);
        printf(" \n Promedio: %.1f \n", (total/4));
        printf("=================================== \n");
    }
}
//=========================================================================================

int askForChar(char* message, int tam,char aux[],int j)
{
    int retorno =0;
    if(message!=NULL && tam>0)
    {
        printf("\n%d-%s",j+1,message);
        fflush(stdin);
        scanf("%[^\n]s",aux);

        for (int i=0; aux[i]!= '\0'; i++){
            aux[i] = tolower(aux[i]);
         }
            aux[0] = toupper(aux[0]);
        retorno=1;
    }
    return retorno;
}

int askForInt(char* message, int tam,int* aux,int j)
{
    int retorno =0;

    if(message!=NULL && tam>0)
    {
        printf("\n%d-%s",j+1,message);
        scanf("%d",aux);
        retorno=1;
    }
    return retorno;
}
