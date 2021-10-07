/*
    Crear una aplicación que solicite la carga de un determinado valor (dígito a dígito)
    y determine si el mismo es capicúa). La cantidad máxima de dígitos es 10.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pCargaValor(int tam,int valor[])
{
      int i;

     for(i=1;i<=tam;i++)
    {
         printf("\nIngrese valor: ");
         scanf("%d",&valor[i]);
    }
}

void pRellenoDeVector(int tam,int valorCapicua[],int valor[])
{
     int i,indiceCapicua=tam;
     for(i=1;i<=tam;i++)
    {
        valorCapicua[indiceCapicua]=valor[i];
        indiceCapicua--;
    }
}

int fAveriguarCapicua(int tam,int valorCapicua[],int valor[])
{
    int i,laVerdad=0;

    for(i=1;i<=tam;i++)
    {
       if (valorCapicua[i]!=valor[i])
       {
          laVerdad=1;
       }
    }
    return laVerdad;
}


int main()
{
    int tam =3;
    int valor[tam],valorCapicua[tam];

    pCargaValor(tam,valor);
    pRellenoDeVector(tam,valorCapicua,valor);
    if(fAveriguarCapicua(tam,valorCapicua,valor)==1)
    {
        printf("\n No es capicua!");
    }else{
        printf("\n Es capicua!");
    }
    return 0;
}
