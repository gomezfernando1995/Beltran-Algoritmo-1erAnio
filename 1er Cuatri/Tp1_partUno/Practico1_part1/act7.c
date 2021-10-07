#include <stdio.h>
#include <stdlib.h>

/*
  7. Desarrollar un programa que permita lea 2 números enteros positivos
  y que determine y visualice por pantalla si los números fueron capturados en orden creciente o no.
*/
int main()
{
    int  primerNumero,segundoNumero,i;

    printf("\n Ingrese primer numero: ");
    scanf("%d",&primerNumero);
    while(primerNumero<1)
    {
     printf("\n Reingrese numero,tiene que ser positivo: ");
      scanf("%d",&primerNumero);
    }
    printf("\n Ingrese segundo numero: ");
    scanf("%d",&segundoNumero);
    while(segundoNumero<1)
    {
     printf("\n Reingrese numero,tiene que ser positivo: ");
      scanf("%d",&segundoNumero);
    }

    if(primerNumero<segundoNumero )
    {
        printf("\n El orden es creciente\n");
    }else if(primerNumero==segundoNumero)
    {
        printf("\n Los numeros son iguales\n");
    }else
    {
        printf("\n El orden es decreciente\n");
    }

    return 0;
}
