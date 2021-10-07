/*  Crea un array de n�meros y otro de String de 10 posiciones donde
    insertaremos notas entre 0 y 10 (debemos controlar que no se inserte
    una invalida), pudiendo ser decimal la nota en el array de n�meros.
    En el vector de Strings se insertar� en cada posici�n el resultado de la
    aprobaci�n de cada nota insertada en el otro vector (mayor o igual a
    cuatro ser� aprobado). Generar luego un listado con la posici�n, la nota
    y el resultado de aprobaci�n. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pVericacion(float aNotas[],int i)
{
    while(aNotas[i]<0 || aNotas[i]>10)
    {
        printf("\nReingrese nota: ");
        scanf("%f",&aNotas[i]);
    }
}

void pCargaNotasChar(float aNotas[],char aNotasChar[][12],int vTam)
{
    int i;
    for(i=0;i<vTam;i++)
    {
        if(aNotas[i]>4)
        {
            strcpy(aNotasChar[i],"Aprobado");

        }else
        {
            strcpy(aNotasChar[i],"Desaprobado");
        }
    }
}

void pMostrarNotas(float aNotas[],char aNotasChar[][12],int vTam)
{
    int i;

     for(i=0;i<vTam;i++)
    {
        printf("\n %d-Nota %-3.f  %s ",i+1,aNotas[i],aNotasChar[i]);
    }
}

void pPedirNotas(float aNotas[],char aNotasChar[][12],int vTam)
{
    int i;
    for(i=0;i<vTam;i++)
    {
        printf("\n Ingrese Nota:");
        scanf("%f",&aNotas[i]);
        fVericacion(aNotas,i);
    }
}

int main()
{
    int vTam=10;
    float aNotas[vTam];
    char aNotasChar[vTam][12];

    pPedirNotas(aNotas,aNotasChar,vTam);
    pCargaNotasChar(aNotas,aNotasChar,vTam);
    pMostrarNotas(aNotas,aNotasChar,vTam);
    return 0;
}
